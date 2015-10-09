<?php
/**
 * @copyright 2015 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
namespace Application\Models;
use Blossom\Classes\ActiveRecord;
use Blossom\Classes\Database;

class Map extends ActiveRecord
{
    protected $tablename = 'maps';

	/**
	 * Populates the object with data
	 *
	 * Passing in an associative array of data will populate this object without
	 * hitting the database.
	 *
	 * Passing in a scalar will load the data from the database.
	 * This will load all fields in the table as properties of this class.
	 * You may want to replace this with, or add your own extra, custom loading
	 *
	 * @param int|string|array $id (ID, email, username)
	 */
	public function __construct($id=null)
	{
		if ($id) {
			if (is_array($id)) {
				$this->exchangeArray($id);
			}
			else {
				$zend_db = Database::getConnection();
				$sql = ActiveRecord::isId($id)
					? 'select * from maps where id=?'
					: 'select * from maps where name=?';

				$result = $zend_db->createStatement($sql)->execute([$id]);
				if (count($result)) {
					$this->exchangeArray($result->current());
				}
				else {
					throw new \Exception('maps/unknown');
				}
			}
		}
		else {
			// This is where the code goes to generate a new, empty instance.
			// Set any default values for properties that need it here
		}
	}

	public function validate()
	{
        if (!$this->getName()) { throw new \Exception('missingRequiredFields'); }
	}

	public function save() { parent::save(); }
	public function delete()
	{
        $this->deleteFile();
        parent::delete();
	}

	//----------------------------------------------------------------
	// Generic Getters & Setters
	//----------------------------------------------------------------
	public function getId  () { return parent::get('id'  ); }
	public function getName() { return parent::get('name'); }

	public function setName($s) { parent::set('name', $s); }

	public function handleUpdate(array $post, array $files)
	{
        $this->setName($post['name']);
        $this->saveFile($files);
	}

	//----------------------------------------------------------------
	// Custom Functions
	//----------------------------------------------------------------
	public function saveFile($files)
	{
        if (isset($files['script']) && is_uploaded_file($files['script']['tmp_name'])) {
            $newFile = SITE_HOME."/maps/{$this->getInternalFilename()}.js";

            rename($files['script']['tmp_name'], $newFile);
            chmod($newFile, 0666);
            // Check and make sure the file was saved
            if (!is_file($newFile)) {
                throw new \Exception('media/badServerPermissions');
            }
        }
	}

	public function deleteFile()
	{
        $script = SITE_HOME."/maps/{$this->getInternalFilename()}.js";
        if (is_file($script)) { unlink($script); }
	}

	/**
	 * Returns the file name used on the server
	 *
	 * We do not use the filename the user chose when saving the files.
	 * We generate a unique filename the first time the filename is needed.
	 * This filename will be saved in the database whenever this media is
	 * finally saved.
	 *
	 * @return string
	 */
	public function getInternalFilename()
	{
		$filename = parent::get('internalFilename');
		if (!$filename) {
			$filename = uniqid();
			parent::set('internalFilename', $filename);
		}
		return $filename;
	}
}
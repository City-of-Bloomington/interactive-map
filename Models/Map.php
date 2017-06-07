<?php
/**
 * @copyright 2015-2017 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
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
				$this->data = $id;
			}
			else {
				$sql = ActiveRecord::isId($id)
					? 'select * from maps where id=?'
					: 'select * from maps where alias=?';

				$result = parent::doQuery($sql, [$id]);
				if (count($result)) {
					$this->data = $result[0];
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
        if (!$this->getAlias()) { $this->setAlias($this->getName()); }
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
	public function getId                () { return parent::get('id'                ); }
	public function getName              () { return parent::get('name'              ); }
	public function getAlias             () { return parent::get('alias'             ); }
	public function getDescription       () { return parent::get('description'       ); }
	public function getNavigationMarkdown() { return parent::get('navigationMarkdown'); }
	public function getRelatedMarkdown   () { return parent::get('relatedMarkdown'   ); }

	public function setName              ($s) { parent::set('name',               $s); }
	public function setAlias             ($s) { parent::set('alias', preg_replace('/[^a-z\-]/', '', strtolower($s))); }
	public function setDescription       ($s) { parent::set('description',        $s); }
	public function setNavigationMarkdown($s) { parent::set('navigationMarkdown', $s); }
	public function setRelatedMarkdown   ($s) { parent::set('relatedMarkdown',    $s); }

	public function handleUpdate(array $post, array $files)
	{
        $fields = ['name', 'alias', 'description', 'navigationMarkdown', 'relatedMarkdown'];
        foreach ($fields as $f) {
            $set = 'set'.ucfirst($f);
            $this->$set($post[$f]);
        }
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

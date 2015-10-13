<?php
/**
 * @copyright 2015 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
namespace Application\Models;

use Blossom\Classes\Url;

class MediaManager
{
    /**
     * Queries media manager for a single item's info
     *
     * The response is cached in memory, so subsequent calls
     * to this function do not send out another HTTP request.
     *
     * @param int|hex $id
     * @return stdClass JSON response from media manager
     */
    public static function mediaInfo($id)
    {
        static $response = [];

        if (empty($response[$id])) {
            $url = MEDIA_MANAGER."/media/view?format=json;media_id=$id";
            $response[$id] = Url::get($url);
        }
        if (isset($response[$id])) {
            return json_decode($response[$id]);
        }
    }

    /**
     * Validate user entered value and return media_id
     *
     * Returns null on validation error
     *
     * Users can enter ID in various ways:
     * int:       22
     * hex:       530778b93e0bf
     * media URL: http://localhost/media-manager/media/view?media_id=3
     * image url: http://localhost/media-manager/m/2014/2/21/350/530778b93e0bf.png
     *
     * @param string $id
     * @return int
     */
    public static function getValidId($id)
    {
        $id = trim($id);

        if (   preg_match('|media_id=(\d+)|',         $id, $matches)
            || preg_match('|([0-9a-f]{13})(.\w+)?$|', $id, $matches) ) {
            $id = $matches[1];
        }

        $media = self::mediaInfo($id);
        if ($media) {
            return $media->id;
        }
    }

    /**
     * @param int $media_id
     * @param string $derivative The name of the derivative
     * @return string
     */
    public static function getMediaUrl($media_id, $derivative=null)
    {
        $info = self::mediaInfo($media_id);
        if ($info) {
            $d = date('Y/n/j', strtotime($info->uploaded));
            $url = MEDIA_MANAGER."/m/$d/";

            if ($derivative) {
                foreach ($info->derivatives as $d) {
                    if (!empty($d->{$derivative})) {
                        $url.= $d->{$derivative};
                    }
                }
            }
            $url.= '/'.$info->internalFilename;
            return $url;
        }
    }
}
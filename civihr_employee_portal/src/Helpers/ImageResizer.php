<?php

namespace Drupal\civihr_employee_portal\Helpers;

class ImageResizer {

  const RESIZE_WIDTH = 400;
  const RESIZE_HEIGHT = 400;

  /**
   * Resizes images to fix profile pictures.
   *
   * @param string $imagePath
   */
  public static function resizeForProfile($imagePath) {
    $image = image_load($imagePath);

    if (!$image) {
      return;
    }

    image_scale_and_crop($image, self::RESIZE_WIDTH, self::RESIZE_HEIGHT);
    image_save($image, $imagePath);
  }
}

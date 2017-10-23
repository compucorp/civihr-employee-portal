<?php

namespace Drupal\civihr_employee_portal\Helpers;

class ImageHelper {
  public static function resizeForProfile($imagePath) {
    $image = image_load($imagePath);

    if (!$image) {
      return;
    }

    image_scale_and_crop($image, 400, 400);
    image_save($image, $imagePath);
  }
}

<?php
if ( ! defined( 'ABSPATH' ) ) {
    exit;
}

class CSS_File {
    public static function enqueue() {
        wp_enqueue_style(
            'neptunia-generated-css',
            NEPTUNIA_CSS_URL . 'output/neptunia.css',
            [],
            null
        );
    }
}
// Kjør i front-end
add_action( 'wp_enqueue_scripts', [ 'CSS_File', 'enqueue' ] );

<?php
if ( ! defined( 'ABSPATH' ) ) {
    exit;
}

class Bricks {
    public static function init() {
        add_action( 'wp_enqueue_scripts', [ __CLASS__, 'enqueue_css' ] );
    }

    public static function enqueue_css() {
        wp_enqueue_style(
            'neptunia-bricks-css',
            NEPTUNIA_CSS_URL . 'output/neptunia.css',
            [],
            null
        );
    }
}
// Koble inn i front-end
Bricks::init();

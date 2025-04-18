<?php
if ( ! defined( 'ABSPATH' ) ) {
    exit;
}

class CSS_Engine {
    public static function init() {
        $css = ':root {';

        // Hent variabler
        $vars_file = NEPTUNIA_CSS_DIR . 'config/variables.json';
        if ( file_exists( $vars_file ) ) {
            $json = json_decode( file_get_contents( $vars_file ), true );
            foreach ( $json['variables'] as $var ) {
                $css .= sprintf( '--%s: %s;', $var['id'], $var['default'] );
            }
        }

        // Hent hjelpe‑klasser
        $classes_file = NEPTUNIA_CSS_DIR . 'config/classes.json';
        if ( file_exists( $classes_file ) ) {
            $json = json_decode( file_get_contents( $classes_file ), true );
            foreach ( $json['classes'] as $item ) {
                $css .= sprintf( '.%s { %s }', $item['class'], $item['style'] );
            }
        }

        $css .= '}';
        // Skriv ut til generert CSS‑fil
        file_put_contents( NEPTUNIA_CSS_DIR . 'output/neptunia.css', $css );
    }
}

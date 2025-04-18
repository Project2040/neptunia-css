<?php
if ( ! defined( 'ABSPATH' ) ) {
    exit;
}

class Color {
    public static function hex_to_hsl( $hex ) {
        $hex = ltrim( $hex, '#' );
        $r = hexdec( substr( $hex, 0, 2 ) ) / 255;
        $g = hexdec( substr( $hex, 2, 2 ) ) / 255;
        $b = hexdec( substr( $hex, 4, 2 ) ) / 255;
        $max = max( $r, $g, $b );
        $min = min( $r, $g, $b );
        $l   = ( $max + $min ) / 2;
        $d   = $max - $min;
        if ( $d === 0 ) {
            $h = $s = 0;
        } else {
            $s = $l > 0.5
                ? $d / ( 2 - $max - $min )
                : $d / ( $max + $min );
            switch ( $max ) {
                case $r:
                    $h = 60 * fmod( ( ( $g - $b ) / $d ), 6 );
                    break;
                case $g:
                    $h = 60 * ( ( ( $b - $r ) / $d ) + 2 );
                    break;
                default:
                    $h = 60 * ( ( ( $r - $g ) / $d ) + 4 );
                    break;
            }
        }
        return [ $h, $s * 100, $l * 100 ];
    }

    public static function lighten( $hex, $percent ) {
        list( $h, $s, $l ) = self::hex_to_hsl( $hex );
        $l = min( 100, max( 0, $l + $percent ) );
        return self::hsl_to_hex( $h, $s, $l );
    }

    private static function hsl_to_hex( $h, $s, $l ) {
        $c = ( 1 - abs( 2 * $l / 100 - 1 ) ) * ( $s / 100 );
        $x = $c * ( 1 - abs( fmod( $h / 60, 2 ) - 1 ) );
        $m = $l / 100 - $c / 2;
        if      ( $h < 60  ) { list( $r, $g, $b ) = [ $c, $x, 0 ]; }
        elseif  ( $h < 120 ) { list( $r, $g, $b ) = [ $x, $c, 0 ]; }
        elseif  ( $h < 180 ) { list( $r, $g, $b ) = [ 0, $c, $x ]; }
        elseif  ( $h < 240 ) { list( $r, $g, $b ) = [ 0, $x, $c ]; }
        elseif  ( $h < 300 ) { list( $r, $g, $b ) = [ $x, 0, $c ]; }
        else                 { list( $r, $g, $b ) = [ $c, 0, $x ]; }

        return sprintf(
            "#%02x%02x%02x",
            ( $r + $m ) * 255,
            ( $g + $m ) * 255,
            ( $b + $m ) * 255
        );
    }
}

<?php
// Avslutt om dette lastes utenfor WordPress
if ( ! defined( 'ABSPATH' ) ) {
    exit;
}

// Basestier
define( 'NEPTUNIA_CSS_DIR', plugin_dir_path( __FILE__ ) );
define( 'NEPTUNIA_CSS_URL', plugin_dir_url( __FILE__ ) );

// Last inn kjerneklasser
require_once NEPTUNIA_CSS_DIR . 'inc/CSS_Engine.php';
require_once NEPTUNIA_CSS_DIR . 'inc/CSS_File.php';
require_once NEPTUNIA_CSS_DIR . 'inc/Color.php';
require_once NEPTUNIA_CSS_DIR . 'inc/Bricks.php';

// Initialiser CSS‑generator på init-hook
add_action( 'init', [ 'CSS_Engine', 'init' ] );

// Initier Bricks-integrasjon (legger på enqueue via egen add_action inne i klassen)
Bricks::init();

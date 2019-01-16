#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#define TAPPING_TERM 200 // how long before a tap becomes a hold
#define PREVENT_STUCK_MODIFIERS // when switching layers, this will release all mods
#define PERMISSIVE_HOLD // makes tap and hold keys work better for fast typers who don't want tapping term set above 500
// #define FORCE_NKRO

#include "config_common.h"

#ifdef AUDIO_ENABLE
    /* #define STARTUP_SONG SONG(ZELDA_TREASURE) */
    // #define STARTUP_SONG SONG(PLANCK_SOUND)
    #define STARTUP_SONG SONG(NO_SOUND)

    /* #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \ */
    /*                               SONG(COLEMAK_SOUND), \ */
    /*                               SONG(DVORAK_SOUND) \ */
    /*                             } */
#endif

// #define MUSIC_MASK (keycode != KC_NO)

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

// #define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

#endif

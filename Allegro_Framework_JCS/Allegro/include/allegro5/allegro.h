/*         ______   ___    ___
 *        /\  _  \ /\_ \  /\_ \
 *        \ \ \L\ \\//\ \ \//\ \      __     __   _ __   ___
 *         \ \  __ \ \ \ \  \ \ \   /'__`\ /'_ `\/\`'__\/ __`\
 *          \ \ \/\ \ \_\ \_ \_\ \_/\  __//\ \L\ \ \ \//\ \L\ \
 *           \ \_\ \_\/\____\/\____\ \____\ \____ \ \_\\ \____/
 *            \/_/\/_/\/____/\/____/\/____/\/___L\ \/_/ \/___/
 *                                           /\____/
 *                                           \_/__/
 *
 *      Main header file for the entire Allegro library.
 *      (separate modules can be included from the allegro/ directory)
 *
 *      By Shawn Hargreaves.
 *
 *      Vincent Penquerc'h split the original allegro.h into separate headers.
 *
 *      See readme.txt for copyright information.
 */


#ifndef __al_included_allegro5_allegro_h
#define __al_included_allegro5_allegro_h


#include "base.h"

#include "altime.h"
#include "bitmap.h"
#include "bitmap_draw.h"
#include "bitmap_io.h"
#include "bitmap_lock.h"
#include "blender.h"
#include "color.h"
#include "config.h"
#include "debug.h"
#include "display.h"
#include "drawing.h"
#include "error.h"
#include "events.h"
#include "file.h"
#include "fixed.h"
#include "fmaths.h"
#include "fshook.h"
#include "fullscreen_mode.h"
#include "joystick.h"
#include "keyboard.h"
#include "memory.h"
#include "monitor.h"
#include "mouse.h"
#include "mouse_cursor.h"
#include "path.h"
#include "system.h"
#include "threads.h"
#include "timer.h"
#include "tls.h"
#include "transformations.h"
#include "utf8.h"


#ifndef ALLEGRO_NO_COMPATIBILITY
   #include "alcompat.h"
#endif


#ifdef ALLEGRO_EXTRA_HEADER
   //#include ALLEGRO_EXTRA_HEADER
#endif


#endif



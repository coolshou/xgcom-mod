/*
 * XGCom (Xiyou Linux Group)
 *
 * Copyright (c) 2008-~  Xiyou Linux Group
 *
 * This source code is released for free distribution under the
 * terms of the GNU General Public License.
 *
 * file name: cfg.h
 * modify date: 2009-7-30
 * Author: helight.xu@gmail.com
 *
 * Program definitions:
 */
#ifndef CFG_H_
#define CFG_H_

#include <gtk/gtk.h>
#include "support.h"

typedef struct {
  gboolean transparency;
  gboolean show_cursor;
  gint rows;
  gint columns;
  gint scrollback;
  gboolean visual_bell;
  GdkColor foreground_color;
  GdkColor background_color;
  gdouble background_saturation;
  gchar *font;
} display_config_t;

//#define DEFAULT_FONT "Monospace, 12"
#define DEFAULT_FONT "Droid Sans Mono"

GtkWidget* create_configuration_dialog (struct xcomdata *xcomdata);

#endif //CFG_H_

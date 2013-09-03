/*
 * XGCom (Xiyou Linux Group)
 *
 * Copyright (c) 2008-~  Xiyou Linux Group
 *
 * This source code is released for free distribution under the
 * terms of the GNU General Public License.
 *
 * file name: CfgFace.c
 * modify date: 2009-7-30
 * Author: helight.xu@gmail.com
 *
 * Program definitions:
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "support.h"
#include "Funs.h"

static GtkWidget *cfg_option_dialog;

//font dialog
void on_save_font_button_clicked (GtkButton *button, gpointer user_data);
void on_cancel_font_button_clicked (GtkButton *button, gpointer user_data);

GtkWidget* create_configuration_option_dialog (struct xcomdata *xcomdata)
{
	GdkPixbuf *cfg_dialog_icon_pixbuf;
	GtkWidget *dialog_vbox;
	GtkWidget *setuo_frame;
	GtkWidget *alignment2;
	GtkWidget *setup_tablel;
	GtkWidget *label_font;

	GtkWidget *setup_label;
	GtkWidget *dialog_action_area1;
	GtkWidget *cancel_font_button;
	GtkWidget *save_font_button;
		
	cfg_option_dialog = gtk_dialog_new ();
	gtk_widget_set_size_request (cfg_option_dialog, 240, 260);
	gtk_window_set_title (GTK_WINDOW (cfg_option_dialog), _("config_option"));
	gtk_window_set_position (GTK_WINDOW (cfg_option_dialog), GTK_WIN_POS_CENTER_ON_PARENT);
	gtk_window_set_destroy_with_parent (GTK_WINDOW (cfg_option_dialog), TRUE);
	cfg_dialog_icon_pixbuf = create_pixbuf ("xgcom.png");
	if (cfg_dialog_icon_pixbuf) {
		gtk_window_set_icon (GTK_WINDOW (cfg_option_dialog), cfg_dialog_icon_pixbuf);
		//gdk_pixbuf_unref (cfg_dialog_icon_pixbuf);
		g_object_unref(cfg_dialog_icon_pixbuf);
	}
	gtk_window_set_type_hint (GTK_WINDOW (cfg_option_dialog), GDK_WINDOW_TYPE_HINT_DIALOG);
	gtk_window_set_gravity (GTK_WINDOW (cfg_option_dialog), GDK_GRAVITY_CENTER);

	dialog_vbox = GTK_DIALOG (cfg_option_dialog)->vbox;
	gtk_widget_show (dialog_vbox);

	setuo_frame = gtk_frame_new (NULL);
	gtk_widget_show (setuo_frame);
	gtk_box_pack_start (GTK_BOX (dialog_vbox), setuo_frame, TRUE, TRUE, 0);
	gtk_container_set_border_width (GTK_CONTAINER (setuo_frame), 4);
	gtk_frame_set_label_align (GTK_FRAME (setuo_frame), 0.04, 0.51);

	alignment2 = gtk_alignment_new (0.5, 0.5, 1, 1);
	gtk_widget_show (alignment2);
	gtk_container_add (GTK_CONTAINER (setuo_frame), alignment2);
	gtk_alignment_set_padding (GTK_ALIGNMENT (alignment2), 0, 0, 12, 0);

	setup_tablel = gtk_table_new (2, 2, FALSE);
	gtk_widget_show (setup_tablel);
	gtk_container_add (GTK_CONTAINER (alignment2), setup_tablel);
	gtk_container_set_border_width (GTK_CONTAINER (setup_tablel), 3);

	label_font = gtk_label_new (_("Font"));
	gtk_widget_show (label_font);
	gtk_table_attach (GTK_TABLE (setup_tablel), label_font, 0, 1, 0, 1,
		(GtkAttachOptions) (GTK_FILL),
		(GtkAttachOptions) (0), 0, 0);
	gtk_widget_set_size_request (label_font, 90, -1);
	gtk_misc_set_alignment (GTK_MISC (label_font), 0, 0.5);

	setup_label = gtk_label_new (_("\74b\76Setup\74\57b\76"));
	gtk_widget_show (setup_label);
	gtk_frame_set_label_widget (GTK_FRAME (setuo_frame), setup_label);
	gtk_label_set_use_markup (GTK_LABEL (setup_label), TRUE);

	dialog_action_area1 = GTK_DIALOG (cfg_option_dialog)->action_area;
	gtk_widget_show (dialog_action_area1);
	gtk_button_box_set_layout (GTK_BUTTON_BOX (dialog_action_area1), GTK_BUTTONBOX_END);

	save_font_button = gtk_button_new_with_mnemonic (_("Save")); 
	gtk_widget_show (save_font_button);
	gtk_dialog_add_action_widget (GTK_DIALOG (cfg_option_dialog), save_font_button, GTK_RESPONSE_OK);
	
	cancel_font_button = gtk_button_new_with_mnemonic (_("Cancel"));
	gtk_widget_show (cancel_font_button);
	gtk_dialog_add_action_widget (GTK_DIALOG (cfg_option_dialog), cancel_font_button, GTK_RESPONSE_OK);
	GTK_WIDGET_SET_FLAGS (cancel_font_button, GTK_CAN_DEFAULT);

	g_signal_connect ((gpointer) save_font_button, "clicked",
		G_CALLBACK (on_save_font_button_clicked),
		(gpointer)xcomdata);
	g_signal_connect ((gpointer) cancel_font_button, "clicked",
		G_CALLBACK (on_cancel_font_button_clicked),
		(gpointer)xcomdata);

	return cfg_option_dialog;	
}


void
on_save_font_button_clicked (GtkButton *button, gpointer user_data)
{	
	//TODO
	
	gtk_widget_destroy(GTK_WIDGET(cfg_option_dialog));
	return;
}

void
on_cancel_font_button_clicked (GtkButton *button, gpointer user_data)
{
	//TODO
	
	gtk_widget_destroy(GTK_WIDGET(cfg_option_dialog));	
	return;
}

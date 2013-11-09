/*
 * XGCom (Xiyou Linux Group)
 *
 * Copyright (c) 2008-~  Xiyou Linux Group
 *
 * This source code is released for free distribution under the
 * terms of the GNU General Public License.
 *
 * file name: CfgOptionFace.c
 * modify date: 2013-9-17
 * Author: coolshou2060
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

//#include "support.h"
#include "Funs.h"
#include "Cfg.h"

static GtkWidget *cfg_option_dialog;

display_config_t term_conf;

void read_font_button(GtkFontButton *fontButton);
//font dialog
void on_save_option_button_clicked (GtkButton *button, gpointer user_data);
void on_cancel_option_button_clicked (GtkButton *button, gpointer user_data);

GtkWidget* create_configuration_option_dialog (struct xcomdata *xcomdata)
{
	GtkWidget   *BoiteH, *BoiteV, *Label;
	gchar *font;
    GtkWidget *fontButton;

	GdkPixbuf *cfg_dialog_icon_pixbuf;
	GtkWidget *dialog_vbox;
	GtkWidget *setup_gridl;
	GtkWidget *label_font;

	GtkWidget *dialog_action_area1;
	GtkWidget *cancel_button;
	GtkWidget *save_button;
		
	cfg_option_dialog = gtk_dialog_new ();
	gtk_widget_set_size_request (cfg_option_dialog, 400, 260);
	gtk_window_set_title (GTK_WINDOW (cfg_option_dialog), _("config_option"));
	gtk_window_set_position (GTK_WINDOW (cfg_option_dialog), GTK_WIN_POS_CENTER_ON_PARENT);
	gtk_window_set_destroy_with_parent (GTK_WINDOW (cfg_option_dialog), TRUE);
	cfg_dialog_icon_pixbuf = create_pixbuf ("xgcom.png");
	if (cfg_dialog_icon_pixbuf) {
		gtk_window_set_icon (GTK_WINDOW (cfg_option_dialog), cfg_dialog_icon_pixbuf);
		g_object_unref(cfg_dialog_icon_pixbuf);
	}
	gtk_window_set_type_hint (GTK_WINDOW (cfg_option_dialog), GDK_WINDOW_TYPE_HINT_DIALOG);
	gtk_window_set_gravity (GTK_WINDOW (cfg_option_dialog), GDK_GRAVITY_CENTER);

	dialog_vbox = gtk_dialog_get_content_area(GTK_DIALOG (cfg_option_dialog));	
	gtk_widget_show (dialog_vbox);
	
	setup_gridl = gtk_grid_new();
	gtk_widget_set_hexpand (setup_gridl, TRUE);
	gtk_widget_set_halign (setup_gridl, GTK_ALIGN_FILL);
	gtk_widget_set_vexpand (setup_gridl, TRUE);
	gtk_widget_set_valign (setup_gridl, GTK_ALIGN_FILL);
	gtk_widget_show (setup_gridl);
	gtk_container_add (GTK_CONTAINER (dialog_vbox), setup_gridl);
		

    BoiteH = gtk_grid_new();
    gtk_widget_show (BoiteH);
	gtk_grid_attach (GTK_GRID (setup_gridl), BoiteH, 0, 0, 1, 1);    
    
    Label = gtk_label_new(NULL);
    gtk_widget_show (Label);
    gtk_label_set_markup(GTK_LABEL(Label), "<b>Font selection: </b>");
	gtk_grid_attach (GTK_GRID (BoiteH), Label, 0, 0, 1, 1);        

    font =  g_strdup (term_conf.font);
    fontButton = gtk_font_button_new_with_font(font);
    gtk_widget_show (fontButton);
	gtk_grid_attach (GTK_GRID (BoiteH), fontButton, 1, 0, 1, 1);    
    g_signal_connect(GTK_WIDGET(fontButton), "font-set", G_CALLBACK(read_font_button), 0);
    
//button==============================
	dialog_action_area1 = gtk_dialog_get_action_area(GTK_DIALOG (cfg_option_dialog));
	gtk_widget_show (dialog_action_area1);
	gtk_button_box_set_layout (GTK_BUTTON_BOX (dialog_action_area1), GTK_BUTTONBOX_END);

	save_button = gtk_button_new_with_mnemonic (_("Save")); 
	gtk_widget_show (save_button);
	gtk_dialog_add_action_widget (GTK_DIALOG (cfg_option_dialog), save_button, GTK_RESPONSE_OK);
	
	cancel_button = gtk_button_new_with_mnemonic (_("Cancel"));
	gtk_widget_show (cancel_button);
	gtk_dialog_add_action_widget (GTK_DIALOG (cfg_option_dialog), cancel_button, GTK_RESPONSE_OK);
	gtk_widget_set_can_focus(cancel_button, TRUE);
	
	g_signal_connect ((gpointer) save_button, "clicked",
		G_CALLBACK (on_save_option_button_clicked),
		(gpointer)xcomdata);
	g_signal_connect ((gpointer) cancel_button, "clicked",
		G_CALLBACK (on_cancel_option_button_clicked),
		(gpointer)xcomdata);

	return cfg_option_dialog;	
}


void
on_save_option_button_clicked (GtkButton *button, gpointer user_data)
{	
	//TODO
	//save setting
	//apply setting
	gtk_widget_destroy(GTK_WIDGET(cfg_option_dialog));
	return;
}

void
on_cancel_option_button_clicked (GtkButton *button, gpointer user_data)
{
	//TODO
	
	gtk_widget_destroy(GTK_WIDGET(cfg_option_dialog));	
	return;
}

void 
read_font_button(GtkFontButton *fontButton)
{
	g_free(term_conf.font);
	term_conf.font = g_strdup(gtk_font_button_get_font_name(fontButton));
	
//TODO: set vte_term font
	//if(term_conf.font != NULL)
	//	vte_terminal_set_font_from_string(VTE_TERMINAL(display), term_conf.font);
}

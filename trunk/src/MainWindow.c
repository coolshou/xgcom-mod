/*
 * XGCom (Xiyou Linux Group)
 *
 * Copyright (c) 2008-~  Xiyou Linux Group
 *
 * This source code is released for free distribution under the
 * terms of the GNU General Public License.
 *
 * file name: MainWindow.c
 * modify date: 2009-7-30
 * Author: helight.xu@gmail.com
 *
 * Program definitions:
 */

#ifdef HAVE_CONFIG_H
#	include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

//#include <giomm/settings.h>

#include "support.h"
#include "MainWindow.h"
#include "FootFace.h"
#include "MenuFace.h"
#include "RightVboxFace.h"
#include "LeftVboxFace.h"



GtkWidget* create_Xgcom (struct xcomdata *xcomdata)
{
	GtkWidget *main_window;
	GdkPixbuf *Xgcom_icon_pixbuf;
	//GtkWidget *main_vbox;
	GtkWidget *main_vgrid;
/*-------------------------main_menubar---------------------*/
	GtkWidget *main_menubar;
/*-------------------------body_hbox------------------------*/
	//GtkWidget *body_hbox;
	GtkWidget *body_hgrid;
/*------------------------left_vbox-------------------------*/	
	//GtkWidget *left_vbox;
	GtkWidget *left_vgrid;
/*------------------------right_vbox-------------------------*/
	//GtkWidget *right_vbox;
	GtkWidget *right_vgrid;	
/*------------------------foot_hbox--------------------------*/
	//GtkWidget *foot_hbox;
	GtkWidget *foot_hgrid;
	
	GtkAccelGroup *accel_group;
	accel_group = gtk_accel_group_new ();
	
//TODO: font
	PangoFontMap *fontmap;
	PangoFontFamily **families;
	int n_families;
	int i;
	fontmap = pango_cairo_font_map_get_default();	
	pango_font_map_list_families(fontmap,&families,&n_families);
	debug_p("n_families: %d \n", n_families);
	for (i = 0; i < n_families; i++) {
        PangoFontFamily * family = families[i];
        const char * family_name;
        family_name = pango_font_family_get_name (family);
        //TODO: chech if we have "Droid Sans Mono"
        if ( strcmp(family_name, "Droid Sans Mono") == 0 ) {
			printf ("===================font match: %s===================\n", family_name);			
		}
        //printf ("Family %d: %s\n", i, family_name);
    }
    g_free (families);
//end font
    
	//settings = Gio.Settings('org.gnome.desktop.interface');
	//monospace-font-name
	//font_name = settings.get_string('font-name');
	//GtkWidget *text_view;
	//text_view = gtk_text_view_new();
	//context = text_view.get_pango_context()

	main_window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	//gtk_widget_set_size_request (main_window, 600, 700);
	gtk_widget_set_can_focus(main_window, TRUE);
	//GTK_WIDGET_SET_FLAGS (main_window, GTK_CAN_DEFAULT);
	gtk_widget_set_can_default (main_window, TRUE);
	gtk_window_set_title (GTK_WINDOW (main_window), _("XGCom ("VERSION")"));
	//gtk_window_set_default_size (GTK_WINDOW (main_window), 600, 700);
	gtk_window_set_destroy_with_parent (GTK_WINDOW (main_window), TRUE);
	gtk_window_set_position (GTK_WINDOW (main_window), GTK_WIN_POS_CENTER);
	Xgcom_icon_pixbuf = create_pixbuf ("xgcom.png");
	if (Xgcom_icon_pixbuf){
		gtk_window_set_icon (GTK_WINDOW (main_window), Xgcom_icon_pixbuf);
		//gdk_pixbuf_unref (Xgcom_icon_pixbuf);
		g_object_unref(Xgcom_icon_pixbuf);
	}
/*
 -------------main_window----------------------------
 -------------main_vgrid-----------------------------
 |   main_menubar									|
 |-------------body_hgrid---------------------------|
 ||------ left_vgrid --|-----right_vgrid ----------||
 ||                    |						   ||
 ||                    |						   ||
 |--------------------------------------------------|
 |-------------foot_hgrid---------------------------|
 ||												   ||
 |--------------------------------------------------|
 ---------------------------------------------------- 
*/
	//main_vbox = gtk_vbox_new (FALSE, 0);
	//main_vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
	//gtk_widget_show (main_vbox);	
	//gtk_container_add (GTK_CONTAINER (main_window), main_vbox);
	
	main_vgrid = gtk_grid_new();
	gtk_widget_set_hexpand (main_vgrid, TRUE);
	gtk_widget_set_halign (main_vgrid, GTK_ALIGN_FILL);
	gtk_widget_set_vexpand (main_vgrid, TRUE);
	gtk_widget_set_valign (main_vgrid, GTK_ALIGN_FILL);
	gtk_widget_show(main_vgrid);
	//gtk_grid_set_orientation(main_vgrid, GTK_ORIENTATION_VERTICAL);
	gtk_orientable_set_orientation (GTK_ORIENTABLE (main_vgrid), GTK_ORIENTATION_VERTICAL);
	gtk_container_add (GTK_CONTAINER (main_window), main_vgrid);
	
/*------------------------main_menubar-----------------------*/
	main_menubar = create_menu(main_window, main_vgrid, accel_group, xcomdata);

/*------------------------body_hbox--------------------------*/
	body_hgrid = gtk_grid_new();
	gtk_widget_set_hexpand (body_hgrid, TRUE);
	gtk_widget_set_halign (body_hgrid, GTK_ALIGN_FILL);
	gtk_widget_set_vexpand (body_hgrid, TRUE);
	gtk_widget_set_valign (body_hgrid, GTK_ALIGN_FILL);
	gtk_widget_show(body_hgrid);
	gtk_grid_attach (GTK_GRID (main_vgrid), body_hgrid, 0, 1, 1, 1);
	
/*-------------------------create_leftvbox-------------------*/
	left_vgrid = create_leftvbox(main_window, body_hgrid, accel_group, xcomdata);
	
/*-------------------------create_rightvbox------------------*/
	right_vgrid = create_rightvbox(main_window, body_hgrid, accel_group, xcomdata);
	
/*-------------------------create_foot-----------------------*/
	foot_hgrid = create_foot(main_window, main_vgrid, xcomdata);

	g_signal_connect ((gpointer) main_window, "delete_event",
		G_CALLBACK (on_Xgcom_delete_event), NULL);

	gtk_widget_grab_focus (main_window);
	gtk_widget_grab_default (main_window);
	gtk_window_add_accel_group (GTK_WINDOW (main_window), accel_group);

	xcomdata->gmain = main_window;
	debug_p("baud: %d \n", xcomdata->comcfg.baud);
	
	return main_window;
}

gboolean
on_Xgcom_delete_event (GtkWidget *widget, GdkEvent *event, gpointer user_data)
{
	debug_p("bye world;\n");
	close_uart();
	gtk_main_quit();
	
	return FALSE;
}

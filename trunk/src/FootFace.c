/*
 * XGCom (Xiyou Linux Group)
 *
 * Copyright (c) 2008-~  Xiyou Linux Group
 *
 * This source code is released for free distribution under the
 * terms of the GNU General Public License.
 *
 * file name: FootFace.c
 * modify date: 2009-7-30
 * Author: helight.xu@gmail.com
 *
 * Program definitions:
 */
#include "FootFace.h"

GtkWidget*
create_foot (GtkWidget *main_window, GtkWidget *main_vbox, struct xcomdata *xcomdata)
{
	//GtkWidget *foot_hbox;
	GtkWidget *foot_hgrid;
	GtkWidget *conf_label;
	GtkWidget *conf_parameter;
	GtkWidget *com_label;
	GtkWidget *com_stat;
	GtkWidget *space;
	
	debug_p("FootFace ========\n");	
	
	foot_hgrid = gtk_grid_new();
	//test
	//GdkColor color;
	//gdk_color_parse ("red", &color);
	//gtk_widget_modify_fg (widget, GTK_STATE_NORMAL, &color);
	//gtk_widget_modify_fg (foot_hgrid, GTK_STATE_NORMAL, &color);
	//test end

	gtk_widget_set_hexpand (foot_hgrid, TRUE);
	gtk_widget_set_halign (foot_hgrid, GTK_ALIGN_FILL);
	gtk_widget_set_vexpand (foot_hgrid, FALSE);
	gtk_widget_set_valign (foot_hgrid, GTK_ALIGN_END);

	gtk_widget_show (foot_hgrid);
	gtk_grid_attach (GTK_GRID (main_vbox), foot_hgrid, 0, 2, 1, 1);

		conf_label = gtk_label_new (_("Parameter: "));
		gtk_widget_show (conf_label);
		gtk_grid_attach (GTK_GRID (foot_hgrid), conf_label, 0, 0, 1, 1);
		//gtk_widget_set_size_request (conf_label, 80, 20);

		conf_parameter = gtk_label_new (_("com"));
		gtk_widget_show (conf_parameter);
		gtk_grid_attach (GTK_GRID (foot_hgrid), conf_parameter, 1, 0, 1, 1);
		//gtk_misc_set_alignment (GTK_MISC (conf_parameter), 0, 0.5);
		//gtk_widget_set_size_request (conf_parameter, -1, 50);
		
		space = gtk_label_new("         ");
		gtk_widget_show(space);
		gtk_grid_attach (GTK_GRID (foot_hgrid), space, 2, 0, 1, 1);
		//gtk_grid_insert_column(GTK_GRID (foot_hbox),2);
		
		com_label = gtk_label_new (_("State: "));
		gtk_widget_show (com_label);
		gtk_grid_attach (GTK_GRID (foot_hgrid), com_label, 3, 0, 1, 1);
		//gtk_widget_set_size_request (com_label, 50, 20);
		//gtk_label_set_line_wrap (GTK_LABEL (com_label), TRUE);

		com_stat = gtk_label_new (_("close"));
		gtk_widget_show (com_stat);
		gtk_grid_attach (GTK_GRID (foot_hgrid), com_stat, 4, 0, 1, 1);
		//gtk_widget_set_size_request (com_stat, 60, 20);
		//gtk_grid_set_column_homogeneous(GTK_GRID(foot_hbox),TRUE); 
		
	xcomdata->gconf_parameter = conf_parameter;
	xcomdata->gcom_stat = com_stat;
	return foot_hgrid;
}

/*
 * XGCom (Xiyou Linux Group)
 *
 * Copyright (c) 2008-~  Xiyou Linux Group
 *
 * This source code is released for free distribution under the
 * terms of the GNU General Public License.
 *
 * file name: LeftVboxFace.c
 * modify date: 2009-7-30
 * Author: helight.xu@gmail.com
 *
 * Program definitions:
 */
#include "LeftVboxFace.h"
#include "LeftVboxCall.h"

GtkWidget*
create_leftvbox (GtkWidget *main_window, GtkWidget *body_hbox, 
	GtkAccelGroup *accel_group, struct xcomdata *xcomdata)
{
	GtkWidget *left_vgrid;
	GtkWidget *left_top_vgrid;
	GtkWidget *left_foot_vgrid;
	
	GtkWidget *grid_conf;
	GtkWidget *conf_button;
	GtkWidget *save_conf;
	GtkWidget *open_uart;
	GtkWidget *load_conf;
	GtkWidget *grid_hex;
	GtkWidget *hex_show;
	//GtkWidget *hbox_send;
	GtkWidget *hgrid_send;
	GtkWidget *send_num_label;
	GtkWidget *send_num;
	gchar *send_num_str = "0";
	//GtkWidget *hbox_rcv;
	GtkWidget *hgrid_rcv;
	GtkWidget *rcv_num_label;
	GtkWidget *rcv_num;
	gchar *rcv_num_str = "0";
	GtkWidget *grid_flush;
	GtkWidget *new_count;
	GtkWidget *clean_rcv_buff;
	GtkWidget *save_data;
	GtkWidget *frame_save;
	GtkWidget *alignment3;
	GtkWidget *vbox_frame_save;
	GtkWidget *add_save;
	GSList *add_save_group = NULL;
	GtkWidget *cover_save;
	GtkWidget *save_label;
	GtkWidget *grid_send_file;
	GtkWidget *choose_file;
	GtkWidget *send_file;
	GtkWidget *clean_send_buff;
	GtkWidget *send_data;
	GtkWidget *fixed_free_space;
	GtkWidget *grid_hex_send;
	GtkWidget *hex_send;
	GtkWidget *keep_send;
	//GtkWidget *hbox_interval;
	GtkWidget *hgrid_interval;
	GtkWidget *time_label;
	GtkWidget *time_interval;
	gchar *time_interval_str = "100";
	GtkWidget *left_top;
	GtkWidget *left_bottom;
	GtkWidget *button1;
  
	left_vgrid = gtk_grid_new();
	gtk_widget_set_halign (left_vgrid, GTK_ALIGN_CENTER);	
	gtk_widget_set_vexpand (left_vgrid, TRUE);
	gtk_widget_set_valign (left_vgrid, GTK_ALIGN_FILL);
	gtk_widget_show (left_vgrid);
	gtk_grid_attach (GTK_GRID (body_hbox), left_vgrid, 0, 0, 1, 1);
	gtk_widget_set_size_request (left_vgrid, 50, -1);
	
		left_top_vgrid = gtk_grid_new();
		gtk_widget_set_halign (left_top_vgrid, GTK_ALIGN_CENTER);
		gtk_widget_show (left_top_vgrid);
		gtk_grid_attach(GTK_GRID (left_vgrid), left_top_vgrid, 0, 0, 1, 1);
		
		debug_p("grid_conf ========\n");
		grid_conf = gtk_grid_new();
		gtk_widget_set_halign (grid_conf, GTK_ALIGN_CENTER);	
		gtk_widget_show (grid_conf);
		gtk_grid_attach(GTK_GRID (left_top_vgrid), grid_conf, 0, 0, 1, 1);
		//gtk_widget_set_size_request (table_conf, 110, 165);
		
			conf_button = gtk_button_new_with_mnemonic (_("Configure"));
			gtk_widget_set_halign (conf_button, GTK_ALIGN_FILL);
			gtk_widget_show (conf_button);
			gtk_grid_attach (GTK_GRID (grid_conf), conf_button, 0, 0, 1, 1);
			
			save_conf = gtk_button_new_with_mnemonic (_("Save Conf"));
			gtk_widget_set_halign (save_conf, GTK_ALIGN_FILL);
			gtk_widget_show (save_conf);
			gtk_grid_attach (GTK_GRID (grid_conf), save_conf, 0, 1, 1, 1);
			
			load_conf = gtk_button_new_with_mnemonic (_("Load Conf"));
			gtk_widget_set_halign (load_conf, GTK_ALIGN_FILL);
			gtk_widget_show (load_conf);
			gtk_grid_attach (GTK_GRID (grid_conf), load_conf, 0, 2, 1, 1);

			open_uart = gtk_button_new_with_mnemonic (_("Open Com"));
			gtk_widget_set_halign (open_uart, GTK_ALIGN_FILL);
			gtk_widget_show (open_uart);
			gtk_grid_attach (GTK_GRID (grid_conf), open_uart, 0, 3, 1, 1);

			clean_rcv_buff = gtk_button_new_with_mnemonic (_("Clear Rcv"));
			gtk_widget_set_halign (clean_rcv_buff, GTK_ALIGN_FILL);
			gtk_widget_show (clean_rcv_buff);
			gtk_grid_attach (GTK_GRID (grid_conf), clean_rcv_buff, 0, 4, 1, 1);

		debug_p("grid_hex ========\n");	
		grid_hex = gtk_grid_new();
		gtk_widget_set_halign (grid_hex, GTK_ALIGN_CENTER);
		gtk_widget_show (grid_hex);
		gtk_grid_attach(GTK_GRID (left_top_vgrid), grid_hex, 0, 1, 1, 1);
		
			hex_show = gtk_check_button_new_with_mnemonic (_("HEX Show"));
			gtk_widget_set_halign (hex_show, GTK_ALIGN_CENTER);
			gtk_widget_show (hex_show);
			gtk_grid_attach (GTK_GRID (grid_hex), hex_show, 0, 0, 1, 1);
			
			hgrid_send = gtk_grid_new();
			gtk_widget_set_halign (hgrid_send, GTK_ALIGN_CENTER);
			gtk_widget_show (hgrid_send);
			gtk_grid_attach (GTK_GRID (grid_hex), hgrid_send, 0, 1, 1, 1);
			
				send_num_label = gtk_label_new (_("S:"));
				gtk_widget_show (send_num_label);
				gtk_grid_attach (GTK_GRID (hgrid_send), send_num_label, 0, 0, 1, 1);

				send_num = gtk_entry_new ();
				gtk_widget_show (send_num);
				gtk_grid_attach (GTK_GRID (hgrid_send), send_num, 1, 0, 1, 1);
				gtk_entry_set_width_chars(GTK_ENTRY(send_num), 7);
				gtk_widget_set_size_request (send_num, 7, -1);
				//gtk_entry_set_invisible_char (GTK_ENTRY (send_num), 9679);
				gtk_editable_set_editable (GTK_EDITABLE (send_num), FALSE);
				gint send_num_str_position = 0;
				gtk_editable_insert_text(GTK_EDITABLE(send_num), send_num_str, -1, &send_num_str_position); 
				
			hgrid_rcv = gtk_grid_new();	
			gtk_widget_set_halign (hgrid_rcv, GTK_ALIGN_CENTER);
			gtk_widget_show (hgrid_rcv);
			gtk_grid_attach (GTK_GRID (grid_hex), hgrid_rcv, 0, 2, 1, 1);
				
				rcv_num_label = gtk_label_new (_("R:"));
				gtk_widget_show (rcv_num_label);
				gtk_grid_attach (GTK_GRID (hgrid_rcv), rcv_num_label, 0, 0, 1, 1);

				rcv_num = gtk_entry_new ();
				gtk_widget_show (rcv_num);
				gtk_grid_attach (GTK_GRID (hgrid_rcv), rcv_num, 1, 0, 1, 1);
				gtk_entry_set_width_chars(GTK_ENTRY(rcv_num), 7);
				gtk_widget_set_size_request (rcv_num, 7, -1);
				//gtk_entry_set_invisible_char (GTK_ENTRY (rcv_num), 9679);
				gtk_editable_set_editable (GTK_EDITABLE (rcv_num), FALSE);
				gint rcv_num_str_position = 0;
				gtk_editable_insert_text(GTK_EDITABLE(rcv_num), rcv_num_str, -1, &rcv_num_str_position); 

		debug_p("grid_flush ========\n");
		grid_flush = gtk_grid_new();
		gtk_widget_set_halign (grid_flush, GTK_ALIGN_CENTER);
		gtk_widget_show (grid_flush);
		gtk_grid_attach(GTK_GRID (left_top_vgrid), grid_flush, 0, 2, 1, 1);

			new_count = gtk_button_new_with_mnemonic (_("Recount"));
			gtk_widget_set_halign (new_count, GTK_ALIGN_FILL);
			gtk_widget_show (new_count);
			gtk_grid_attach (GTK_GRID (grid_flush), new_count, 0, 0, 1, 1);

		frame_save = gtk_frame_new (NULL);
		gtk_widget_show (frame_save);
		gtk_grid_attach(GTK_GRID (left_top_vgrid), frame_save, 0, 3, 1, 1);
		gtk_container_set_border_width (GTK_CONTAINER (frame_save), 2);

			save_label = gtk_label_new (_("Log"));
			gtk_widget_show (save_label);
			gtk_frame_set_label_widget (GTK_FRAME (frame_save), save_label);
			gtk_label_set_use_markup (GTK_LABEL (save_label), TRUE);
			
			alignment3 = gtk_alignment_new (0.5, 0.5, 1, 1);
			gtk_widget_show (alignment3);
			gtk_container_add (GTK_CONTAINER (frame_save), alignment3);

			vbox_frame_save = gtk_grid_new();
			gtk_widget_set_halign (vbox_frame_save, GTK_ALIGN_CENTER);
			gtk_widget_show (vbox_frame_save);
			gtk_container_add (GTK_CONTAINER (alignment3), vbox_frame_save);
			
			save_data = gtk_button_new_with_mnemonic (_("Log Data"));
			gtk_widget_set_halign (save_data, GTK_ALIGN_FILL);
			gtk_widget_show (save_data);
			gtk_grid_attach(GTK_GRID (vbox_frame_save), save_data, 0, 0, 1, 1);
			gtk_widget_set_size_request (save_data, 50, -1);
			
			add_save = gtk_radio_button_new_with_mnemonic (NULL, _("Append"));
			gtk_widget_show (add_save);
			gtk_grid_attach(GTK_GRID (vbox_frame_save), add_save, 0, 1, 1, 1);
			gtk_radio_button_set_group (GTK_RADIO_BUTTON (add_save), add_save_group);
			add_save_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (add_save));

			cover_save = gtk_radio_button_new_with_mnemonic (NULL, _("Rewrite"));
			gtk_widget_show (cover_save);
			gtk_grid_attach(GTK_GRID (vbox_frame_save), cover_save, 0, 2, 1, 1);
			gtk_radio_button_set_group (GTK_RADIO_BUTTON (cover_save), add_save_group);
			add_save_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (cover_save));


		left_foot_vgrid = gtk_grid_new();
		gtk_widget_set_halign (left_foot_vgrid, GTK_ALIGN_CENTER);
		gtk_widget_show (left_foot_vgrid);
		gtk_grid_attach(GTK_GRID (left_vgrid), left_foot_vgrid, 0, 1, 1, 1);

			debug_p("grid_send_file =====left_foot_vgrid===\n");
			grid_send_file = gtk_grid_new();
			gtk_widget_set_halign (grid_send_file, GTK_ALIGN_CENTER);
			gtk_widget_show (grid_send_file);
			gtk_grid_attach (GTK_GRID (left_foot_vgrid), grid_send_file, 0, 0, 1, 1);
			
				choose_file = gtk_button_new_with_mnemonic (_("Select File"));
				gtk_widget_set_halign (choose_file, GTK_ALIGN_FILL);
				gtk_widget_show (choose_file);
				gtk_grid_attach (GTK_GRID (grid_send_file), choose_file, 0, 0, 1, 1);
				
				send_file = gtk_button_new_with_mnemonic (_("Send File"));
				gtk_widget_set_halign (send_file, GTK_ALIGN_FILL);
				gtk_widget_show (send_file);
				gtk_grid_attach (GTK_GRID (grid_send_file), send_file, 0, 1, 1, 1);
				
				send_data = gtk_button_new_with_mnemonic (_("Send Data"));
				gtk_widget_set_halign (send_data, GTK_ALIGN_FILL);
				gtk_widget_show (send_data);
				gtk_grid_attach (GTK_GRID (grid_send_file), send_data, 0, 2, 1, 1);
				
				clean_send_buff = gtk_button_new_with_mnemonic (_("Clear Send"));
				gtk_widget_set_halign (clean_send_buff, GTK_ALIGN_FILL);
				gtk_widget_show (clean_send_buff);
				gtk_grid_attach (GTK_GRID (grid_send_file), clean_send_buff, 0, 3, 1, 1);

			debug_p("grid_hex_send =====left_foot_vgrid===\n");
			grid_hex_send = gtk_grid_new();
			gtk_widget_set_halign (grid_hex_send, GTK_ALIGN_CENTER);
			gtk_widget_show (grid_hex_send);
			gtk_grid_attach (GTK_GRID (left_foot_vgrid), grid_hex_send, 0, 1, 1, 1);
			
			hex_send = gtk_check_button_new_with_mnemonic (_("HEX Send"));
			gtk_widget_set_halign (hex_send, GTK_ALIGN_CENTER);
			gtk_widget_show (hex_send);
			gtk_grid_attach (GTK_GRID (grid_hex_send), hex_send, 0, 0, 1, 1);

			keep_send = gtk_check_button_new_with_mnemonic (_("Continual"));
			gtk_widget_set_halign (keep_send, GTK_ALIGN_CENTER);
			gtk_widget_show (keep_send);
			gtk_grid_attach (GTK_GRID (grid_hex_send), keep_send, 0, 1, 1, 1);

			hgrid_interval = gtk_grid_new();
			gtk_widget_set_halign (hgrid_interval, GTK_ALIGN_CENTER);
			gtk_widget_show (hgrid_interval);
			gtk_grid_attach (GTK_GRID (grid_hex_send), hgrid_interval, 0, 2, 1, 1);
			
				time_label = gtk_label_new (_("Int:"));
				gtk_widget_show (time_label);
				gtk_grid_attach (GTK_GRID (hgrid_interval), time_label, 0, 0, 1, 1);

				time_interval = gtk_entry_new ();
				gtk_widget_show (time_interval);
				gtk_grid_attach (GTK_GRID (hgrid_interval), time_interval, 1, 0, 1, 1);
				//TODO: number only
				gtk_entry_set_width_chars(GTK_ENTRY(time_interval), 5);
				gtk_widget_set_size_request (time_interval, 5, -1);
				//gtk_entry_set_invisible_char (GTK_ENTRY (time_interval), 9679);
				gint time_interval_str_position = 0 ;
				gtk_editable_insert_text(GTK_EDITABLE(time_interval), time_interval_str, -1, &time_interval_str_position); 

			left_bottom = gtk_fixed_new();
			gtk_widget_show(left_bottom);
			gtk_grid_attach (GTK_GRID (left_foot_vgrid), left_bottom, 0, 3, 1, 1);

	g_signal_connect ((gpointer) conf_button, "clicked",
		G_CALLBACK (on_conf_button_clicked),
		(gpointer)xcomdata);
	g_signal_connect ((gpointer) save_conf, "clicked",
		G_CALLBACK (on_save_conf_clicked),
		(gpointer)xcomdata);
	g_signal_connect ((gpointer) open_uart, "clicked",
		G_CALLBACK (on_open_uart_clicked),
		(gpointer)xcomdata);
	g_signal_connect ((gpointer) load_conf, "clicked",
		G_CALLBACK (on_load_conf_clicked),
		(gpointer)xcomdata);
	g_signal_connect ((gpointer) hex_show, "toggled",
		G_CALLBACK (on_hex_show_toggled),
		(gpointer)xcomdata);
	g_signal_connect ((gpointer) new_count, "clicked",
		G_CALLBACK (on_new_count_clicked),
		(gpointer)xcomdata);
	g_signal_connect ((gpointer) clean_rcv_buff, "clicked",
		G_CALLBACK (on_clean_rcv_buff_clicked),
		(gpointer)xcomdata);
	g_signal_connect ((gpointer) save_data, "clicked",
		G_CALLBACK (on_save_data_clicked),
		(gpointer)xcomdata);
	g_signal_connect ((gpointer) add_save, "toggled",
		G_CALLBACK (on_add_save_toggled),
		(gpointer)xcomdata);
	g_signal_connect ((gpointer) cover_save, "toggled",
		G_CALLBACK (on_cover_save_toggled),
		(gpointer)xcomdata);
	g_signal_connect ((gpointer) choose_file, "clicked",
		G_CALLBACK (on_choose_file_clicked),
		(gpointer)xcomdata);
	g_signal_connect ((gpointer) send_file, "clicked",
		G_CALLBACK (on_send_file_clicked),
		(gpointer)xcomdata);
	g_signal_connect ((gpointer) clean_send_buff, "clicked",
		G_CALLBACK (on_clean_send_buff_clicked), 
		(gpointer)xcomdata);
	g_signal_connect ((gpointer) send_data, "clicked",
		G_CALLBACK (on_send_data_clicked), 
		(gpointer)xcomdata);
	g_signal_connect ((gpointer) hex_send, "toggled",
		G_CALLBACK (on_hex_send_toggled),
		(gpointer)xcomdata);
	g_signal_connect ((gpointer) keep_send, "toggled",
		G_CALLBACK (on_keep_send_toggled),
		(gpointer)xcomdata);

	xcomdata->ghex_show = hex_show;
	xcomdata->grcv_num_show = rcv_num;
	xcomdata->gsend_num_show = send_num;
	xcomdata->button_save_vte = save_data;
	xcomdata->button_open_uart = open_uart;
	xcomdata->gbutton_send_data = send_data;
	xcomdata->gbutton_send_file = send_file;
	xcomdata->gkeep_send = keep_send;
	xcomdata->ginterval = time_interval;
	gtk_widget_set_sensitive(GTK_WIDGET(send_data), FALSE);
	gtk_widget_set_sensitive(GTK_WIDGET(send_file), FALSE);
	gtk_widget_set_sensitive(GTK_WIDGET(keep_send), FALSE);
	
	//struct xcomdata *xcomdata = (struct xcomdata *)user_data;
	debug_p("left_vgrid baud: %d \n", xcomdata->comcfg.baud);
	return left_vgrid;
}

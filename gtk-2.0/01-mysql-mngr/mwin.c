
/*
 * mwin.c
 * dark_neo
 * 2014-06-13
 */

#include <stdlib.h>
#include "mwin.h"

void on_win_destroy(main_window *mw)
{
	mw->windows = g_slist_remove(mw->windows, NULL);

	if (g_slist_length(mw->windows) == 0) {
		/* last window was closed */
		g_slist_free(mw->windows);
		/*gtk_main_quit(); */
	}
}

void on_fmitem_cnn_click(main_window *mw)
{
	mwin_conn *mwc = (mwin_conn *) malloc(sizeof(mwin_conn));

	if (mwc == NULL) {
		fprintf(stderr, "\nError allocating memory for 'mwc'\n");
		return;
	}

	mwc->win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(mwc->win), MWINCONN_TITLE);
	gtk_window_set_position(GTK_WINDOW(mwc->win), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(mwc->win), MWINCONN_WIDTH,
					MWINCONN_HEIGHT);
	create_labels(mwc);

	gtk_widget_show_all(mwc->win);
}

void create_fmnu(main_window *mw)
{
	mw->fm_accel = gtk_accel_group_new();
	gtk_window_add_accel_group(GTK_WINDOW(mw->win), mw->fm_accel);

	mw->fsub_mnu = gtk_menu_new();
	mw->fmitem_cnn = gtk_menu_item_new_with_mnemonic("_Connect");
	gtk_menu_shell_append(GTK_MENU_SHELL(mw->fsub_mnu), mw->fmitem_cnn);
	gtk_widget_add_accelerator(mw->fmitem_cnn, "activate", mw->fm_accel,
					GDK_n, GDK_CONTROL_MASK,
					GTK_ACCEL_VISIBLE);
	g_signal_connect(G_OBJECT(mw->fmitem_cnn), "activate",
				G_CALLBACK(on_fmitem_cnn_click), mw);

	mw->fmitem_dcn = gtk_menu_item_new_with_mnemonic("_Disconnect");
	gtk_menu_shell_append(GTK_MENU_SHELL(mw->fsub_mnu), mw->fmitem_dcn);
	gtk_widget_add_accelerator(mw->fmitem_dcn, "activate", mw->fm_accel,
					GDK_d, GDK_CONTROL_MASK,
					GTK_ACCEL_VISIBLE);
		/* handler_goes_here */

	mw->msep = gtk_separator_menu_item_new();
	gtk_menu_shell_append(GTK_MENU_SHELL(mw->fsub_mnu), mw->msep);

	mw->fmitem_qut = gtk_menu_item_new_with_mnemonic("_Quit");
	gtk_menu_shell_append(GTK_MENU_SHELL(mw->fsub_mnu), mw->fmitem_qut);
	gtk_widget_add_accelerator(mw->fmitem_qut, "activate", mw->fm_accel, 
					GDK_q, GDK_CONTROL_MASK,
					GTK_ACCEL_VISIBLE);
	g_signal_connect_swapped(G_OBJECT(mw->win), "destroy",
					G_CALLBACK(on_quitwin), NULL);
	g_signal_connect(G_OBJECT(mw->fmitem_qut), "activate",
				G_CALLBACK(on_quitwin), NULL);

	mw->fmnu = gtk_menu_item_new_with_mnemonic("_File");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(mw->fmnu), mw->fsub_mnu);
}

void create_emnu(main_window *mw)
{
	mw->em_accel = gtk_accel_group_new();
	gtk_window_add_accel_group(GTK_WINDOW(mw->win), mw->em_accel);

	mw->esub_mnu = gtk_menu_new();
	mw->emitem_cpy = gtk_menu_item_new_with_mnemonic("_Copy");
	gtk_menu_shell_append(GTK_MENU_SHELL(mw->esub_mnu), mw->emitem_cpy);
	gtk_widget_add_accelerator(mw->emitem_cpy, "activate", mw->em_accel,
					GDK_c, GDK_CONTROL_MASK,
					GTK_ACCEL_VISIBLE);
		/* handler_goes_here */

	mw->emitem_cut = gtk_menu_item_new_with_mnemonic("C_ut");
	gtk_menu_shell_append(GTK_MENU_SHELL(mw->esub_mnu), mw->emitem_cut);
	gtk_widget_add_accelerator(mw->emitem_cut, "activate", mw->em_accel,
					GDK_x, GDK_CONTROL_MASK,
					GTK_ACCEL_VISIBLE);
		/* handler_goes_here */

	mw->emitem_pst = gtk_menu_item_new_with_mnemonic("_Paste");
	gtk_menu_shell_append(GTK_MENU_SHELL(mw->esub_mnu), mw->emitem_pst);
	gtk_widget_add_accelerator(mw->emitem_pst, "activate", 
					mw->em_accel,
					GDK_v, GDK_CONTROL_MASK,
					GTK_ACCEL_VISIBLE);
		/* handler_goes_here */

	mw->msep = gtk_separator_menu_item_new();
	gtk_menu_shell_append(GTK_MENU_SHELL(mw->esub_mnu), mw->msep);

	mw->emitem_sta = gtk_menu_item_new_with_mnemonic("_Select all");
	gtk_menu_shell_append(GTK_MENU_SHELL(mw->esub_mnu), mw->emitem_sta);
	gtk_widget_add_accelerator(mw->emitem_sta, "activate", mw->em_accel,
					GDK_a, GDK_CONTROL_MASK,
					GTK_ACCEL_VISIBLE);
		/* handler_goes_here */

	mw->emnu = gtk_menu_item_new_with_mnemonic("_Edit");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(mw->emnu), mw->esub_mnu);
}

void create_hmnu(main_window *mw)
{
	mw->hm_accel = gtk_accel_group_new();
	gtk_window_add_accel_group(GTK_WINDOW(mw->win), mw->hm_accel);

	mw->hsub_mnu = gtk_menu_new();
	mw->hmitem_abt = gtk_menu_item_new_with_mnemonic("_About");
	gtk_menu_shell_append(GTK_MENU_SHELL(mw->hsub_mnu), mw->hmitem_abt);
	gtk_widget_add_accelerator(mw->hmitem_abt, "activate", mw->hm_accel,
					GDK_h, GDK_CONTROL_MASK,
					GTK_ACCEL_VISIBLE);
		/* handler_goes_here */

	mw->hmnu = gtk_menu_item_new_with_mnemonic("_Help");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(mw->hmnu), mw->hsub_mnu);
}

void create_mnubar(main_window *mw)
{
	/* Create a vbox to put the menu */
	mw->vbox = gtk_vbox_new(false, 0);
	gtk_container_add(GTK_CONTAINER(mw->win), mw->vbox);

	mw->mnu_bar = gtk_menu_bar_new();
	gtk_box_pack_start(GTK_BOX(mw->vbox), mw->mnu_bar, false, false, 2);

	/* Add the menu to menu-bar */
	gtk_menu_shell_append(GTK_MENU_SHELL(mw->mnu_bar), mw->fmnu);
	gtk_menu_shell_append(GTK_MENU_SHELL(mw->mnu_bar), mw->emnu);
	gtk_menu_shell_append(GTK_MENU_SHELL(mw->mnu_bar), mw->hmnu);
}

void create_statusbar(main_window *mw)
{
	mw->statusbar = gtk_statusbar_new();
	gtk_statusbar_push(GTK_STATUSBAR(mw->statusbar), 0, mw->statusbar_msg);
	gtk_box_pack_end(GTK_BOX(mw->vbox), mw->statusbar, false, false, 1);
}

void create_mw(main_window *mw, int argc, char **argv)
{
	mw->statusbar_msg = "Ready";

	gtk_init(&argc, &argv);

	mw->win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(mw->win), MWIN_TITLE);
	gtk_window_set_position(GTK_WINDOW(mw->win), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(mw->win), MWIN_WIDTH,
					MWIN_HEIGHT);

	create_fmnu(mw);
	create_emnu(mw);
	create_hmnu(mw);
	create_mnubar(mw);
	create_statusbar(mw);

	gtk_widget_show_all(mw->win);
	gtk_main();
}



/*
 * mwin-connection.c
 * dark_neo
 * 2014-06-14
 */

#include "mwin-conn.h"

void create_labels(mwin_conn *mwc)
{
	mwc->vbox = gtk_vbox_new(FALSE, 10);
	mwc->hbox = gtk_hbox_new(FALSE, 10);

	/*
	gtk_container_add(GTK_CONTAINER(mwc->win), mwc->vbox);
	*/
	gtk_container_add(GTK_CONTAINER(mwc->win), mwc->hbox);

	mwc->lbl_intro = gtk_label_new("Specify your MySQL connection settings:");
	gtk_box_pack_start(GTK_BOX(mwc->vbox), mwc->lbl_intro, false, false, 0);
	/*
	gtk_box_pack_start(GTK_BOX(mwc->hbox), mwc->lbl_intro, false, false, 0);
	*/

	mwc->lbl_host = gtk_label_new("Host");
	gtk_label_set_justify(GTK_LABEL(mwc->lbl_host), GTK_JUSTIFY_LEFT);
	/*
	gtk_box_pack_start(GTK_BOX(mwc->vbox), mwc->lbl_host, false, false, 0);
	*/
	gtk_box_pack_start(GTK_BOX(mwc->hbox), mwc->lbl_host, false, false, 0);

	mwc->txt_host = gtk_entry_new();
	/*
	gtk_box_pack_start(GTK_BOX(mwc->vbox), mwc->lbl_host, false, false, 0);
	*/
	gtk_box_pack_start(GTK_BOX(mwc->hbox), mwc->txt_host, false, false, 0);

	/*
	mwc->lbl_port = gtk_label_new("Port");
	gtk_label_set_justify(GTK_LABEL(mwc->lbl_port), GTK_JUSTIFY_LEFT);
	gtk_box_pack_start(GTK_BOX(mwc->vbox), mwc->lbl_port, false, false, 0);

	mwc->lbl_user = gtk_label_new("User");
	gtk_label_set_justify(GTK_LABEL(mwc->lbl_user), GTK_JUSTIFY_LEFT);
	gtk_box_pack_start(GTK_BOX(mwc->vbox), mwc->lbl_user, false, false, 0);

	mwc->lbl_pass = gtk_label_new("Password");
	gtk_label_set_justify(GTK_LABEL(mwc->lbl_pass), GTK_JUSTIFY_LEFT);
	gtk_box_pack_start(GTK_BOX(mwc->vbox), mwc->lbl_pass, false, false, 0);

	mwc->lbl_db = gtk_label_new("Database");
	gtk_label_set_justify(GTK_LABEL(mwc->lbl_db), GTK_JUSTIFY_LEFT);
	gtk_box_pack_start(GTK_BOX(mwc->vbox), mwc->lbl_db, false, false, 0);
	*/
}

void create_textbox(mwin_conn *mwc)
{
}

void create_buttons(mwin_conn *mwc)
{
}


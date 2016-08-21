
/*
 * mwin-conn.h
 * dark_neo
 * 2014-06-14
 */

#ifndef MWIN_CONN_H
#define MWIN_CONN_H

#include <stdbool.h>
#include "events.h"

#define MWINCONN_TITLE 		"Connection properties"
#define MWINCONN_WIDTH 		400
#define MWINCONN_HEIGHT 	400

/*
 * The window will be created from it's called.
 */
typedef struct _mwin_connection {
	GtkWidget	*win;		/* the window	 */
	GtkWidget	*vbox;
	GtkWidget	*hbox;
	GtkWidget	*frame;

	GtkWidget	*lbl_intro;
	GtkWidget	*lbl_host;
	GtkWidget	*lbl_port;
	GtkWidget	*lbl_user;
	GtkWidget	*lbl_pass;
	GtkWidget	*lbl_db;

	GtkWidget	*txt_host;
	GtkWidget	*txt_port;
	GtkWidget	*txt_user;
	GtkWidget	*txt_pass;	/* masked	*/
	GtkWidget	*cmb_db;	/* combo-box	*/

	GtkWidget	*btn_ok;
	GtkWidget	*btn_cancel;
	GtkWidget	*btn_testconn;
} mwin_conn;

extern void create_labels(mwin_conn *mwc);
extern void create_textbox(mwin_conn *mwc);
extern void create_buttons(mwin_conn *mwc);

#endif /* MWIN_CONN_H */


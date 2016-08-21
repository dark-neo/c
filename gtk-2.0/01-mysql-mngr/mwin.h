
/*
 * mwin.h
 * dark_neo
 * 2014-06-13
 */

#ifndef MWIN_H
#define MWIN_H

#include <stdbool.h>
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
#include "mwin-conn.h"

#define MWIN_TITLE 	"MyMySQL Manager"
#define MWIN_WIDTH 	1024
#define MWIN_HEIGHT 	768

typedef struct _main_window {
	GtkWidget 	*win;		/* the window		*/
	GSList		*windows;	/* child windows	*/
	GtkWidget	*vbox;		/* store elements vertically */
	GtkWidget 	*mnu_bar;	/* a menu bar		*/
	GtkWidget	*fmnu;		/* file menu		*/
	GtkWidget	*fsub_mnu;	/* file sub-menu	*/
	GtkAccelGroup	*fm_accel;	/* file sub-menu keyboard shortcuts */
	GtkWidget	*fmitem_cnn;	/* connect 		*/
	GtkWidget	*fmitem_dcn;	/* disconnect 		*/
	GtkWidget	*fmitem_qut;	/* quit			*/

	GtkWidget	*emnu;		/* edit menu		*/
	GtkWidget	*esub_mnu;	/* edit sub-menu	*/
	GtkAccelGroup	*em_accel;	/* edit sub-menu keyboard shortcuts */
	GtkWidget	*emitem_cpy;	/* copy			*/
	GtkWidget	*emitem_cut;	/* cut			*/
	GtkWidget	*emitem_pst;	/* paste		*/
	GtkWidget	*emitem_sta;	/* select-all		*/

	GtkWidget	*hmnu;		/* help menu		*/
	GtkWidget	*hsub_mnu;	/* help sub-menu keyboard shortcuts */
	GtkAccelGroup	*hm_accel;	/* help 		*/
	GtkWidget	*hmitem_abt;	/* about		*/

	GtkWidget	*msep;		/* menu separator	*/
	GtkWidget	*statusbar;
	const char 	*statusbar_msg;
} main_window;

extern void create_mw(main_window *mw, int argc, char **argv);
extern void create_fmnu(main_window *mw);
extern void create_emnu(main_window *mw);
extern void create_hmnu(main_window *mw);
extern void create_mnubar(main_window *mw);
extern void create_statusbar(main_window *mw);
extern void on_quitwin(GtkWidget *widget, void *data);
extern void on_win_destroy(main_window *mw);
extern void on_fmitem_cnn_click(main_window *mw);

#endif /* MWIN_H */

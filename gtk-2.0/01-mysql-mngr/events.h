
/*
 * events.h
 * dark_neo
 * 2014-06-14
 */

/* Declared here all events used in this project. */

#ifndef EVENTS_H
#define EVENTS_H

#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

/*
 * Close the program.
 */
extern void on_quitwin(GtkWidget *widget, void *data);

/*
 * Close a child window.
 *
 * Params:
 * 	widget: the widget to be freed.
 *	parent: the parent of widget.
 *
 * No defined in 'events.c' file. Overridable for any implementation.
 */
extern void on_window_destroy(GtkWidget *widget, void *parent);

#endif /* EVENTS_H */


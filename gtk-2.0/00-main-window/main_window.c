
/*
 * main-window.c
 * dark_neo
 * 2014-06-08
 */

#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
	GtkWidget *window;

	gtk_init(&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "GTK+ App");
	gtk_widget_show(window);

	gtk_main();

	return 0;
}



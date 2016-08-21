
/*
 * main.c
 * dark_neo
 * 2014-06-13
 */

#include <gtk/gtk.h>
#include <my_global.h>
#include <mysql/mysql.h>
#include "mwin.h"

int main(int argc, char *argv[])
{
	main_window win;

	create_mw(&win, argc, argv); 

	return 0;
}


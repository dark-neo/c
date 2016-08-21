
/*
 * mysql_test.c
 * dark_neo
 * 2014-06-09
 */

/*
 * Connection to MySQL local server through C.
 */

#include <stdio.h>
#include <mysql/mysql.h>

int main(void)
{
	printf("\nMySQL client version: %s\n", mysql_get_client_info());

	return 0;
}


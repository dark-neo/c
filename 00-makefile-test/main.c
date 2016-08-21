
/*
 * main.c
 * dark_neo
 * 2014-06-06
 */

#include <stdio.h>
#include "person.h"

int main(void)
{
	person *pers = new_person("Name", "Surname", 101);

	pers->show_data(pers);

	delete_person(pers);
	
	return 0;
}


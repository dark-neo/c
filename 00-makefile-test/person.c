
/*
 * person.c
 * dark_neo
 * 2014-06-06
 */

#include <stdio.h>
#include <stdlib.h>
#include "person.h"

person *new_person(char *name, char *surname, unsigned int age)
{
	/* Create the person public object */
	person *pers = (person *) malloc(sizeof(person));
	if (pers == NULL) {
		fprintf(stderr, "\nError allocating memory for 'person'.");
		return NULL;
	}

	/* Create the private person object to access data. */
	pers->_priv = (_person *) malloc(sizeof(_person));
	if (pers->_priv == NULL) {
		fprintf(stderr, "\nError allocating memory for '_person'.");
		return NULL;
	}

	/* Copy the values into the private data. */
	pers->_priv->_name 		= name;
	pers->_priv->_surname 	= surname;
	pers->_priv->_age		= age;

	/* Assign to function_pointer the function. */
	pers->show_data = show_data;

	return pers;
}

void delete_person(person *self)
{
	/* Delete the private person object. */
	if (self->_priv != NULL) {
		free(self->_priv);
		self->_priv = NULL;
	}

	/* Delete the public person object. */
	if (self != NULL) {
		free(self);
		self = NULL;
	}
}

void show_data(struct _person_pub *self)
{
	printf("\tName: %s", self->_priv->_name);
	printf("\n\tSurname: %s", self->_priv->_surname);
	printf("\n\tAge: %d\n", self->_priv->_age);
}


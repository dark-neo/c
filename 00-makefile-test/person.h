
/*
 * person.h
 * dark_neo
 * 2014-06-06
 */

#ifndef PERSON_H
#define PERSON_H

typedef struct _person_priv {
	char 			*_name;
	char			*_surname;
	unsigned int	_age;
} _person;

typedef struct _person_pub {
	_person *_priv;

	void 	(* show_data)	(struct _person_pub *self);
} person;

extern person* 		new_person(char *name, char *surname, unsigned int age);
extern void			delete_person(person *self);
extern void			show_data(person *self);

#endif /* PERSON_H */

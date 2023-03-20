#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - initializesa variable of type struct dog
 * @d: pointer to struct dog to iniatialize
 * @name: name to iniatialize
 * @owner: owner to iniatialize
 */
void init_dof(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		d = malloc(sizeof(struct dog));
	d->name = name;
	d->age = age;
	d->owner = owner;
}

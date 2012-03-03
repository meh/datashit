/**
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *                    Version 2, December 2004
 *
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
 *
 *  0. You just DO WHAT THE FUCK YOU WANT TO.
 **/

#include <stdlib.h>

#include "datashit/Value.h"

static
void
DefaultDestroyer (DSValue* value)
{
	free(value->pointer);
}

DSValue*
ds_value (void* data)
{
	DSValue* result = malloc(sizeof(DSValue));

	result->pointer    = data;
	result->references = 0;
	result->protect    = false;
	result->destroyer  = DefaultDestroyer;

	return result;
}

DSValue*
ds_constant (void* data)
{
	return ds_value_destroyer(ds_value(data), NULL);
}

DSValue*
ds_value_protect (DSValue* value)
{
	value->protect = true;

	return value;
}

DSValue*
ds_value_unprotect (DSValue* value)
{
	value->protect = false;

	if (value->references <= 0) {
		return ds_value_dereference(value);
	}

	return value;
}

DSValue*
ds_value_reference (DSValue* value)
{
	value->references++;

	return value;
}

DSValue*
ds_value_dereference (DSValue* value)
{
	value->references--;

	if (!value->protect) {
		if (value->destroyer) {
			value->destroyer(value);
		}

		free(value);

		return NULL;
	}

	return value;
}

DSValue*
ds_value_destroyer (DSValue* value, DSValueDestroyer destroyer)
{
	value->destroyer = destroyer;

	return value;
}

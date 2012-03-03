#include <stdio.h>
#include <stdlib.h>
#include <datashit.h>

void
print_destroyer (DSValue* value)
{
	printf("destroying %p\n", ds_value_get(value));

	free(ds_value_get(value));
}

int
main (int argc, char** argv)
{
	DSValue* constant = ds_value_reference(ds_const(23));
	DSValue* value    = ds_value_reference(ds_value_destroyer(ds_value(malloc(sizeof(int))), print_destroyer));

	*(int*) ds_value_get(value) = 42;

	printf("constant contains %d\n", ds_value_get(constant));
	printf("constant has %d references\n", constant->references);

	printf("value contains %d\n", *(int*) ds_value_get(value));
	printf("value has %d references\n", value->references);

	ds_value_dereference(constant);
	ds_value_unprotect(ds_value_protect(value));

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <datashit.h>

DS_DEFINE_NEXTER_FOR_ARRAY_OF(int);

bool counter (int* data) {
	return *data % 2 == 0;
}

void print (int* data) {
	printf("hey, I've got a %d\n", *data);
}

int
main (int argc, char** argv)
{
	int             array[]  = { 1, 2, 3, 4, 5 };
	DSArrayMetadata metadata = DS_ARRAY_METADATA(sizeof(array) / sizeof(array[0]));

	printf("the array has %lu even elements\n", ds_count_array_of(int, array, &metadata, counter));

	ds_each_array_of(int, array, &metadata, print);

	return 0;
}

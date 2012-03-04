#include <stdio.h>
#include <datashit.h>

bool counter (DSValue** value) {
	return (int) ds_value_get(*value) % 2 != 0;
}

int
main (int argc, char** argv)
{
	DSList list  = ds_const_cons(1, ds_const_cons(2));
	DSList list2 = ds_const_list(1, 2, 3, 4, 5, 6);

	printf("the first list has %lu odd elements\n", ds_count_list(list, counter));
	printf("the second list has %lu odd elements\n", ds_count_list(list2, counter));

	ds_list_destroy(list);
	ds_list_destroy(list2);

	return 0;
}

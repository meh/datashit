/**
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *                    Version 2, December 2004
 *
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
 *
 *  0. You just DO WHAT THE FUCK YOU WANT TO.
 **/

#include "datashit/algorithms.h"

void*
ds_next (void* data, DSNexter nexter, void* metadata)
{
	return nexter(data, metadata);
}

size_t
ds_count_ (void* data, DSNexter nexter, void* metadata, DSCounter counter, void* metadata2)
{
	size_t result = 0;
	void*  current = data;

	do {
		if (counter == NULL || counter(current, metadata2)) {
			result++;
		}
	} while ((current = ds_next(current, nexter, metadata)));

	return result;
}

void*
ds_each_ (void* data, DSNexter nexter, void* metadata, DSYielder yielder, void* metadata2)
{
	void* current = data;

	do {
		yielder(current, metadata2);
	} while ((current = ds_next(current, nexter, metadata)));

	return data;
}

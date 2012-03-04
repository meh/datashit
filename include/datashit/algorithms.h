/**
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *                    Version 2, December 2004
 *
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
 *
 *  0. You just DO WHAT THE FUCK YOU WANT TO.
 **/

#include <datashit/common.h>

#ifndef _DATASHIT_ALGORITHMS_H
#define _DATASHIT_ALGORITHMS_H

typedef void* (*DSNexter)(void* data, void* metadata);
typedef bool (*DSCounter)(void* data, void* metadata);
typedef void (*DSYielder)();

extern void* ds_next (void* data, DSNexter nexter, void* metadata);

extern size_t ds_count_ (void* data, DSNexter nexter, void* metadata, DSCounter counter, void* metadata2);

#define ds_count(a, ...) ((ARGS_LENGTH(__VA_ARGS__) == 2) ? \
	ds_count_(a, (DSNexter) ARGS_FIRST(__VA_ARGS__), NULL, (DSCounter) ARGS_SECOND(__VA_ARGS__), NULL) : ((ARGS_LENGTH(__VA_ARGS__) == 3) ? \
	ds_count_(a, (DSNexter) ARGS_FIRST(__VA_ARGS__), (void*) ARGS_SECOND(__VA_ARGS__), (DSCounter) ARGS_THIRD(__VA_ARGS__), NULL) : \
	ds_count_(a, (DSNexter) ARGS_FIRST(__VA_ARGS__), (void*) ARGS_SECOND(__VA_ARGS__), (DSCounter) ARGS_THIRD(__VA_ARGS__), (void*) ARGS_FOURTH(__VA_ARGS__))))

extern void* ds_each_ (void* data, DSNexter nexter, void* metadata, DSYielder yielder, void* metadata2);

#define ds_each(a, ...) ((ARGS_LENGTH(__VA_ARGS__) == 2) ? \
	ds_each_(a, (DSNexter) ARGS_FIRST(__VA_ARGS__), NULL, (DSYielder) ARGS_SECOND(__VA_ARGS__), NULL) : ((ARGS_LENGTH(__VA_ARGS__) == 3) ? \
	ds_each_(a, (DSNexter) ARGS_FIRST(__VA_ARGS__), (void*) ARGS_SECOND(__VA_ARGS__), (DSYielder) ARGS_THIRD(__VA_ARGS__), NULL) : \
	ds_each_(a, (DSNexter) ARGS_FIRST(__VA_ARGS__), (void*) ARGS_SECOND(__VA_ARGS__), (DSYielder) ARGS_THIRD(__VA_ARGS__), (void*) ARGS_FOURTH(__VA_ARGS__))))

#endif

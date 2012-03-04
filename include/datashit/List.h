/**
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *                    Version 2, December 2004
 *
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
 *
 *  0. You just DO WHAT THE FUCK YOU WANT TO.
 **/

#ifndef _DATASHIT_LIST_H
#define _DATASHIT_LIST_H

#include <datashit/common.h>

typedef struct DSListNode {
	DSValue* value;

	struct DSListNode* next;
} DSListNode;

typedef DSListNode* DSList;

#define ds_cons(...) ((ARGS_LENGTH(__VA_ARGS__) == 1) ? \
	ds_cons_((void*) ARGS_FIRST(__VA_ARGS__), NULL) : \
	ds_cons_((void*) ARGS_FIRST(__VA_ARGS__), ARGS_SECOND(__VA_ARGS__)))

#define ds_list(...) ds_list_(ARGS_LENGTH(__VA_ARGS__), __VA_ARGS__)

extern DSListNode* ds_cons_ (void* value, DSListNode* data);

extern DSListNode* ds_list_ (size_t length, ...);

#define ds_const_cons(...) ((ARGS_LENGTH(__VA_ARGS__) == 1) ? \
	ds_const_cons_((void*) ARGS_FIRST(__VA_ARGS__), NULL) : \
	ds_const_cons_((void*) ARGS_FIRST(__VA_ARGS__), ARGS_SECOND(__VA_ARGS__)))

#define ds_const_list(...) ds_const_list_(ARGS_LENGTH(__VA_ARGS__), __VA_ARGS__)

extern DSListNode* ds_const_cons_ (void* value, DSListNode* data);

extern DSListNode* ds_const_list_ (size_t length, ...);

extern DSListNode* ds_list_copy (DSListNode* data);

extern void ds_list_destroy (DSListNode* data);

extern void*       ds_car (DSListNode* data);
extern DSListNode* ds_cdr (DSListNode* data);

#define ds_head(...) ds_car(__VA_ARGS__)
#define ds_tail(...) ds_cdr(__VA_ARGS__)

extern DSListNode* ds_append (void* value, DSListNode* data);

extern DSListNode* ds_const_append (void* value, DSListNode* data);

extern void* ds_pop (DSListNode* data, void* value);

extern DSListNode* ds_list_nexter (DSListNode* current);

#define ds_count_list(list, counter...) \
	ds_count(list, ds_list_nexter, NULL, ARGS_FIRST(counter), ARGS_SECOND(counter))

#endif

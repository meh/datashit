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

#include <stdbool.h>

#include <datashit/Value.h>

typedef struct DSListNode {
	DSValue* value;

	struct DSListNode* next;
} DSListNode;

typedef DSListNode* List;

#define CONS(a, b) ((void*) a, b)

extern DSListNode* ds_cons (void* value, DSListNode* data);

extern void*     ds_car (DSListNode* data);
extern DSListNode* ds_cdr (DSListNode* data);

extern void*     ds_head (DSListNode* data);
extern DSListNode* ds_tail (DSListNode* data);

extern void* ds_pop (DSListNode* data, void* value);

#endif

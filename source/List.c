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
#include "datashit/List.h"

DSListNode*
cons (void* value, DSListNode* data)
{
	DSListNode* head = malloc(sizeof(DSListNode));

	head->value = ds_value(value);
	head->next  = data;

	return head;
}

void*
car (DSListNode* data)
{
	if (data == NULL) {
		return NULL;
	}

	return data->value;
}

DSListNode*
cdr (DSListNode* data)
{
	if (data == NULL) {
		return NULL;
	}

	return data->next;
}


void* head (DSListNode* data) __attribute__((alias("car")));

DSListNode* tail (DSListNode* data) __attribute__((alias("cdr")));

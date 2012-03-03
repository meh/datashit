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

ListNode*
cons (void* value, ListNode* data)
{
	ListNode* head = malloc(sizeof(ListNode));

	head->value = ds_value(value);
	head->next  = data;

	return head;
}

void*
car (ListNode* data)
{
	if (data == NULL) {
		return NULL;
	}

	return data->value;
}

ListNode*
cdr (ListNode* data)
{
	if (data == NULL) {
		return NULL;
	}

	return data->next;
}


void* head (ListNode* data) __attribute__((alias("car")));

ListNode* tail (ListNode* data) __attribute__((alias("cdr")));

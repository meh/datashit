/**
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *                    Version 2, December 2004
 *
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
 *
 *  0. You just DO WHAT THE FUCK YOU WANT TO.
 **/

#include "datashit/List.h"

DSListNode*
ds_cons_ (void* value, DSListNode* data)
{
	DSListNode* head = malloc(sizeof(DSListNode));

	head->value = ds_value_reference(ds_value(value));
	head->next  = data;

	return head;
}

DSListNode*
ds_list_ (size_t length, ...)
{
	va_list args;
	DSList  result = NULL;

	va_start(args, length);
	for (size_t i = 0; i < length; i++) {
		result = ds_append(va_arg(args, void*), result);
	}
	va_end(args);

	return result;
}

DSListNode*
ds_const_cons_ (void* value, DSListNode* data)
{
	DSListNode* head = malloc(sizeof(DSListNode));

	head->value = ds_value_reference(ds_const(value));
	head->next  = data;

	return head;
}

DSListNode*
ds_const_list_ (size_t length, ...)
{
	va_list args;
	DSList  result = NULL;

	va_start(args, length);
	for (size_t i = 0; i < length; i++) {
		result = ds_const_append(va_arg(args, void*), result);
	}
	va_end(args);

	return result;
}

DSListNode*
ds_list_copy (DSListNode* data)
{
	DSListNode* result  = NULL;
	DSListNode* current = data->next;
	DSListNode* tmp     = NULL;
	DSListNode* tail    = NULL;

	result        = malloc(sizeof(DSListNode));
	result->value = ds_value_reference(data->value);
	result->next  = NULL;

	tail = result;

	while (current) {
		tmp = malloc(sizeof(DSListNode));

		tmp->value = ds_value_reference(current->value);
		tmp->next  = NULL;

		tail->next = tmp;
		tail       = tmp;
		
		current = current->next;
	}

	return result;
}

void
ds_list_destroy (DSListNode* data)
{
	DSListNode* current  = data;
	DSListNode* previous = NULL;

	while (current) {
		ds_value_dereference(current->value);

		previous = current;
		current  = current->next;

		free(previous);
	}
}

void*
ds_car (DSListNode* data)
{
	if (data == NULL) {
		return NULL;
	}

	ds_value_reference(data->value);

	return data->value;
}

DSListNode*
ds_cdr (DSListNode* data)
{
	if (data == NULL) {
		return NULL;
	}

	return data->next;
}

DSListNode*
ds_append (void* value, DSListNode* data)
{
	DSListNode* current = data;

	if (data == NULL) {
		return ds_cons(value);
	}

	while (current->next) {
		current = current->next;
	}

	current->next = ds_cons(value);

	return data;
}

DSListNode*
ds_const_append (void* value, DSListNode* data)
{
	DSListNode* current = data;

	if (data == NULL) {
		return ds_const_cons(value);
	}

	while (current->next) {
		current = current->next;
	}

	current->next = ds_const_cons(value);

	return data;
}


DSListNode*
ds_list_nexter (DSListNode* current)
{
	return current->next;
}

/**
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *                    Version 2, December 2004
 *
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
 *
 *  0. You just DO WHAT THE FUCK YOU WANT TO.
 **/

#ifndef _DATASHIT_VALUE_H
#define _DATASHIT_VALUE_H

#include <stdbool.h>

struct DSValue;

typedef void (*DSValueDestroyer) (struct DSValue* value);

typedef struct DSValue {
	void* pointer;

	size_t         references;
	bool           protect;
	DSValueDestroyer destroyer;
} DSValue;

extern DSValue* ds_value (void* data);
extern DSValue* ds_constant (void* data);
extern DSValue* ds_value_protect (DSValue* value);
extern DSValue* ds_value_unprotect (DSValue* value);
extern DSValue* ds_value_reference (DSValue* value);
extern DSValue* ds_value_dereference (DSValue* value);
extern DSValue* ds_value_destroyer (DSValue* value, DSValueDestroyer destroyer);

#define ds_const(x) ds_constant((void*) x)

#define ds_value_get(v) (v->pointer)

static inline DSValue* ds_value_set_ (DSValue* v, void* x) { v->pointer = x; return v; }
#define ds_value_set(v, x) (ds_value_set_(v, (void*) x))

#endif

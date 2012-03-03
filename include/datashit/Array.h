/**
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *                    Version 2, December 2004
 *
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
 *
 *  0. You just DO WHAT THE FUCK YOU WANT TO.
 **/

#ifndef _DATASHIT_ARRAY_H
#define _DATASHIT_ARRAY_H

typedef struct DSArrayMetadata {
	size_t current;
	size_t length;
} DSArrayMetadata;

#define DS_ARRAY_METADATA(size) { 0, (size) }
#define DS_ARRAY_METADATA_RESET(p) (ds_array_metadata_reset_(p))

static inline DSArrayMetadata* ds_array_metadata_reset_ (DSArrayMetadata* metadata)
{
	metadata->current = 0;

	return metadata;
}

#define DS_DEFINE_NEXTER_FOR_ARRAY_OF(type)                     \
	type*                                                         \
	_ds_next_for_## type (type* array, DSArrayMetadata* metadata) \
	{                                                             \
		if (metadata->current >= metadata->length - 1) {            \
			return NULL;                                              \
		}                                                           \
                                                                \
		metadata->current++;                                        \
                                                                \
		return array + 1;                                           \
	}

#define DS_NEXTER_FOR_ARRAY_OF(type) _ds_next_for_ ## type

#endif

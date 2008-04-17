/* apk_hash.h - Alpine Package Keeper (APK)
 *
 * Copyright (C) 2005-2008 Natanael Copa <n@tanael.org>
 * Copyright (C) 2008 Timo Teräs <timo.teras@iki.fi>
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it 
 * under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation. See http://www.gnu.org/ for details.
 */

#ifndef APK_HASH_H
#define APK_HASH_H

#include <malloc.h>
#include "apk_defines.h"

typedef void *apk_hash_item;
typedef const void *apk_hash_key;

typedef unsigned long (*apk_hash_f)(apk_hash_key);
typedef int (*apk_hash_compare_f)(apk_hash_key, apk_hash_key);
typedef void (*apk_hash_delete_f)(apk_hash_item);
typedef int (*apk_hash_enumerator_f)(apk_hash_item, void *ctx);

struct apk_hash_ops {
	ptrdiff_t	node_offset;
	apk_hash_key	(*get_key)(apk_hash_item item);
	unsigned long	(*hash_key)(apk_hash_key key);
	int		(*compare)(apk_hash_key key, apk_hash_key item);
	void		(*delete_item)(apk_hash_item item);
};

typedef struct hlist_node apk_hash_node;
APK_ARRAY(apk_hash_array, struct hlist_head);

struct apk_hash {
	const struct apk_hash_ops *ops;
	struct apk_hash_array *buckets;
	int num_items;
};

unsigned long apk_hash_string(const char *string);
unsigned long apk_hash_csum(const void *);

void apk_hash_init(struct apk_hash *h, const struct apk_hash_ops *ops,
		   int num_buckets);
void apk_hash_free(struct apk_hash *h);

int apk_hash_foreach(struct apk_hash *h, apk_hash_enumerator_f e, void *ctx);
apk_hash_item apk_hash_get(struct apk_hash *h, apk_hash_key key);
void apk_hash_insert(struct apk_hash *h, apk_hash_item item);
void apk_hash_delete(struct apk_hash *h, apk_hash_key key);

#endif

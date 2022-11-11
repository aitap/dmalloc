/*
 * defines for the system specific memory routines
 *
 * Copyright 2020 by Gray Watson
 *
 * This file is part of the dmalloc package.
 *
 * Permission to use, copy, modify, and distribute this software for
 * any purpose and without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies, and that the name of Gray Watson not be used in advertising
 * or publicity pertaining to distribution of the document or software
 * without specific, written prior permission.
 *
 * Gray Watson makes no representations about the suitability of the
 * software described herein for any purpose.  It is provided "as is"
 * without express or implied warranty.
 *
 * The author may be contacted via https://dmalloc.com/
 */

#ifndef __HEAP_H__
#define __HEAP_H__

#include "dmalloc_loc.h"			/* for LOCAL and BLOCK_SIZE */

/*
 * error code returned by heap allocation routine
 */
#define HEAP_ALLOC_ERROR	0L

/* test whether pointer PNT is in the heap space */
#define IS_IN_HEAP(pnt)		\
  ((char *)(pnt) >= (char *)_dmalloc_heap_low \
   && (char *)(pnt) < (char *)_dmalloc_heap_high)

/*<<<<<<<<<<  The below prototypes are auto-generated by fillproto */

extern
void		*_dmalloc_heap_low;	/* base of our heap */

extern
void		*_dmalloc_heap_high;	/* end of our heap */

/*
 * int _heap_startup
 *
 * Initialize heap pointers.
 *
 * Returns 1 on success or 0 on failure.
 */
extern
int	_dmalloc_heap_startup(void);

/*
 * void *_dmalloc_heap_alloc
 *
 * Function to get memory bytes from the heap.
 *
 * Returns a valid pointer on success or NULL on failure.
 *
 * ARGUMENTS:
 *
 * size -> Number of bytes we need.
 */
extern
void	*_dmalloc_heap_alloc(const unsigned int size);

/*<<<<<<<<<<   This is end of the auto-generated output from fillproto. */

#endif /* ! __HEAP_H__ */

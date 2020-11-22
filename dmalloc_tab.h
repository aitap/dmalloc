/*
 * Local defines for the memory table.
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
 * The author may be contacted via http://dmalloc.com/
 */

#ifndef __DMALLOC_TAB_H__
#define __DMALLOC_TAB_H__

/* entry in a memory table */
typedef struct mem_entry_st {
  const char		*me_file;		/* filename of alloc or ra */
  unsigned int		me_line;		/* line number of alloc */
  unsigned long		me_total_size;		/* size bytes alloced */
  unsigned long		me_total_c;		/* total pointers allocated */
  unsigned long		me_in_use_size;		/* size currently alloced */
  unsigned long		me_in_use_c;		/* pointers currently in use */
  /* we use this so we can easily un-sort the list */
  struct mem_entry_st	*me_entry_pos_p;	/* pos of entry in table */
} mem_entry_t;

/* memory table */
typedef struct {
  mem_entry_t		*mt_entries;		/* our entries */
  mem_entry_t		*mt_bounds_p;		/* past the end of entries */
  int			mt_entry_n;		/* number entries in list */
  int			mt_in_use_c;		/* in use counter */
  mem_entry_t		mt_other_pointers;	/* other pointer info */
} mem_table_t;

/*<<<<<<<<<<  The below prototypes are auto-generated by fillproto */

/*
 * void _dmalloc_table_init
 *
 * DESCRIPTION:
 *
 * Clear out the allocation information in our table.  We are going to
 * be loading it with other info.
 *
 * RETURNS:
 *
 * None.
 *
 * ARGUMENTS:
 *
 * mem_table -> Memory table we are working on.
 *
 * mem_entries -> Entries to associate with the table.
 *
 * entry_n -> Number of entries in the mem_entries array.
 */
extern
void	_dmalloc_table_init(mem_table_t *mem_table, mem_entry_t *mem_entries,
			    const int entry_n);

/*
 * void _dmalloc_table_insert
 *
 * DESCRIPTION:
 *
 * Insert a pointer to the table.
 *
 * RETURNS:
 *
 * None.
 *
 * ARGUMENTS:
 *
 * mem_table -> Memory table we are working on.
 *
 * file -> File name or return address of the allocation.
 *
 * line -> Line number of the allocation.
 *
 * size -> Size in bytes of the allocation.
 */
extern
void	_dmalloc_table_insert(mem_table_t *mem_table,
			      const char *file, const unsigned int line,
			      const unsigned long size);

/*
 * void _dmalloc_table_delete
 *
 * DESCRIPTION:
 *
 * Remove a pointer from the table.
 *
 * RETURNS:
 *
 * None.
 *
 * ARGUMENTS:
 *
 * mem_table -> Memory table we are working on.
 *
 * old_file -> File name or return address of the allocation to
 * delete.
 *
 * old_line -> Line number of the allocation to delete.
 *
 * size -> Size in bytes of the allocation.
 */
extern
void	_dmalloc_table_delete(mem_table_t *mem_table, const char *old_file,
			      const unsigned int old_line,
			      const DMALLOC_SIZE size);

/*
 * void _dmalloc_table_log_info
 *
 * DESCRIPTION:
 *
 * Log information from the memory table to the log file.
 *
 * RETURNS:
 *
 * None.
 *
 * ARGUMENTS:
 *
 * mem_table -> Memory table we are working on.
 *
 * log_n -> Number of entries to log to the file.  Set to 0 to
 * display all entries in the table.
 *
 * in_use_column_b -> Display the in-use numbers in a column.
 */
extern
void	_dmalloc_table_log_info(mem_table_t *mem_table, const int log_n,
				const int in_use_column_b);

/*<<<<<<<<<<   This is end of the auto-generated output from fillproto. */

#endif /* ! __DMALLOC_TAB_H__ */

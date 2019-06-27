/*
** main.c for  in /Users/ouahab/Documents/master/malloc/amarou_o
**
** Made by AMAROUCHE Ouahab
** Login   <amarou_o@etna-alternance.net>
**
** Started on  Wed Jan 16 16:38:05 2019 AMAROUCHE Ouahab
** Last update Wed Jan 16 16:45:16 2019 AMAROUCHE Ouahab
*/

#include "my_malloc.h"

t_block *position = NULL;
t_block *g_first_released = NULL;

void putBlock(t_block *blk, t_block *prev, t_block *next, uint size)
{
  blk->allocated = 1;
  blk->magic_number = 42;
  blk->size = size;
  blk->prev = prev;
  blk->next = next;
}

void split_freed_block(t_block *header, size_t size)
{
  t_block *newBlk;

  newBlk = (void *)header + size + BLOCK_SIZE;
  putBlock(newBlk, header, header->next, 0);
  newBlk->size = header->size - size - BLOCK_SIZE;
  newBlk->allocated = 0;

  if (header->next != NULL)
  {
    header->next->prev = newBlk;
  }

  header->next = newBlk;
  header->size = size;

  if (header == g_first_released)
  {
    g_first_released = newBlk;
  }
}

void *use_released_block(size_t size)
{
  t_block *blk;
  blk = (t_block*)position;

  while (blk != NULL && position != sbrk(0))
  {
    if (blk->allocated == 0 && blk->size >= size)
    {
      if (blk->size >= size + 100)
      {
        split_freed_block(blk, size);
      }

      blk->allocated = 1;
      return ((void *) blk + BLOCK_SIZE);
    }

    blk = blk->next;
  }
  return (NULL);
}

void *move_memory(size_t size)
{
  void  *current = sbrk(BLOCK_SIZE + size);
  t_block *blk = current;
  putBlock(blk, last, NULL, size);

  if (last != NULL)
  {
    last->next = blk;
  }

  last = blk;
  return (((void *)blk) + BLOCK_SIZE );
}

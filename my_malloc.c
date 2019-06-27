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

void *malloc(size_t size)
{
  void *blk_return;

  if (position == NULL)
  {
      position = sbrk(0);
  }

  blk_return = use_released_block(size);
  
  if (blk_return != NULL)
  {
      return blk_return;
  }
  return move_memory(size);
}

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

void free(void *ptr) {
    t_block *header;

    header = (t_block *) ptr - 1;

    if (ptr == NULL || header->magic_number != 42 || header->allocated == 0) {
        return;
    }
    header->allocated = 0;
}

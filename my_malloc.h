/*
** main.c for  in /Users/ouahab/Documents/master/malloc/amarou_o
**
** Made by AMAROUCHE Ouahab
** Login   <amarou_o@etna-alternance.net>
**
** Started on  Wed Jan 16 16:38:05 2019 AMAROUCHE Ouahab
** Last update Wed Jan 16 16:45:16 2019 AMAROUCHE Ouahab
*/

#ifndef MY_MALLOC__H__
#define MY_MALLOC__H__

#include <sys/types.h>
#include <unistd.h>

#define BLOCK_SIZE sizeof(t_block)

typedef struct s_block {
    struct s_block *next;
    struct s_block *prev;
    int allocated;
    size_t size;
    char magic_number;
} t_block;

void *malloc(size_t size);

void putBlock(t_block *blk, t_block *prev, t_block *next, uint size);

void *use_released_block(size_t size);

void *move_memory(size_t size);

void free(void *ptr);

t_block *last;
t_block *position;
t_block *g_first_released;

#endif


#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>


extern char **for_instructions;
extern int count;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/** monty_functions.c **/
char **get_command_line(FILE *);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strdup(char *s);
int read_line(FILE *file, char *buffer, size_t max_length);

/** functions1.c **/
int execute_stack(char **, int, stack_t **);
char **tokenize_string(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);

/** monty_commands.c **/
void pull_command(stack_t **head, unsigned int line_number);
void pall_command(stack_t **head, unsigned int line_number);
void freer_list(stack_t *head);
void free_arr(char **instructions);
void token_check(char **tokens, int x);
#endif

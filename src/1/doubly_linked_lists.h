#ifndef SRC_DOUBLY_LINKED_LISTS_H_
#define SRC_DOUBLY_LINKED_LISTS_H_

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>


typedef struct node {
    char *name;
    int *grades;
    struct node *next;
    struct node *prev; 
} node_t;

typedef struct list {
    size_t size;
    node_t *head;
    node_t *tail; 
} list_t;

list_t *create_list();

node_t *search_node_name(list_t *list, char* name_key, int size);
node_t *search_node_grades(list_t *list, int* grades_key, int size);

void pop_back(list_t *list);
void pop_front(list_t *list);
void delete_list(list_t *list);
void delete_node(list_t *list, int position);
void print_list(list_t *list, int grades_size);
void push_back(list_t *list, char *name_new, int *grades_new, int name_size, int grades_size);
void push_front(list_t *list, char *name_new, int *grades_new, int name_size, int grades_size);

char *copy_names(char *name, int name_size);

int *copy_grades(int *grades, int grades_size);
int equal_node_name(node_t *node, char* name_key, int size);
int equal_node_grades(node_t *node, int* grades_key, int size);

#endif //  SRC_DOUBLY_LINKED_LISTS_H_


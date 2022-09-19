#include "doubly_linked_lists.h"


list_t* create_list() {
    list_t *tmp = (list_t*) malloc(sizeof(list_t));
    if (tmp == NULL) {
        printf("Error: Bad allocation!\n");
    } else {
        tmp->size = 0;
        tmp->head = tmp->tail = NULL;      
    }
 
    return tmp;
}


void delete_list(list_t *list) {
    if (list->head == NULL) {
        printf("Error: List is also freed!\n");
    }
    node_t *tmp = list->head;
    node_t *next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(list);
    list = NULL;
}

void push_back(list_t *list, char *name_new, int *grades_new) {
    node_t *tmp = (node_t*) malloc(sizeof(node_t));
    if (tmp == NULL) {
        printf("Error: Bad allocation!\n");
    } else {
        tmp->name = name_new, tmp->grades = grades_new;
        tmp->next = NULL, tmp->prev = list->tail;
        if (list->tail) {
            list->tail->next = tmp;
        }
        list->tail = tmp;

        if (list->head == NULL) {
            list->head = tmp;
        }
        list->size++;
    }
}

void pop_back(list_t *list) {
    if (list->tail == NULL) {
        printf("Error: List is also empty!\n");
    } else {
        node_t *tmp;
        tmp = list->tail;
        list->tail = list->tail->prev;
        if (list->tail) {
            list->tail->next = NULL;
        }

        if(tmp == list->head) {
            list->head = NULL;
        }
        free(tmp);
        list->size--;
    }
}

int main() {
    list_t* new_list = create_list();
    int *arr = (int*) malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++) {
        arr[i] = i + 1;
    }
    for (int i = 0; i < 10; i++) {
        push_back(new_list, "ABCDEF", arr);
        printf("%s\n\n", new_list->head->name);
        for (int j = 0; j < 10; j++) {
            if (j == 9) {
                printf("%d\n", new_list->head->grades[j]);
            } else {
                printf("%d ", new_list->head->grades[j]);
            }
        }
    }

}
#include "doubly_linked_lists.h"


list_t *create_list() {
    list_t *new_list = (list_t*)malloc(sizeof(list_t));
    if (new_list == NULL) {
        printf("Error: Bad allocation!\n");
    } else {
        new_list->head = new_list->tail = NULL;
        new_list->size = 0;
    }

    return new_list;
}

void delete_list(list_t *list) {
    if (list == NULL) {
        printf("Error: List is also freed!\n");
    } else {
        node_t *tmp = list->tail;
        while(list->head != NULL) {
            list->tail = list->tail->prev;
            free(tmp);
            tmp = list->tail;
        }
        free(list);
        list = NULL;
    }
}

char *copy_names(char *name, int name_size) {
    char* new_name = (char*)malloc(sizeof(char) * name_size);
    for (int i = 0; i < name_size; i++) {
        new_name[i] = name[i];
    }

    return new_name;
}

int *copy_grades(int *grades, int grades_size) {
    int* new_grades = (int*)malloc(sizeof(int) * grades_size);
    for (int i = 0; i < grades_size; i++) {
        new_grades[i] = grades[i];
    }

    return new_grades;
}

void push_back(list_t *list, char *name_new, int *grades_new, int name_size, int grades_size) {
    node_t *tmp = (node_t*)malloc(sizeof(node_t));
    if (tmp == NULL) {
        printf("Error: Bad allocation!\n");
    } else {
        tmp->name = copy_names(name_new, name_size);
        tmp->grades = copy_grades(grades_new, grades_size);
        tmp->next = NULL, tmp->prev = list->tail;
        if (list->head == NULL) {
            list->head = list->tail = tmp;
        } else {
            list->tail->next = tmp;
            list->tail = tmp;
        }
        list->size++;
    }
}

void push_front(list_t *list, char *name_new, int *grades_new, int name_size, int grades_size) {
    node_t *tmp = (node_t*)malloc(sizeof(node_t));
    if (tmp == NULL) {
        printf("Error: Bad allocation!\n");
    } else {
        tmp->name = copy_names(name_new, name_size);
        tmp->grades = copy_grades(grades_new, grades_size);
        tmp->next = list->head, tmp->prev = NULL;
        if (list->head == NULL) {
            list->head = list->tail = tmp;
        } else {
            list->head->prev = tmp;
            list->head = tmp;
        }
        list->size++;
    }
}

void pop_back(list_t *list) {
    if (list->head == NULL) {
        printf("Error: List is also empty!\n");
    } else {
        node_t *tmp = (node_t*)malloc(sizeof(node_t));
        if (tmp == NULL) {
            printf("Error: Bad allocation!\n");
        } else {
            tmp = list->tail;
            list->tail = list->tail->prev;
            if (list->tail) {
                list->tail->next = NULL;
            }
            if (tmp == list->head) {
                list->head = NULL;
            }
            free(tmp);
        }
        list->size--;
    }
}

void pop_front(list_t *list) {
    if (list->head == NULL) {
        printf("Error: List is also empty!\n");
    } else {
        node_t *tmp = (node_t*)malloc(sizeof(node_t));
        if (tmp == NULL) {
            printf("Error: Bad allocation!\n");
        } else {
            tmp = list->head;
            list->head = list->head->next;
            if (list->head) {
                list->head->prev = NULL;
            }
            if (tmp == list->tail) {
                list->tail = NULL;
            }
            free(tmp);
        }
        list->size--;
    }
}

void print_list(list_t *list, int grades_size) {
    if (list == NULL) {
        printf("List is empty!\n");
    } else {
        node_t *p = list->head;
        int count = 0;
        while(p != NULL) {
            printf("%s\n", p->name);
            for (int i = 0; i < grades_size; i++) {
                if (i == grades_size - 1) {
                    printf("%d\n", p->grades[i]);
                } else {
                    printf("%d ", p->grades[i]);
                }
            }
            p = p->next;
            count++;
        }
    }
}

void delete_node(list_t *list, int position) {
	if (position < 0 || !list->head) {
        printf("Error: List is also empty ot position below nil");
	} else {
        int current_item_index = 0;
        node_t *tmp = list->head;
        for (int i = 0; tmp != NULL && i < position; i++) {
            tmp = tmp->next;
        }
        if (tmp == NULL) {
            printf("Error: Go out from size!\n");
        } else {
            if (list->head == tmp) {
                list->head = tmp->next;
            }
        
            if (tmp->next != NULL) {
                tmp->next->prev = tmp->prev;
            }
        
            if (tmp->prev != NULL) {
                tmp->prev->next = tmp->next;
            }   
            free(tmp);
        }
    }
}

int main() {
    list_t *list = create_list();
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int count = 0;
    printf("!!! PART I: PUSH BACK\n");
    for (int i = 0; i < 10; i++) {
        push_back(list, "ABCDE", arr, 5, 10);
        printf("\n");
        print_list(list, 10);
        printf("\n");
        for (int j = 0; j < 10; j++) {
            arr[j] = count + i;
            count++;
        }
    }  

    printf("!!! PART II: POP BACK\n");
    for (int i = 0; i < 10; i++) {
        pop_back(list);
        printf("\n");
        print_list(list, 10);
        printf("\n");
    }

    printf("!!! PART III: PUSH FRONT\n");
    for (int i = 0; i < 10; i++) {
        push_front(list, "ABCDE", arr, 5, 10);
        printf("\n");
        print_list(list, 10);
        printf("\n");
        for (int j = 0; j < 10; j++) {
            arr[j] = count + i;
            count++;
        }
    }  

    printf("!!! PART IV: POP FRONT\n");
    for (int i = 0; i < 10; i++) {
        pop_front(list);
        printf("\n");
        print_list(list, 10);
        printf("\n");
    }   

    printf("!!! PART V: DELETE ELEMENT\n");
    count = 0;
    for (int i = 0; i < 10; i++) {
        push_back(list, "ABCDE", arr, 5, 10);
        for (int j = 0; j < 10; j++) {
            arr[j] = count + i;
            count++;
        }
    }
    print_list(list, 10);
    printf("\n");
    delete_node(list, 4);
    printf("\n");
    print_list(list, 10);
    return 0;
}
#include "doubly_linked_lists.h"

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
    printf("\n");

    printf("!!! PART VI: GET ELEMENT\n");
    printf("%s\n", get_node_from_index(list, 5)->name);
    printf("\n");

    int arr_new[10] = {44, 45, 46, 47, 48, 49, 50, 51, 52, 53};
    node_t *new_node = search_node_grades(list, arr_new, 10);
    for (int i = 0; i < 10; i++) {
        if (i == 10 - 1) {
            printf("%d\n", new_node->grades[i]);
        } else {
            printf("%d ", new_node->grades[i]);
        }
    }

    printf("PART VII: SERIALIZE\n");
    serialize(list);
    printf("PART VIII: DESERIALIZE\n");
    print_list(list, 10);

    return 0;
}

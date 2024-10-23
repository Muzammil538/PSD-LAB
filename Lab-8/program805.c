#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void removeDuplicates(struct Node* head) {
    int hash[1000] = {0};
    struct Node* prev = NULL;
    struct Node* current = head;

    while (current) {
        if (hash[current->data]) {
            prev->next = current->next;
            free(current);
        } else {
            hash[current->data] = 1;
            prev = current;
        }
        current = current->next;
    }
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    push(&head, 11);
    push(&head, 10);
    push(&head, 12);
    push(&head, 11);
    push(&head, 12);
    push(&head, 10);

    printf("Original List:\n");
    printList(head);

    removeDuplicates(head);

    printf("List after removing duplicates:\n");
    printList(head);

    return 0;
}
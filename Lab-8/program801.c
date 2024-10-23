#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void reverseList(struct Node** head) {
    struct Node *prev = NULL, *current = *head, *next;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void push(struct Node** head, int data) {
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void printList(struct Node* head) {
    for (struct Node* temp = head; temp; temp = temp->next)
        printf("%d ", temp->data);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    for (int i = 5; i > 0; --i) push(&head, i);
    printf("Original Linked List:\n");
    printList(head);
    reverseList(&head);
    printf("Reversed Linked List:\n");
    printList(head);
    return 0;
}
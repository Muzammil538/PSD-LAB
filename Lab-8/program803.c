#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* merge(struct Node* a, struct Node* b) {
    struct Node dummy, *tail = &dummy; 
    dummy.next = NULL;

    while (a && b) {
        if (a->data <= b->data) {
            tail->next = a; a = a->next;
        } else {
            tail->next = b; b = b->next;
        }
        tail = tail->next;
    }
    tail->next = a ? a : b;
    return dummy.next;
}

void push(struct Node** head, int data) {
    struct Node* new_node = malloc(sizeof(*new_node));
    new_node->data = data; new_node->next = *head; *head = new_node;
}

void print(struct Node* head) {
    for (struct Node* temp = head; temp; temp = temp->next) 
        printf("%d ", temp->data);
    printf("\n");
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    push(&list1, 5); push(&list1, 3); push(&list1, 1);
    push(&list2, 6); push(&list2, 4); push(&list2, 2);

    printf("List 1:\n"); print(list1);
    printf("List 2:\n"); print(list2);
    printf("Merged List:\n"); print(merge(list1, list2));

    return 0;
}
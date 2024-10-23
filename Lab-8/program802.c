#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* detectLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return slow;
    }
    return NULL;
}

struct Node* findLoopStart(struct Node* head) {
    struct Node* meet = detectLoop(head);
    if (!meet) return NULL;
    struct Node *start = head;
    while (start != meet) {
        start = start->next;
        meet = meet->next;
    }
    return start;
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

int main() {
    struct Node* head = NULL;
    for (int i = 5; i >= 1; i--) push(&head, i);
    head->next->next->next->next->next = head->next->next; // Create loop
    struct Node* loopStart = findLoopStart(head);
    printf(loopStart ? "Loop detected at node with data: %d\n" : "No loop detected.\n", loopStart ? loopStart->data : 0);
    return 0;
}
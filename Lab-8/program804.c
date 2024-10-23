#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int getListLength(struct Node* head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

struct Node* getIntersectionNode(struct Node* head1, struct Node* head2) {
    int len1 = getListLength(head1), len2 = getListLength(head2), diff = abs(len1 - len2);
    struct Node* longer = len1 > len2 ? head1 : head2;
    struct Node* shorter = len1 > len2 ? head2 : head1;

    while (diff--) longer = longer->next;
    while (longer && shorter) {
        if (longer == shorter) return longer;
        longer = longer->next;
        shorter = shorter->next;
    }
    return NULL;
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

int main() {
    struct Node* head1 = NULL, *head2 = NULL;
    push(&head1, 30); push(&head1, 15); push(&head1, 9); push(&head1, 6); push(&head1, 3);
    push(&head2, 30); push(&head2, 15); push(&head2, 10);
    
    struct Node* intersectionNode = getIntersectionNode(head1, head2);
    printf(intersectionNode ? "Intersection at node with data: %d\n" : "No intersection found.\n", intersectionNode ? intersectionNode->data : 0);
    
    return 0;
}
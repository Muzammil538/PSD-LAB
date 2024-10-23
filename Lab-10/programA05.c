#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

void enqueue(Queue *q, int x) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue *q) {
    if (q->front == NULL) {
        return -1; // Queue is empty
    }
    int data = q->front->data;
    Node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

void interleave(Queue *q1, Queue *q2, Queue *result) {
    while (q1->front != NULL && q2->front != NULL) {
        enqueue(result, dequeue(q1));
        enqueue(result, dequeue(q2));
    }
    while (q1->front != NULL) {
        enqueue(result, dequeue(q1));
    }
    while (q2->front != NULL) {
        enqueue(result, dequeue(q2));
    }
}

void display(Queue *q) {
    Node *temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue q1, q2, result;
    q1.front = q1.rear = NULL;
    q2.front = q2.rear = NULL;
    result.front = result.rear = NULL;

    // Enqueue elements into q1 and q2
    enqueue(&q1, 1);
    enqueue(&q1, 3);
    enqueue(&q1, 5);
    enqueue(&q2, 2);
    enqueue(&q2, 4);
    enqueue(&q2, 6);

    interleave(&q1, &q2, &result);

    printf("Interleaved queue: ");
    display(&result);

    return 0;
}
#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

int isFull() {
    return (front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1));
}

int isEmpty() {
    return front == -1;
}

void enqueue(int val) {
    if (isFull()) return;
    if (front == -1) front = rear = 0;
    else if (rear == MAX - 1 && front != 0) rear = 0;
    else rear++;
    queue[rear] = val;
}

int dequeue() {
    if (isEmpty()) return -1;
    int val = queue[front];
    if (front == rear) front = rear = -1;
    else if (front == MAX - 1) front = 0;
    else front++;
    return val;
}

void display() {
    if (isEmpty()) return;
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    enqueue(10); enqueue(20); enqueue(30); enqueue(40); enqueue(50);
    display();        // Output: 10 20 30 40 50
    dequeue(); dequeue();
    enqueue(60); enqueue(70);
    display();        // Output: 30 40 50 60 70
    return 0;
}

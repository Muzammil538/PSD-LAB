#include <stdio.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int val) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = val;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// Function to reverse the queue using recursion
void reverseQueue() {
    if (front > rear) return;
    int val = dequeue();
    reverseQueue();
    queue[--front] = val;  // Re-insert at the front
}

// Function to display the queue
void display() {
    for (int i = front; i <= rear; i++) printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    enqueue(10); enqueue(20); enqueue(30); enqueue(40); enqueue(50);
    printf("Original Queue: ");
    display();   // Output: 10 20 30 40 50

    reverseQueue();
    
    printf("Reversed Queue: ");
    display();   // Output: 50 40 30 20 10
    return 0;
}

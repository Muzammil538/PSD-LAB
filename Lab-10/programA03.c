#include <stdio.h>
#define MAX 100

struct Item {
    int value;
    int priority;
};

struct Item queue[MAX];
int size = 0;

void enqueue(int value, int priority) {
    if (size == MAX) return;
    queue[size].value = value;
    queue[size].priority = priority;
    size++;
}

int dequeue() {
    if (size == 0) return -1;
    int highest = 0;
    for (int i = 1; i < size; i++) {
        if (queue[i].priority < queue[highest].priority)
            highest = i;
    }
    int val = queue[highest].value;
    for (int i = highest; i < size - 1; i++) 
        queue[i] = queue[i + 1];
    size--;
    return val;
}

void display() {
    for (int i = 0; i < size; i++)
        printf("Value: %d, Priority: %d\n", queue[i].value, queue[i].priority);
}

int main() {
    enqueue(10, 2); enqueue(20, 1); enqueue(30, 3);
    display();          // Outputs: 10 (P:2), 20 (P:1), 30 (P:3)
    printf("Dequeued: %d\n", dequeue());  // Output: 20
    display();          // Outputs: 10 (P:2), 30 (P:3)
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent the double-ended queue (deque)
struct Deque {
    int data[MAX_SIZE];
    int front, rear;
};

// Function to initialize an empty deque
void initialize(struct Deque *deque) {
    deque->front = -1;
    deque->rear = -1;
}

// Function to check if the deque is empty
int isEmpty(struct Deque *deque) {
    return (deque->front == -1 && deque->rear == -1);
}

// Function to check if the deque is full
int isFull(struct Deque *deque) {
    return ((deque->rear + 1) % MAX_SIZE == deque->front);
}

// Function to insert an element at the front of the deque
void insertFront(struct Deque *deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert at the front.\n");
    } else {
        if (isEmpty(deque)) {
            deque->front = deque->rear = 0;
        } else {
            deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
        }
        deque->data[deque->front] = value;
        printf("%d inserted at the front of the deque.\n", value);
    }
}

// Function to insert an element at the rear of the deque
void insertRear(struct Deque *deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert at the rear.\n");
    } else {
        if (isEmpty(deque)) {
            deque->front = deque->rear = 0;
        } else {
            deque->rear = (deque->rear + 1) % MAX_SIZE;
        }
        deque->data[deque->rear] = value;
        printf("%d inserted at the rear of the deque.\n", value);
    }
}

// Function to remove an element from the front of the deque
int removeFront(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot remove from the front.\n");
        return -1; // Return a sentinel value to indicate an error
    } else {
        int value = deque->data[deque->front];
        if (deque->front == deque->rear) {
            // Deque has only one element, reset it to empty
            deque->front = deque->rear = -1;
        } else {
            deque->front = (deque->front + 1) % MAX_SIZE;
        }
        return value;
    }
}

// Function to remove an element from the rear of the deque
int removeRear(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot remove from the rear.\n");
        return -1; // Return a sentinel value to indicate an error
    } else {
        int value = deque->data[deque->rear];
        if (deque->front == deque->rear) {
            // Deque has only one element, reset it to empty
            deque->front = deque->rear = -1;
        } else {
            deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
        }
        return value;
    }
}

// Function to display the elements of the deque
void display(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
    } else {
        printf("Deque elements: ");
        int i = deque->front;
        while (1) {
            printf("%d ", deque->data[i]);
            if (i == deque->rear) break;
            i = (i + 1) % MAX_SIZE;
        }
        printf("\n");
    }
}

int main() {
    struct Deque deque;
    initialize(&deque);

    insertFront(&deque, 10);
    insertRear(&deque, 20);
    insertFront(&deque, 30);

    display(&deque);

    int removedFront = removeFront(&deque);
    if (removedFront != -1) {
        printf("Removed element from the front: %d\n", removedFront);
    }

    int removedRear = removeRear(&deque);
    if (removedRear != -1) {
        printf("Removed element from the rear: %d\n", removedRear);
    }

    display(&deque);

    return 0;
}

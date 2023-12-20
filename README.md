# Simple-Queue-Implementation-in-C
This is a basic implementation of a queue data structure in C.

## Table of Contents

- [Overview](#overview)
- [Functions](#functions)
- [Usage](#usage)
- [Sample Test](#sample-test)

## Overview

The code provides a simple implementation of a queue using a linked list. It includes basic queue operations such as enqueue, dequeue, print, size, and more.

## Functions

### Basic Operations

- `enqueue`: Adds an element to the end of the queue.
- `dequeue`: Removes the element from the front of the queue.
- `print_queue`: Prints the elements of the queue.

### Queue Information

- `size`: Returns the number of elements in the queue.
- `is_empty`: Checks if the queue is empty.

### Search and Manipulation

- `search_index`: Searches for the index of a specific element.
- `remove_from_queue`: Removes a specific element from the queue.
- `count`: Counts the occurrences of a specific element in the queue.

### Queue Management

- `destroy_queue`: Destroys the entire queue and frees up memory.
- `reverse`: Reverses the order of elements in the queue.
- `copy`: Creates a copy of the queue.

### Front and Rear Operations

- `front`: Returns the front element of the queue.
- `rear`: Returns the rear element of the queue.

## Usage

You can use this implementation by including the provided functions in your C program. Simply include the `queue.h` file in your code and use the functions as needed.

## Sample Test

You can use the following test as a starting point to verify the functionality of the implemented queue.

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

int main(void) {
    Queue* head = NULL;
    int choice;
    do {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Queue Size\n");
        printf("5. Is Queue Empty?\n");
        printf("6. Search Index\n");
        printf("7. Remove from Queue\n");
        printf("8. Count Occurrences\n");
        printf("9. Reverse Queue\n");
        printf("10. Copy Queue\n");
        printf("11. Front of Queue\n");
        printf("12. Rear of Queue\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int data;
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                head = enqueue(head, data);
                break;
            }
            case 2:
                head = dequeue(head);
                printf("Dequeued an element.\n");
                break;
            case 3:
                printf("Current Queue:\n");
                print_queue(head);
                break;
            case 4:
                printf("Queue Size: %d\n", size(head));
                break;
            case 5:
                printf("Is Queue Empty? %s\n", is_empty(head) ? "Yes" : "No");
                break;
            case 6: {
                int searchData;
                printf("Enter data to search: ");
                scanf("%d", &searchData);
                printf("Index of %d in Queue: %d\n", searchData, search_index(head, searchData));
                break;
            }
            case 7: {
                int removeData;
                printf("Enter data to remove: ");
                scanf("%d", &removeData);
                head = remove_from_queue(head, removeData);
                printf("Removed %d from Queue.\n", removeData);
                break;
            }
            case 8: {
                int countData;
                printf("Enter data to count occurrences: ");
                scanf("%d", &countData);
                printf("Occurrences of %d in Queue: %d\n", countData, count(head, countData));
                break;
            }
            case 9:
                head = reverse(head);
                printf("Reversed Queue.\n");
                break;
            case 10: {
                Queue* copyHead = copy(head);
                printf("Copied Queue:\n");
                print_queue(copyHead);
                break;
            }
            case 11:
                printf("Front of the Queue: %d\n", front(head));
                break;
            case 12:
                printf("Rear of the Queue: %d\n", rear(head));
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    destroy_queue(head);

    return 0;
}


/**
 * Simple Queue Lİbrary
 * @file queue.h
 * @author Enes Talha Keleş
 * @date Thursday 21th December, 2023
 */

#ifndef SIMPLE_QUEUE_H
#define SIMPLE_QUEUE_H


/**
 * @struct node
 * @brief Node structure for the queue.
 */
typedef struct queue_node {
    int data;
    struct queue_node* next;
} Queue;

/**
 * @brief Adds a new element to the end of the queue.
 *
 * @param head The head of the queue.
 * @param enqueue_data The data to be added to the queue.
 * @return The head of the updated queue.
 */
Queue* enqueue(Queue* head, int enqueue_data);

/**
 * @brief Removes the element from the front of the queue.
 *
 * @param head The head of the queue.
 * @return The head of the updated queue.
 */
Queue* dequeue(Queue *head);

/**
 * @brief Prints the elements of the queue.
 *
 * @param head The head of the queue.
 */
void print_queue(Queue *head);

/**
 * @brief Gets the size of the queue.
 *
 * @param head The head of the queue.
 * @return The size of the queue.
 */
int size(Queue *head);

/**
 * @brief Checks if the queue is empty.
 *
 * @param head The head of the queue.
 * @return True if the queue is empty, false otherwise.
 */
bool is_empty(Queue *head);

/**
 * @brief Searches for the index of a given data in the queue.
 *
 * @param head The head of the queue.
 * @param search_data The data to search for.
 * @return The index of the data if found, or -1 if not found.
 */
int search_index(Queue *head, int search_data);

/**
 * @brief Removes all occurrences of a specific data from the queue.
 *
 * @param head The head of the queue.
 * @param data_to_remove The data to be removed.
 * @return The head of the updated queue.
 */
Queue *remove_from_queue(Queue *head, int data_to_remove);

/**
 * @brief Counts the occurrences of a specific data in the queue.
 *
 * @param head The head of the queue.
 * @param data_to_count_occurrences The data to be counted.
 * @return The number of occurrences of the specified data.
 */
int count(Queue *head, int data_to_count_occurences);

/**
 * @brief Destroys the queue and frees the memory.
 *
 * @param head The head of the queue.
 */
void destroy_queue(Queue *head);

/**
 * @brief Reverses the elements of the queue.
 *
 * @param head The head of the queue.
 * @return The head of the reversed queue.
 */
Queue *reverse(Queue *head);

/**
 * @brief Creates a copy of the queue.
 *
 * @param head The head of the queue.
 * @return The head of the copied queue.
 */
Queue *copy(Queue *head);

/**
 * @brief Gets the front element of the queue.
 *
 * @param head The head of the queue.
 * @return The data of the front element.
 */
int front(Queue *head);

/**
 * @brief Gets the rear element of the queue.
 *
 * @param head The head of the queue.
 * @return The data of the rear element.
 */
int rear(Queue *head);

#endif 

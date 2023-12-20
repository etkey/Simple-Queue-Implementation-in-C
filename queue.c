#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"
#define INVALID_VALUE -1
#define EMPTY -2


void print_queue(Queue* head) {
    if (is_empty(head)){
		printf("The Queue is empty!\n");
		return;
	}
    Queue* current = head;
    int counter = 1;
    while (current != NULL) {
        printf("Queue number %d: %d \n", counter, current->data);
        counter++;
        current = current->next;
    }
}

Queue* enqueue(Queue* head, int enqueue_data) {
    Queue* enqueue = malloc(sizeof(Queue));
    enqueue->data = enqueue_data;
    enqueue->next = NULL; 
    if (is_empty(head)) return enqueue;
    Queue* current = head;
    while (current->next != NULL) current = current->next;
    current->next = enqueue;
    return head;
}

Queue* dequeue(Queue *head){
	if(is_empty(head)) return NULL;
	if(head->next == NULL){
		free(head);
		return NULL;
	}
	Queue *current = head;
	Queue *prev = NULL;
	while(current->next != NULL){
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	free(current);
	return head;
}
int size(Queue *head){
	if(is_empty(head)) return 0;
	int counter = 1;
	Queue *current = head;
	while(current->next != NULL){
		current = current->next;
		counter++;
	}
	return counter;
}

bool is_empty(Queue *head){
	if(head == NULL) return true;
	else return false;
}

int search_index(Queue *head, int search_data){
	if (is_empty(head)) return INVALID_VALUE;
	Queue *current = head;
	int counter = 1;
	while(current != NULL){
		if(current->data == search_data){
			return counter;
		}
		current = current->next;
		counter++;
	}
	return INVALID_VALUE;
}

Queue *remove_from_queue(Queue *head, int data_to_remove){
	if(is_empty(head)) return NULL;
	if(head->data == data_to_remove && head->next == NULL ){
		free(head);
		return NULL;
	}
	Queue *current = head;
	Queue *prev = NULL;
	if(head->data == data_to_remove){
		head = current->next;
		free(current);
		return head;
	}
	while(current != NULL){
		if(current->data == data_to_remove){
			prev->next = current->next;
			free(current);
			return head;
		}
		prev = current;
		current = current->next;
	}
	return head;
}

int count(Queue *head, int data_to_count_occurences){
	if(is_empty(head)) return EMPTY;
	Queue *current = head;
	int counter = 0;
	while(current != NULL){
		if(current->data == data_to_count_occurences) counter++;
		current = current->next;
	}
	return counter;
}

void destroy_queue(Queue *head){
	while(head != NULL){
		Queue *current = head;
		head = head->next;
		free(current);
	}
    head = NULL;
}

Queue *reverse(Queue *head){
	if(is_empty(head)) return NULL;
	if(head->next ==NULL)  return head;
	Queue *current = head;
	Queue *next = NULL;
	Queue *prev = NULL;
	while(current->next != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}

Queue *copy(Queue *head){
	if(is_empty(head)) return NULL;
	if(head-> next == NULL) return head;
	Queue *current = head;
	Queue *copy_head = NULL;
	Queue *copy_tail = NULL;
	while(current != NULL){
		Queue *new_queue_node = malloc(sizeof(Queue));
		if(is_empty(new_queue_node)) return NULL;
		new_queue_node->data = current->data;
		new_queue_node->next = NULL;
		if(copy_head == NULL){
			copy_head = new_queue_node;
			copy_tail = new_queue_node;
		}
		else{
			copy_tail->next = new_queue_node;
			copy_tail = new_queue_node;
		}
		current = current->next;
	}
	return copy_head;
}

int front(Queue *head){
	if(is_empty(head)) return EMPTY;
	return head->data;
}

int rear(Queue *head){
	if(is_empty(head)) return EMPTY;
	Queue *current = head;
	while(current->next != NULL){
		current = current->next;
	}
	return current->data;
}

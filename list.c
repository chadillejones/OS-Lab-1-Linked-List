// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#include "list.h"

/* Functions for allocating and freeing lists. By using only these functions,
 * the user should be able to allocate and free all the memory required for
 * this linked list library. */
list_t *list_alloc() { 
  list_t *list = (list_t *) malloc(sizeof(list_t));
  list->head = NULL;

  return list;
}

void list_free(list_t *l) {
	node_t* current = l->head;
	node_t* next = NULL;
	while (current != NULL) {
		next = current->next;
    free(current);
    current = next;
	}
  free(l);
}

/* Prints the list in some format. */
void list_print(list_t *l) {
	node_t* temp = l->head;
	while (temp != NULL) {
		printf(" %d ", temp->value);
		temp = temp->next;
	}
  printf("\n");
}

/* Returns the length of the list. */
int list_length(list_t *l) { 
	node_t* temp = l->head;
  int count = 0;
	while (temp != NULL) {
		temp = temp->next;
    count++;
	}
  return count;
}

/* Methods for adding to the list. */
void list_add_to_back(list_t *l, elem value) {
	node_t* current = l->head;
  if (current == NULL) {
    current = (node_t *) malloc(sizeof(node_t));
    current->value = value;
    current->next = NULL;
    l->head = current;
  } else {
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->value = value;
    current->next->next = NULL;    
  }
}

void list_add_to_front(list_t *l, elem value) {
  node_t* new_node = (node_t *) malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = l->head;
  l->head = new_node;  
}

void list_add_at_index(list_t *l, elem value, int index) {
  node_t* current = l->head;
  int length = list_length(l);
  if ((current == NULL) || (index <= 0)) {
    list_add_to_front(l, value);
  } else if (index > length) {
    list_add_to_back(l, value);
  } else {
    int current_index = 1;
    while (current_index < index) {
      current = current->next;
      current_index++;
    }
    node_t* new_node = (node_t *) malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = current->next;
    current->next = new_node;
  }
}

/* Methods for removing from the list. Returns the removed element. */
elem list_remove_from_back(list_t *l) {
  int length = list_length(l);
  node_t* current = l->head;

  if (length == 0) {
    return 0;
  } else if (length == 1) {
    elem value = current->value;
    free(current);
    l->head = NULL;
    return value;
  } else {
    while (current->next->next != NULL) {
      current = current->next;
    }
    elem value = current->next->value;
    free(current->next);
    current->next = NULL;
    return value;   
  }
  return -1;
}

elem list_remove_from_front(list_t *l) { 
  int length = list_length(l);
  node_t* head = l->head;

  if (length == 0) {
    return 0;
  } else if (length == 1) {
    elem value = head->value;
    free(head);
    l->head = NULL;
    return value;
  } else {
    node_t* next = head->next;
    elem value = head->value;
    free(head);
    l->head = next;
    return value;
  }
  return -1;
}

elem list_remove_at_index(list_t *l, int index) { 
  node_t *temp = l->head;
  if(index == 0){
    list_remove_from_front(l);
  }else if(index == (list_length(l) - 1)){
    list_remove_from_back(l);
  }else{
    int i = 0;
    while(i < (index-1)){
      temp = temp->next;
      i+=1;
    }
    elem removedNum = temp->value;
    free(temp);
    return removedNum;
  }
  return -1;
}

/* Checks to see if the given element exists in the list. */
bool list_is_in(list_t *l, elem value) { 
  if(list_length(l) == 0){
    printf("Please add numbers to the list\n");
    return false; 
  }
  node_t *t = l->head;
  while(t != NULL){
    if(t->value == value){
      printf("true\n");
      return true;
    }
    t = t->next;
  }
  return false;
}

/* Returns the element at the given index. */
elem list_get_elem_at(list_t *l, int index) { 
  node_t *t = l->head;
  int i = 0;
  if(list_length(l) == 0){
    printf("Add elements to the list\n");
    return -1; 
  }
  while(i < (index-1)){
    t= t->next;
    i+=1;
  }
  elem listElem = t->value;
  return listElem; 
}

/* Returns the index at which the given element appears. */
int list_get_index_of(list_t *l, elem value) { 
  node_t *t = l->head;
  int index = 0;

  while(t != NULL){
    if(t->value == value){
      return index;
    }else
    {
      t = t->next;
      index+=1;
    }
  }
  
  return -1;   
}



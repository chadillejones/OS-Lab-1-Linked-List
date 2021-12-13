#include <stdio.h>

#include "list.h"

int main() {
  printf("Tests for linked list implementation\n");
  
  list_t *mylist = list_alloc();
  // list_add_to_back test
  printf("---list_add_to_back test---\n");
  printf("Adding 1, 2, 3 to the back\n");
  list_add_to_back(mylist, 1);
  list_add_to_back(mylist, 2);
  list_add_to_back(mylist, 3);
  list_print(mylist);
  printf("\n");

  // list_add_to_front test
  printf("---list_add_to_front test---\n");
  printf("Adding 4 to the front\n");
  list_add_to_front(mylist, 4);
  list_print(mylist);
  printf("\n");

  // list_add_at_index test
  printf("---list_add_at_index test---\n");
  printf("Adding 10 to index 0\n");
  list_add_at_index(mylist, 10, 0);
  list_print(mylist);
  printf("Adding 20 to index 4\n");
  list_add_at_index(mylist, 20, 4);
  list_print(mylist);
  printf("Adding 30 to index 10\n");
  list_add_at_index(mylist, 30, 10);
  list_print(mylist);
  printf("Adding 40 to index 1\n");
  list_add_at_index(mylist, 40, 1);
  list_print(mylist);
  printf("\n");

  // list_get_elem_at test
  printf("---list_get_elem_at test---\n");
  list_print(mylist);
  elem val = list_get_elem_at(mylist, 0);
  printf("The element at index 0 is %d \n", val);
  val = list_get_elem_at(mylist, 7);
  printf("The element at index 7 is %d \n", val);
  val = list_get_elem_at(mylist, 2);
  printf("The element at index 2 is %d \n", val);
  printf("\n");

  // list_get_index_of test
  printf("---list_get_index_of test---\n");
  list_print(mylist);
  val = list_get_index_of(mylist, 30);
  printf("The index of 30 is %d \n", val);
  val = list_get_index_of(mylist, 10);
  printf("The index of 10 is %d \n", val);
  val = list_get_index_of(mylist, 4);
  printf("The index of 4 is %d \n", val);
  printf("\n");

  // list_is_in test
  printf("---list_is_in test---\n");
  list_print(mylist);
  bool is_in = list_is_in(mylist, 30);
  printf("Return 1 if 30 is in the list: %d \n", is_in);
  is_in = list_is_in(mylist, 500);
  printf("Return 1 if 500 is in the list: %d \n", is_in);
  printf("\n");


  // list_remove_from_front test
  printf("---list_remove_from_front test---\n");
  list_print(mylist);
  printf("Removing from front\n");
  list_remove_from_front(mylist);
  list_print(mylist);
  printf("\n");

  // list_remove_from_back test
  printf("---list_remove_from_back test---\n");
  list_print(mylist);
  printf("Removing from back\n");
  list_remove_from_back(mylist);
  list_print(mylist);
  
  // list_remove_at_index test
  printf("---list_remove_at_index test---\n");
  list_print(mylist);
  printf("Removing 40 from index 0\n");
  list_remove_at_index(mylist, 0);
  list_print(mylist);


  // operations on empty list test
  printf("---operations on empty list tests---\nList: ");
  list_print(mylist);
  printf("Removing from index 0\n");
  list_remove_at_index(mylist, 0);
  printf("Removing from back\n");
  list_remove_from_back(mylist);
  printf("Removing from front\n");
  list_remove_from_front(mylist);
  printf("Removing from index 0\n");
  list_remove_at_index(mylist, 0);
  printf("Removing from index 0\n");
  list_remove_at_index(mylist, 0);
  printf("List: ");
  list_print(mylist);
  val = list_get_elem_at(mylist, 0);
  printf("The element at index 0 is %d \n", val);
  is_in = list_is_in(mylist, 0);
  printf("Return 1 if 0 is in the list: %d \n", is_in);
  val = list_get_index_of(mylist, 4);
  printf("The index of 0 is %d \n", val);
  printf("\n");
  
  
  printf("Freeing list.\n");
  list_free(mylist);
  
  return 0;
}

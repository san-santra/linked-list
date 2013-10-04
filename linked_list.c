/* Copyright 2013 miltus31

This file is a part of linked list

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include<stdlib.h>
#include<string.h>

#include"linked_list.h"


linked_list *create_linked_list(size_t size){
  linked_list *list = (linked_list *)malloc(sizeof(linked_list));

  list->start = NULL;
  list->end = NULL;
  //  list->elementSize = size;

  return list;
}


void linked_list_insert(linked_list *list, void *data){
  struct linked_list_node *node;

  node = (struct linked_list_node *)malloc(sizeof(struct linked_list_node));

  node->data = data;
  //  memcpy(node->data, data, list->elementSize);
  node->next = NULL;

  //empty list
  if(list->end == NULL){
    list->start = node;
  }else{
    list->end->next = node;
  }
  
  list->end = node;
  list->nmemb++;
}

// deletes the given linked list including all the data
void linked_list_free_all(linked_list *list){
  struct linked_list_node *node;

  node = list->start;
  while(node != NULL){
    list->start = node->next;
    
    node->next = NULL;
    free(node->data);
    free(node);

    node = list->start;
  }

  free(list);
}

/* size ~~> size of each data item stored in the linked list */
void **linked_list2array(linked_list *list){
  void **data = (void **)malloc(list->nmemb*sizeof(void *));

  struct linked_list_node *tmp = list->start;
  int index = 0;

  while(tmp != NULL){
    //    *(data+index*size) = tmp->data;
    data[index] = tmp->data;

    tmp = tmp->next;
  }

  return data;
}

void linked_list_append(linked_list *list1, linked_list *list2){
  if(list1->start == NULL){
    list1->start = list2->start;
    list1->end = list2->end;
    list1->nmemb = list2->nmemb;
  }
  else if(list2->start != NULL){
    list1->end->next = list2->start;
    list1->end = list2->end;
    list1->nmemb += list2->nmemb;
  }
}


void * linked_list_search(linked_list *list, void *data, int (*cmp)(const void *, const void *)){
  struct linked_list_node *node = list->start;

  while(node !=NULL){
    //found
    if(!cmp(node->data, data))
      return node->data;

    node = node->next;
  }

  return NULL;
}

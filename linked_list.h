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

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<stdlib.h>

typedef struct{
  struct linked_list_node *start, *end;

  //  size_t elementSize;
  int nmemb;
}linked_list;

struct linked_list_node{
  void *data;
  struct linked_list_node *next;
};

// creates an empty linked list
linked_list *create_linked_list();

void linked_list_insert(linked_list *list, void *data);

void * linked_list_search(linked_list *list, void *data,
			  int (*cmp)(const void *, const void *));

//int linked_list_delete(linked_list *list);

// deletes the given linked list including all the data
void linked_list_free_all(linked_list *list);

void **linked_list2array(linked_list *list);

// list2 is appended to list1
void linked_list_append(linked_list *list1, linked_list *list2);


#endif

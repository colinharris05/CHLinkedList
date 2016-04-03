#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "CHLinkedList.h"

typedef struct CHNode {
  void *data;
  struct CHNode *next;
} CHNode;

CHNode *newNode(void *data) {
  CHNode *node = malloc(sizeof(CHNode));
  node->data = data;
  node->next = NULL;
  return node;
}

/* ------------------ */

struct _CHLinkedList {
  CHNode *head;
  CHNode *tail;
  int size;
};

CHLinkedList *chlinkedlist_new() {
  CHLinkedList *list = malloc(sizeof(CHLinkedList));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

void chlinkedlist_print(CHLinkedList *list) {
  CHNode *curr = list->head;
}

int chlinkedlist_size(CHLinkedList *list) {
  return list->size;
}

void *chlinkedlist_get(CHLinkedList *list, int index) {
  if (list->size == 0) {
    return NULL;
  }

  CHNode *curr = list->head;
  int i;
  for (i = 0; i < index; i++) {
    curr = curr->next;
  }
  return curr->data;
}

void chlinkedlist_append(CHLinkedList *list, void *data) {
  assert(data != '\0');
  CHNode *node = newNode(data);
  if (list->head == NULL && list->tail == NULL) {
    list->head = node;
    list->tail = node;
  } else {
    list->tail->next = node;
    list->tail = node;
  }
  list->size++;
}

void *chlinkedlist_removeFromEnd(CHLinkedList *list) {
  if (list->size == 0) {
    return NULL;
  } else if (list->size == 1) {
    CHNode *node = list->tail;
    list->head = NULL;
    list->tail = NULL;
    list->size--;
    return node->data;  
  }
  CHNode *node = list->tail;
  CHNode *curr = list->head;
  while (curr->next != list->tail) {
    curr = curr->next;
  }
  list->tail = curr;
  list->tail->next = NULL;
  list->size--;
  free(curr);
  return node->data;
}
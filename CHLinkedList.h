typedef struct _CHLinkedList CHLinkedList;

CHLinkedList *chlinkedlist_new();
int chlinkedlist_size(CHLinkedList *list);
void *chlinkedlist_get(CHLinkedList *list, int index);
void chlinkedlist_append(CHLinkedList *list, void *data);
void *chlinkedlist_removeFromEnd(CHLinkedList *list);
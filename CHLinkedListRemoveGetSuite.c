#include <stdlib.h>

#include "CHLinkedList.h"
#include "CuTest.h"

void TestRemovingWithZeroElements(CuTest *tc) {
  CHLinkedList *list = chlinkedlist_new();

  int actual_size = chstack_size(stack);
  int expected_size = 0;
  CuAssertIntEquals(tc, expected_size, actual_size);

  int *actual = (int *)chlinkedlist_removeFromEnd(CHLinkedList *list);
  void *expected = NULL;
  CuAssertPtrEquals(tc, expected, actual);
}

CuSuite* CHLinkedListRemoveGetSuite()() {
  CuSuite* suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, TestRemovingWithZeroElements);
  return suite;
}

#include <stdlib.h>

#include "CHLinkedList.h"
#include "CuTest.h"

void TestAppendingTwoElements(CuTest *tc) {
  CHLinkedList *list = chlinkedlist_new();
  int i = 5;
  int j = 6;
  chlinkedlist_append(list, &i);
  chlinkedlist_append(list, &j);

  int expected_size = 2;
  int actual_size = chlinkedlist_size(list);

  int *first = chlinkedlist_get(list, 0);
  int firstExpected = 5;

  int *second = chlinkedlist_get(list, 1);
  int secondExpected = 6;
  
  CuAssertIntEquals(tc, expected_size, actual_size);
  CuAssertIntEquals(tc, *first, firstExpected);
  CuAssertIntEquals(tc, *second, secondExpected);
}

CuSuite* CHLinkedListAppendGetSuite() {
  CuSuite* suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, TestAppendingTwoElements);
  return suite;
}

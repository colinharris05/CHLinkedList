#include <stdlib.h>

#include "CHLinkedList.h"
#include "CuTest.h"

void TestRemovingWithZeroElements(CuTest *tc) {
  CHLinkedList *list = chlinkedlist_new();

  int actual_size = chlinkedlist_size(list);
  int expected_size = 0;
  CuAssertIntEquals(tc, expected_size, actual_size);

  int *actual = (int *)chlinkedlist_removeFromEnd(list);
  void *expected = NULL;
  CuAssertPtrEquals(tc, expected, actual);
}

void TestRemovingWithOneElement(CuTest *tc) {
  CHLinkedList *list = chlinkedlist_new();

  int i = 5;
  chlinkedlist_append(list, &i);

  int actual_size = chlinkedlist_size(list);
  int expected_size = 1;
  CuAssertIntEquals(tc, expected_size, actual_size);

  int *actual = (int *)chlinkedlist_removeFromEnd(list);
  int expected = 5;
  CuAssertIntEquals(tc, expected, *actual);
}

void TestRemovingWithTwoElements(CuTest *tc) {
  CHLinkedList *list = chlinkedlist_new();

  int i = 5;
  int j = 6;
  chlinkedlist_append(list, &i);
  chlinkedlist_append(list, &j);

  int actual_size = chlinkedlist_size(list);
  int expected_size = 2;
  CuAssertIntEquals(tc, expected_size, actual_size);

  int *actual = (int *)chlinkedlist_removeFromEnd(list);
  int expected = 6;
  CuAssertIntEquals(tc, expected, *actual);
}

void TestRemovingTwoElementsInARow(CuTest *tc) {
  CHLinkedList *list = chlinkedlist_new();

  int i = 5;
  chlinkedlist_append(list, &i);

  int actual_size = chlinkedlist_size(list);
  int expected_size = 1;
  CuAssertIntEquals(tc, expected_size, actual_size);

  int *actual = (int *)chlinkedlist_removeFromEnd(list);
  int expected = 5;
  CuAssertIntEquals(tc, expected, *actual);

  actual = (int *)chlinkedlist_removeFromEnd(list);
  int *expectedNull = NULL;
  CuAssertPtrEquals(tc, expectedNull, actual);
}

CuSuite* CHLinkedListRemoveGetSuite() {
  CuSuite* suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, TestRemovingWithZeroElements);
  SUITE_ADD_TEST(suite, TestRemovingWithOneElement);
  SUITE_ADD_TEST(suite, TestRemovingWithTwoElements);
  SUITE_ADD_TEST(suite, TestRemovingTwoElementsInARow);
  return suite;
}

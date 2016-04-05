#include <stdlib.h>

#include "CHLinkedList.h"
#include "CuTest.h"

void TestGetWithZeroElements(CuTest *tc) {
  CHLinkedList *list = chlinkedlist_new();
  int *expected = NULL;
  int *actual = chlinkedlist_get(list, 0);

  CuAssertPtrEquals(tc, expected, actual);
}

void TestGetWithOneElement(CuTest *tc) {
  CHLinkedList *list = chlinkedlist_new();
  int i = 123;
  chlinkedlist_append(list, &i);

  int *expected = &i;
  int *actual = chlinkedlist_get(list, 0);

  CuAssertPtrEquals(tc, expected, actual);
}


void TestGetWithTwoElements(CuTest *tc) {
  CHLinkedList *list = chlinkedlist_new();
  int i = 123;
  int j = 456;
  chlinkedlist_append(list, &i);
  chlinkedlist_append(list, &j);

  int *expected = &j;
  int *actual = chlinkedlist_get(list, 1);

  CuAssertPtrEquals(tc, expected, actual);
}


CuSuite* CHLinkedListGetGetSuite() {
  CuSuite* suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, TestGetWithZeroElements);
  SUITE_ADD_TEST(suite, TestGetWithOneElement);
  SUITE_ADD_TEST(suite, TestGetWithTwoElements);
  return suite;
}
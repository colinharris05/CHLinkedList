#include <stdlib.h>
#include <stdbool.h>
#include "CHLinkedList.h"
#include "CuTest.h"

void TestContainsWithZeroElements(CuTest *tc) {
  CHLinkedList *list = chlinkedlist_new();
  int i = 5;

  bool actual = chlinkedlist_contains(list, &i);

  CuAssertTrue(tc, !actual);
}

CuSuite* CHLinkedListContainsGetSuite() {
  CuSuite* suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, TestContainsWithZeroElements);
  return suite;
}

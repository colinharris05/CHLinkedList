#include <stdio.h>

#include "CuTest.h"

CuSuite* CHLinkedListAppendGetSuite();
CuSuite* CHLinkedListPopGetSuite();
CuSuite* CHLinkedListGetGetSuite();
CuSuite* CHLinkedListContainsGetSuite();

void RunAllTests() {
  CuString *output = CuStringNew();
  CuSuite* suite = CuSuiteNew();

  CuSuiteAddSuite(suite, CHLinkedListAppendGetSuite());
  CuSuiteAddSuite(suite, CHLinkedListPopGetSuite());
  CuSuiteAddSuite(suite, CHLinkedListGetGetSuite());
  CuSuiteAddSuite(suite, CHLinkedListContainsGetSuite());

  CuSuiteRun(suite);
  CuSuiteSummary(suite, output);
  CuSuiteDetails(suite, output);
  printf("%s\n", output->buffer);
}

int main(void) {
  RunAllTests();
}

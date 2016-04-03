#include <stdio.h>

#include "CuTest.h"

CuSuite* CHLinkedListAppendGetSuite();
CuSuite* CHLinkedListRemoveGetSuite();

void RunAllTests() {
  CuString *output = CuStringNew();
  CuSuite* suite = CuSuiteNew();

  CuSuiteAddSuite(suite, CHLinkedListAppendGetSuite());
  CuSuiteAddSuite(suite, CHLinkedListRemoveGetSuite());

  CuSuiteRun(suite);
  CuSuiteSummary(suite, output);
  CuSuiteDetails(suite, output);
  printf("%s\n", output->buffer);
}

int main(void) {
  RunAllTests();
}

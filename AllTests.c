#include <stdio.h>

#include "CuTest.h"

CuSuite* CHLinkedListAppendGetSuite();

void RunAllTests() {
  CuString *output = CuStringNew();
  CuSuite* suite = CuSuiteNew();

  CuSuiteAddSuite(suite, CHLinkedListAppendGetSuite());

  CuSuiteRun(suite);
  CuSuiteSummary(suite, output);
  CuSuiteDetails(suite, output);
  printf("%s\n", output->buffer);
}

int main(void) {
  RunAllTests();
}

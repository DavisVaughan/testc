#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

extern SEXP test_add(SEXP, SEXP);

static const R_CallMethodDef CallEntries[] = {
  {"test_add", (DL_FUNC) &test_add, 2}
};

void R_init_testc(DllInfo *dll)
{
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}

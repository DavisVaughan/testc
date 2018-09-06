#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>

SEXP test_add(SEXP x, SEXP y) {

  int yes_x = 0;
  int yes_y = 0;

  int val_x = 0;
  int val_y = 0;

  int val = 0;

  if(TYPEOF(x) == INTSXP) {
    yes_x = 1;
    val_x = INTEGER(x)[0];
  }

  if(TYPEOF(y) == INTSXP) {
    yes_y = 1;
    val_y = INTEGER(y)[0];
  }

  if(yes_x & yes_y) {
    val = val_x + val_y;
    return Rf_ScalarInteger(val);
  } else {
    Rf_errorcall(R_NilValue, "Something is not an integer.");
  }

}

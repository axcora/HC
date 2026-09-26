#ifndef FILTER_H
#define FILTER_H
#include "../../include/cax.h"

CAXArray* cax_filter_apply(CAXArray *input_array, const char *filter_expr);
CAXArray* cax_apply_filter_chain(CAXArray *input, const char *chain, CAXObject *ctx);
CAXArray* cax_filter_limit(CAXArray *arr, int limit);
CAXArray* cax_filter_slice(CAXArray *arr, int start, int end);
CAXArray* cax_filter_by_tag(CAXArray *arr, const char *tag_val, CAXObject *ctx);

#endif
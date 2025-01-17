#include <stdio.h>

typedef struct {
    double* a;
    size_t degree;
} poly;

poly* init_poly();

void poly_set_a(poly* p, size_t i, double a);

poly* copy_poly(poly* p);

void free_poly(poly* p);

double eval_poly(poly* p, double x);

void print_poly(poly* p);

poly* derive_poly(poly* p);

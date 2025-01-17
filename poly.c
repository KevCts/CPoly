#include "poly.h"
#include <stdio.h>
#include <stdlib.h>

poly* init_poly() {
    poly* res = malloc(sizeof(poly));
    res->a = calloc(1, sizeof(double));
    res->degree = 0;

    return res;
}

void poly_set_a(poly* p, size_t i, double a) {
    if (p->degree < i){
        p->a = realloc(p->a, (i+1) * sizeof(double));
        p->degree = i;
    }

    p->a[i] = a;
}

poly* copy_poly(poly* p) {
    poly* res = init_poly();
    for (size_t i = p->degree; i + 1; i--) {
        poly_set_a(res, i, p->a[i]);
    }

    return res;
}

void free_poly(poly* p) {
    free(p->a);
    free(p);
}

double eval_poly(poly* p, double x) {
    double res = 0;

    for(size_t i = p->degree; i + 1; i--) {
        res *= x;
        res += p->a[i];
    }

    free_poly(p);

    return res;
}

void print_poly(poly* p) {
    for (size_t i = 0; i <= p->degree; i++) {
        if (i > 0) {
            printf(" + ");
        }
        printf("%lf x%ld", p->a[i], i);
    }

    free_poly(p);
    
    printf("\n");
}

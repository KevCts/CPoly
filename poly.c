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
    for(size_t i = p->degree; i + 1; i--) {
        if (i < p->degree) {
            printf(" + ");
        }
        printf("%lf x%ld", p->a[i], i);
    }

    free_poly(p);
    
    printf("\n");
}

poly* derive_poly(poly* p) {
    poly* res = init_poly();

    for(size_t i = p->degree; i; i--) {
        poly_set_a(res, i-1, i * p->a[i]);
    }

    free_poly(p);

    return res;
}

double poly_get_a(poly* p, size_t i) {
    return i <= p->degree ? p->a[i] : 0;
}

poly* produit_poly(poly* p, poly* q) {
    poly* res = init_poly();
    double acc = 0;

    for(size_t i = p->degree + q->degree; i+1; i--) {
        for(size_t j = 0; j <= i; j++) {
            acc += poly_get_a(p, j) * poly_get_a(q, i-j);
        }
        poly_set_a(res, i, acc);
        acc = 0;
    }

    free_poly(p);
    free_poly(q);
    
    return res;
}

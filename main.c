#include <stdio.h>
#define VEC_IMPL
#include "vec.h"

int main(){
    Vec a = vec_alloc(3);
    vec_put(a, (float[]){1, 2, 3}, 3);
    Vec b = vec_alloc(3);
    vec_put(b, (float[]){1, 2, 3}, 3);
    printf("Vec 'a': ");
    vec_print(a);
    printf("Vec 'b': ");
    vec_print(b);
    printf("Vec a+b: ");
    vec_print(vec_add(a, b));
    printf("dot: %lf\n", vec_dot(a, b));
    printf("cross: %lf\n", vec_cross(a, b));
    printf("Vec a*10: ");
    vec_print(vec_mul(a, 10));
    return 0;
}

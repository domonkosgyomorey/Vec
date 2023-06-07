#define VEC_IMPL
#include "vec.h"

int main(){
    Vec a = vec_alloc(2);
    Vec b = vec_alloc(2);

    vec_put(a, (double[]){1, 0}, 2);
    vec_put(b, (double[]){1, 1}, 2);

    printf("'a' vector: ");
    vec_print(a);
    printf("'b' vector: ");
    vec_print(b);

    printf("'a'+'b'=");
    vec_print(vec_add(a, b));
   
    printf("'a'×'b'=%lf\n", vec_cross(a, b));
    
    printf("rotate 'a' by 90: ");
    vec_print(vec_rotate2d(a, 90));
    return 0;
}

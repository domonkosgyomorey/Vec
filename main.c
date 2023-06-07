#include <stdio.h>
#define VEC_IMPL
#include "vec.h"

int main(){
    Vec a = vec_alloc(3);
    vec_put(a, (double[]){1, 2, 3}, 3);
    Vec b = vec_alloc(3);
    vec_put(b, (double[]){1, 2, 3}, 3);

    printf("Vec 'a': ");
    vec_print(a);
    printf("Vec 'b': ");
    vec_print(b);
    
    printf("Vec a+b: ");
    vec_print(vec_add(a, b));
    
    printf("Vec a-b: ");
    vec_print(vec_sub(a, b));
    
    printf("dot: %lf\n", vec_dot(a, b));
    
    printf("cross: %lf\n", vec_cross(a, b));
    
    printf("Vec a*10: ");
    vec_print(vec_mul(a, 10));
    
    Vec e = vec_alloc(2);
    vec_put(e, (double[]){1, 0}, 2);
    
    printf("Vec 'e': ");
    vec_print(e);
    
    printf("'e' rotated by 90°: \t\t");
    vec_print(vec_rotate2d(e, 90));
    
    printf("'e' rotated by 180 over P(-1;0) point: \t\t");
    vec_print(vec_rotate2d_ex(e, -1, 0, 180));;
    
    printf("'e' rotated by 45 over P(0;0) point: \t\t");
    Vec rot_e45 = vec_rotate2d_ex(e, 0, 0, 45);
    printf(" len=( %lf )\n", vec_len(rot_e45));
    vec_print(rot_e45);

    Vec third = vec_alloc(3);
    vec_put(third, (double[]){1, 0, 0}, 3);
    printf("'third' vec: ");
    vec_print(third);

    printf("'third' rotated by x:90 y:0 z:0 : \t\t");
    vec_print(vec_rotate3d(third, 90, 0, 0));

    printf("'third' rotated by x:90 y:90 z:0 : \t\t");
    vec_print(vec_rotate3d(third, 90, 90, 0));
  
    // basicly:
    // 1st: x:45
    // 2nd: y:45
    // 3th: z:45
    printf("'third' rotated by x:45 y:45 z:45 : \t\t");
    vec_print(vec_rotate3d(third, 45, 45, 45));
    
    printf("'third' rotated by x:0 y:0 z:0 : \t\t");
    vec_print(vec_rotate3d(third, 0, 0, 0));

    vec_serialize(third, "third.vec");
    Vec vec = vec_deserialize("third.vec");
    printf("The original 'third': ");
    vec_print(third);
    printf("The deserialized 'third': ");
    vec_print(vec);
    return 0;
}

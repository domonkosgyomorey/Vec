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
    
    printf("Vec a-b: ");
    vec_print(vec_sub(a, b));
    
    printf("dot: %lf\n", vec_dot(a, b));
    
    printf("cross: %lf\n", vec_cross(a, b));
    
    printf("Vec a*10: ");
    vec_print(vec_mul(a, 10));
    
    Vec e = vec_alloc(2);
    vec_put(e, (float[]){1, 0}, 2);
    
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
    vec_put(third, (float[]){1, 0, 0}, 3);
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
    
    // basicly:
    // 1st y:45
    // 2nd x:45
    // 3th z:45      I think its a bug somethere
    printf("'third' rotated by y:45 x:45 z:45 :\n");
    Vec y = vec_rotate3d(third, 0, 90, 0);
    vec_print(y);
    y = vec_rotate3d(y, 90, 0, 0);
    vec_print(y);
    vec_print(vec_rotate3d(y, 0, 0, 90));
    //vec_print(vec_rotate3d(vec_rotate3d(vec_rotate3d(third, 0, 90, 0), 90, 0, 0), 0, 0, 90));

    printf("'third' rotated by x:0 y:0 z:0 : \t\t");
    vec_print(vec_rotate3d(third, 0, 0, 0));
    
    vec_print(third);
    printf("'third' rotated by y:90 x:90 z:90 :\n");
    //y = vec_rotate3d_y(third, 90);
    //vec_print(y);
   // y = vec_rotate3d_x(y, 90);
    //vec_print(y);
    vec_print(vec_rotate3d_z(third, 90));
}

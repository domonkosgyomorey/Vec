#ifndef VEC_H
#define VEC_H

#ifndef VEC_CALLOC
#include <stdlib.h>
#define VEC_CALLOC calloc
#endif

#ifndef VEC_ASSERT
#include <assert.h>
#define VEC_ASSERT assert
#endif

#ifndef VEC_PRINT
#include <stdio.h>
#define VEC_PRINT printf
#endif

#ifndef VEC_SQRT
#include <math.h>
#define VEC_SQRT sqrt
#endif

#ifndef VEC_ACOS
#include <math.h>
#define VEC_ACOS acos
#endif

#ifndef VEC_SIN
#include <math.h>
#define VEC_SIN sin
#endif

#ifndef VEC_COS
#include <math.h>
#define VEC_COS cos
#endif

#define ll long long int
#define PI 3.141592653589793
#define DEG2RAD(D) (D)*(PI/180.0)

typedef struct Vec{
    ll dim;
    double* data;
}Vec;

Vec vec_alloc(ll dim);
void vec_print(Vec vec);
void vec_put(Vec vec, double* data, ll dim);
Vec vec_map(Vec a, double (*map)(double));
Vec vec_add(Vec a, Vec b);
Vec vec_add_s(Vec vec, double scalar);
Vec vec_sub(Vec a, Vec b);
Vec vec_mul(Vec vec, double scalar);
Vec vec_hamilton_prod(Vec a, Vec b);
double vec_dot(Vec a, Vec b);
double vec_angle_between(Vec a, Vec b);
double vec_cross(Vec a, Vec b);
double vec_len(Vec vec);
Vec vec_normalize(Vec vec);
Vec vec_rotate2d(Vec vec, double deg);
Vec vec_rotate2d_ex(Vec vec, double x, double y, double deg);
Vec vec_rotate3d(Vec vec, double xdeg, double ydeg, double zdeg);
Vec vec_rotate3d_x(Vec vec, double xdeg);
Vec vec_rotate3d_y(Vec vec, double ydeg);
Vec vec_rotate3d_z(Vec vec, double zdeg);

#ifdef VEC_IMPL

Vec vec_alloc(ll dim){
    double* data = VEC_CALLOC(dim, sizeof(double));
    VEC_ASSERT(data!=NULL && "Cannot allocate memory");
    return (Vec){dim, data};
}

void vec_print(Vec vec){
    for(ll i = 0; i < vec.dim; i++){
        VEC_PRINT("%.015lf\t", vec.data[i]);
    }
    VEC_PRINT("\n");
}

void vec_put(Vec vec, double* data, ll dim){
    VEC_ASSERT(vec.dim==dim && "Doesnt match the vec.dim with dim");
    for(ll i = 0; i < vec.dim; i++){
        vec.data[i] = data[i];
    }
}

Vec vec_map(Vec a, double (*map)(double)){
    Vec result = vec_alloc(a.dim);
    for(ll i = 0; i < a.dim; i++){
        a.data[i] = map(a.data[i]);
    }
    return result;
}

Vec vec_add(Vec a, Vec b){
    VEC_ASSERT(a.dim==b.dim && "Doesnt match the dim of the two vector");
    Vec result = vec_alloc(a.dim);
    for(ll i = 0; i < a.dim; i++){
        result.data[i] = a.data[i]+b.data[i];
    }
    return result;
}

Vec vec_add_s(Vec vec, double scalar){
    Vec result = vec_alloc(vec.dim);
    for(ll i = 0; i < vec.dim; i++){
        result.data[i] = vec.data[i]+scalar;
    }
    return result;
}

Vec vec_sub(Vec a, Vec b){
    VEC_ASSERT(a.dim==b.dim && "Doesnt match the dim of the two vector");
    Vec result = vec_alloc(a.dim);
    for(ll i = 0; i < a.dim; i++){
        result.data[i] = a.data[i]-b.data[i];
    }
    return result;
}

Vec vec_mul(Vec vec, double scalar){
    Vec result = vec_alloc(vec.dim);
    for(ll i = 0; i < vec.dim; i++){
        result.data[i] = vec.data[i]*scalar;
    }
    return result;

}

Vec vec_hamilton_prod(Vec a, Vec b){
    VEC_ASSERT(a.dim==b.dim && "The dimension of the two vector doesnt match");
    Vec result = vec_alloc(a.dim);
    result.data[0] = a.data[1]*b.data[2]-a.data[2]*b.data[1];
    result.data[1] = a.data[2]*b.data[0]-a.data[0]*b.data[2];
    result.data[2] = a.data[0]*b.data[1]-a.data[1]*b.data[0];
    return result;
}

double vec_dot(Vec a, Vec b){
    VEC_ASSERT(a.dim==b.dim && "The dimension of the two vector doesnt match");
    double result = 0; 
    for(ll i = 0; i < a.dim; i++){
        result += a.data[i]*b.data[i];
    }
    return result;    
}

double vec_angle_between(Vec a, Vec b){
    return VEC_ACOS(vec_dot(a, b)/(vec_len(a)*vec_len(b)));
}

double vec_cross(Vec a, Vec b){
    double al = vec_len(a);
    double bl = vec_len(b);
    double albl = al*bl;
    return albl*VEC_SIN(VEC_ACOS(vec_dot(a, b)/albl));
}

double vec_len(Vec vec){
    double result = 0; 
    for(ll i = 0; i < vec.dim; i++){
        result += vec.data[i]*vec.data[i];
    }
    return VEC_SQRT(result);  
}

Vec vec_normalize(Vec vec){
    return vec_mul(vec, 1.0/vec_len(vec));
}

Vec vec_rotate2d(Vec vec, double deg){
    VEC_ASSERT(vec.dim==2 && "The vector isnt 2D");
    Vec result = vec_alloc(2);
    Vec im = vec_normalize(vec);
    result.data[0] = (im.data[0]*VEC_COS(DEG2RAD(deg)))-(im.data[1]*VEC_SIN(DEG2RAD(deg)));
    result.data[1] = (im.data[0]*VEC_SIN(DEG2RAD(deg)))+(im.data[1]*VEC_COS(DEG2RAD(deg)));
    return vec_mul(result, vec_len(vec));
}

Vec vec_rotate2d_ex(Vec vec, double x, double y, double deg){
    VEC_ASSERT(vec.dim==2 && "The vector isnt 2D");
    Vec p = vec_alloc(2);
    p.data[0] = x;
    p.data[1] = y;
    vec = vec_sub(vec, p);
    Vec im = vec_normalize(vec);
    Vec result = vec_alloc(2);
    result.data[0] = (im.data[0]*VEC_COS(DEG2RAD(deg)))-(im.data[1]*VEC_SIN(DEG2RAD(deg)));
    result.data[1] = (im.data[0]*VEC_SIN(DEG2RAD(deg)))+(im.data[1]*VEC_COS(DEG2RAD(deg)));
    return vec_add(vec_mul(result, vec_len(vec)), p);
}

Vec vec_rotate3d(Vec vec, double xdeg, double ydeg, double zdeg){
    VEC_ASSERT(vec.dim==3 && "The vector isnt 3D");
    Vec xr = vec_rotate3d_x(vec, xdeg);
    vec_print(xr);
    xr = vec_rotate3d_y(xr, ydeg);
    vec_print(xr);
    xr = vec_rotate3d_z(xr, zdeg);
    vec_print(xr);
    return vec_rotate3d_z(vec_rotate3d_y(vec_rotate3d_x(vec, xdeg), ydeg), zdeg);
}

Vec vec_rotate3d_x(Vec vec, double xdeg){
    VEC_ASSERT(vec.dim==3 && "The vector isnt 3D");
    
    Vec result = vec_alloc(3);
    
    double len = vec_len(vec);
    vec = vec_normalize(vec);

    double xrad = DEG2RAD(xdeg);
    double sinx = VEC_SIN(xrad);
    double cosx = VEC_COS(xrad);
    
    result.data[0] = vec.data[0];
    result.data[1] = vec.data[1]*cosx-vec.data[2]*sinx;
    result.data[2] = vec.data[1]*sinx+vec.data[2]*cosx;
    
    return vec_mul(result, len);
}

Vec vec_rotate3d_y(Vec vec, double ydeg){
    VEC_ASSERT(vec.dim==3 && "The vector isnt 3D");
    
    Vec result = vec_alloc(3);
    
    double len = vec_len(vec);
    vec = vec_normalize(vec); 

    double yrad = DEG2RAD(ydeg);
    
    double siny = VEC_SIN(yrad);
    double cosy = VEC_COS(yrad);
    
    result.data[0] = vec.data[0]*cosy+vec.data[2]*siny;
    result.data[1] = vec.data[1];
    result.data[2] = (-vec.data[0]*siny)+vec.data[2]*cosy;
    
    return vec_mul(result, len);
}
Vec vec_rotate3d_z(Vec vec, double zdeg){
    VEC_ASSERT(vec.dim==3 && "The vector isnt 3D");
    
    Vec result = vec_alloc(3);
    
    double len = vec_len(vec);
    vec = vec_normalize(vec);

    double zrad = DEG2RAD(zdeg);
    double sinz = VEC_SIN(zrad);
    double cosz = VEC_COS(zrad);
    
    result.data[0] = vec.data[0]*cosz-vec.data[1]*sinz;
    result.data[1] = vec.data[0]*sinz+vec.data[1]*cosz;
    result.data[2] = vec.data[2];
    
    return vec_mul(result, len);
}

#endif // VEC_IMPL

#endif // VEC_H

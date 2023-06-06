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

#define ll long long int

typedef struct Vec{
    ll dim;
    float* data;
}Vec;

Vec vec_alloc(ll dim);
void vec_print(Vec vec);
void vec_put(Vec vec, float* data, ll dim);
Vec vec_add(Vec a, Vec b);
Vec vec_mul(Vec vec, float scalar);
double vec_dot(Vec a, Vec b);
double vec_angle_between(Vec a, Vec b);
double vec_cross(Vec a, Vec b);
double vec_len(Vec vec);

#ifdef VEC_IMPL

Vec vec_alloc(ll dim){
    float* data = VEC_CALLOC(dim, sizeof(float));
    VEC_ASSERT(data!=NULL && "Cannot allocate memory");
    return (Vec){dim, data};
}

void vec_print(Vec vec){
    VEC_PRINT("Vec dim(Vec)=%zu data:\n\t", vec.dim);
    for(ll i = 0; i < vec.dim; i++){
        VEC_PRINT("%.04f\t", vec.data[i]);
    }
    VEC_PRINT("\n");
}

void vec_put(Vec vec, float* data, ll dim){
    VEC_ASSERT(vec.dim==dim && "Doesnt match the vec.dim with dim");
    for(ll i = 0; i < vec.dim; i++){
        vec.data[i] = data[i];
    }
}

Vec vec_add(Vec a, Vec b){
    VEC_ASSERT(a.dim==b.dim && "Doesnt match the dim of the two vector");
    Vec result = vec_alloc(a.dim);
    for(ll i = 0; i < a.dim; i++){
        result.data[i] = a.data[i]+b.data[i];
    }
    return result;
}

Vec vec_mul(Vec vec, float scalar){
    Vec result = vec_alloc(vec.dim);
    for(ll i = 0; i < vec.dim; i++){
        result.data[i] = vec.data[i]*scalar;
    }
    return result;

}

double vec_dot(Vec a, Vec b){
    VEC_ASSERT(a.dim==b.dim && "Doesnt match the dim of the two vector");
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


#endif // VEC_IMPL

#endif // VEC_H

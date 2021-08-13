#ifndef __VSX__
    #error "VSX is not supported"
#endif
#include <altivec.h>

typedef __vector float fv4sf_t;
typedef __vector unsigned char vec_t;

int main(void)
{
    __vector_quad acc0;
    float a[4] = {1,2,3,4};
    float b[4] = {1,2,3,4};
    vec_t *ca = (vec_t *) a;
    vec_t *rb = (vec_t *) b;
    __builtin_mma_xvf32ger(&acc0, ca[0], rb[0]);
    fv4sf_t result[4];    
    __builtin_mma_disassemble_acc ( (void *) result, &acc0);                        \
    fv4sf_t c0 = result[0];
    return (int)((float*)&c0)[0];
}

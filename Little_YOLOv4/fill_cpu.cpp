
#include <string.h>


void fill_cpu(int N, float ALPHA, float* X, int INCX)
{
    int i;
    if (INCX == 1 && ALPHA == 0) {
        memset(X, 0, N * sizeof(float));
    }
    else {
        for (i = 0; i < N; ++i) X[i * INCX] = ALPHA;
    }
}
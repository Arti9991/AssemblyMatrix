#include <iostream>
#include <cstdlib> 
#include <ctime>
#include "math.h"

using namespace std;

extern "C" 
{
    //float Matrix1 (float c, float mass1, float mass2);
    void Matrix (float* a, float* b, float* d, int M, int N, int K);
}



void Multiply(float* a, float* b, float* c, int M, int N, int K) //функция умножения матриц
{  
     for (int i = 0; i < M; i++)
     {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < K; k++)
            {
                c[i*N + j] += a[i*K + k] * b[k*N + j];
                //c[i*N + j] = Matrix1 (c[i*N + j],mass1[i*K + k],mass2[k*N + j]);
                //cout << c[i*N + j] << endl;
            }
        }
     }
}

void MultiplyAsm(float* a, float* b, float* c, int m, int n, int k)
{
    int l = 0;
    int i = 0;
    int t = 0;
    unsigned int start_time, end_time, search_time; 
    double proc = 0;
    double time = 0;
    search_time = 0;


    start_time =  clock();
    for (t = 0; t < 3; t++)
    {
        while (l < m)
        { 
            i = 0;
            while (i < n)
            {   
                Matrix(a + l, b + i, c + n * l + i, m, n, k);

                i = i + 8;
            }
            l = l + 8; 
        }
    }
    end_time = clock();
    time = (double)(end_time - start_time) / CLOCKS_PER_SEC; 
    double tic = (m * n * k * 3) / 16;
    proc = 100 * (tic / (46e8 * time));
    //cout << tic << endl;

    cout << proc << endl;
    //cout << search_time2
     
}

void Transpond (float* mass1, float* mass2, int M, int K)
{
    for (int i= 0; i < M; i++)
    {
        for (int j = 0; j < K; j++)
        {
            mass2 [j * M + i] = mass1 [i * K + j];
        }
    }
}

int Deffect (float* a, float* b, int M, int N)
{   
    int d = 0;
    for (int i = 0; i < M * N; i++)
    {
        d += pow(fabs(b[i] - a[i]), 2);
    }

    d = sqrt(d);
    return d;
}


float AverDef(float *C, float *C2, int size) {
    int i = 0;
    float sumDiff = 0;
    for (i = 0; i < size; i++)
        sumDiff += abs(C[i] - C2[i]);
    return sumDiff / size;
}



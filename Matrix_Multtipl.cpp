#include <iostream>
#include <cstdlib> 
#include <ctime>
#include "Func.cpp"

using namespace std;

extern "C" 
{
    //float Matrix1 (float c, float mass1, float mass2);
    void Matrix (float* a, float* b, float* d, int M, int N, int K);
}


int main(int argc, char* argv[]) 
{   
    int m, n, k;
//Чтение аргументов n,m,k размеров матриц из командной строки, при условии их наличия
    if (argc == 4)
    {
        m = atoi(argv[1]);
        n = atoi(argv[2]);
        k = atoi(argv[3]);
    }
    else
    {
        m = 8;
        n = 8;
        k = 8;
    }
    //cout << "arguments of command line: " << argc << endl;
    //cout << "arguments of command line: " << m << endl;
//Выделение памяти под масиивы и заполнение случайными числами от 0 до 100
    float* a = new float[m * k];
    for (int i = 0; i < m * k; i++)
        a[i] = static_cast <float>(rand()%100) / 10.0;

    float* b = new float[k * n];
    for (int i = 0; i < k * n; i++)
        b[i] = static_cast <float> (rand()%100) / 10.0;

    float* c = new float[m * n];
    for (int i = 0; i < m * n; i++)
        c[i] = 0.0;

    float* c_m = new float[m * n];
    for (int i = 0; i < m * n; i++)
        c_m[i] = 0.0;       

//выделение памяти под транспонированную матрицу А и транспонирование её

    float* t_a = new float[m * k];
    
    Transpond(a, t_a, m, k);

/*
    for (int i = 0; i < m; i++){
        for (int j = 0; j < k; j++){
            std::cout << a[i * k + j] << ' ';
        }
       std::cout << std::endl;
    }
    std::cout << "______________________" << std::endl;
   for (int i = 0; i < k; i++){
        for (int j = 0; j < m; j++){
            std::cout << t_a[i * m + j] << ' ';
        }
       std::cout << std::endl;
    }
*/

//Вывод массивов на экран
/*
    for (int i = 0; i < m * k; i++)
        cout << a[i]<< "\t";
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
   */ 
    
/* 
    for (int i = 0; i < k * n; i++)
        cout << t_a[i]<< "\t";
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

       for (int i = 0; i < k * n; i++)
        cout << b[i]<< "\t";
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
*/
    
    
    
//Примненеие простой функции умножения матриц с подсчетом времени процесоора до и после приvенеия

    //unsigned int start_time =  clock();
    
    //Multiply(a, b, c_m, m, n, k);

    //unsigned int end_time = clock(); 
    //unsigned int search_time2;
    //unsigned int search_time;
    //unsigned int search_time1 = end_time - start_time;
    //int cl = search_time1/CLOCKS_PER_SEC;
    
    //cout << search_time1 << endl;
    /*
    for (int i = 0; i < m * n; i++)
    {
        cout << c_m[i]<< "\t";
        //c_m[i] = c[i];
        c[i] = 0;
    }
    */
    /*
    cout << "--------------------------------------";
    cout << endl;
    cout << endl;
    cout << endl;
    */

    //cout << endl;
    //Correctness(a, b, c, m, n);
    //cout << endl;
    
    //cout << search_time  << endl;
    
//Подключение функции с ссемблерным ядром х86 для умножения матриц

    if (k < 128 || m < 128 || n < 32) cout << 0 << endl;
    else
    {
        MultiplyAsm(t_a, b, c, m, n, k);
    }


    //float tic = (m * n * k) / 16;
    //float proc = 100 * ((tic/32e3)/search_time2); 

    /*
      for (int i = 0; i < m * n; i++)
        cout << c[i]<< "\t";
    cout << endl;
    cout << endl;
    cout << endl;
    */

    int size = n * m;

    //float d =  AverDef(c, c_m, size);
    //cout << d << endl;

    //d = AvgDeffect(c, c_m, m, n);
    //cout << endl;
    
    return 0;
    }
    
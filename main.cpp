//
//  main.cpp
//  Слияние
//
//  Created by Alexey Karpov on 13.10.16.
//  Copyright © 2016 Alexey Karpov. All rights reserved.
//

#include <iostream>
#include <ctime>

using namespace std;

int* rand_array(int *a, int n);
void print_array (int*, int);
int* copy_array (int*, int);
int* merge_sort (int*, int);

int main() {
    int n;
    cin >> n;
    int *a = new int [n];
    a = rand_array(a, n);
    print_array(a, n);
    a = merge_sort(a, n);
    print_array(a, n);
    delete[] a;
    return 0;
}

void print_array (int* a, int n)
{
    for (int i = 0; i < n; i ++)
        cout << a[i] << " ";
    cout << endl;
}
int* rand_array(int *a, int n)
{
    srand( time_t ( 0 ) );
    for (int i = 0; i < n; i ++)
    {
        a[i] =random() % 100;
    }
    return a;
}
int* copy_array (int *a, int n)
{
    int *b = new int[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i]; //memcpy
    }
    return b;
}


int* merge_sort (int* a, int n)
{
    if (n != 1)
    {
        int nb = n / 2;
        int nc = n - nb;
        int *b = copy_array(a, nb);
        int *c = copy_array(a + nb, nc);
        b = merge_sort(b, nb);
        c = merge_sort(c, nc);
        int i = 0, j =0, index = 0;
        while (i < nb && j < nc)
        {
            if (b[i] > c[j])
            {
                a[index] = b[i];
                index++;
                i++;
            } else {
                a[index] = c[j];
                index++;
                j++;
            }
        }
        while (i < nb)
        {
            a[index] = b[i];
            i++;
            index++;
        }
        while (j < nc)
        {
            a[index] = c[j];
            j++;
            index++;
        }
        delete[] b;
        delete[] c;
    }
    return a;
}
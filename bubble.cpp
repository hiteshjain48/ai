#include<iostream>
#include <omp.h>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void sequentialBubbleSort(int arr[], int n) {
    int swapped;
    for(int i = 0; i<n; i++) {
        swapped = 0;
        for(int j = 0; j<n; j++) {
            if(arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = 1;
            }
        }
        if(!swapped) break;
    }
}

void swap(int &a, int &b) {
    int test = a;
    a = b;
    b = test;
}

void parallelBubbleSort(int arr[], int n) {
    int swapped;
    for(int i  = 0; i<n; i++) {
        swapped = 0;
        int first = i%2;
        #pragma omp parallel for shared(arr, first)
        for (int j = first; j<n-1; j++) {
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = 1;
            }
        }
        if(!swapped) break;
    }
}


int main()
{
    int *a, n;
    cout << "\n enter total no of elements=>";
    cin >> n;
    a = new int[n];
    cout << "\n enter elements=>";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

   // Sequential algorithm
    double start = omp_get_wtime();
    sequentialBubbleSort(a, n);
    double stop = omp_get_wtime(); 
    double seq_time = stop-start; 

    

    cout << "\n sorted array is=>";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }

    cout << "\nSequential Time: " << seq_time<< endl;

    start = omp_get_wtime();
    parallelBubbleSort(a, n);
    stop = omp_get_wtime();
    double par_time = stop - start; 
    
    cout << "\n sorted array is=>";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }

    cout << "\nParallel Time: " << par_time<< endl;
    delete[] a; // Don't forget to free the allocated memory

    return 0;
}

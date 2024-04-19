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
    auto start = high_resolution_clock::now();
    sequentialBubbleSort(a, n);
    auto stop = high_resolution_clock::now(); 
    auto seq_time = duration_cast<microseconds>(stop - start); 

    

    cout << "\n sorted array is=>";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }

    cout << "\nSequential Time: " << seq_time.count() << endl;

   auto start_time =  high_resolution_clock::now();
    parallelBubbleSort(a, n);
    auto end_time = high_resolution_clock::now(); 
    auto par_time = duration_cast<microseconds>(end_time - start_time); 
    
    cout << "\n sorted array is=>";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }

    cout << "\nParallel Time: " << par_time.count()<< endl;
    delete[] a; // Don't forget to free the allocated memory

    return 0;
}

#include <iostream>
#include <omp.h>
using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x=y;
    y=temp;
}

void sequentialBubbleSort(int arr[], int size) {
    int swapped = 0;
    for(int i = 0; i<size; i++) {
        for(int j = i; j<size; j++) {
            if(arr[i]<arr[j]) {
                swapped = 1;
                swap(arr[i],arr[j]);
            }
        }
        if(!swapped) break;
    }
}

void parallelBubbleSort(int arr[], int size) {
    int swapped = 0;

    for(int i = 0; i<size; i++) {
        int first = i%2;
        #pragma omp parallel for shared(first, arr)
        for(int j = first; j<size; j++) {
            if(arr[i]<arr[j]){
                swapped = 1;
                swap(arr[i],arr[j]);
            }
        }
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int left_arr[n1];
    int right_arr[n2];

    for(int i = 0; i<n1; i++) {
        left_arr[i] = arr[left + i];
    }

    for(int j = 0; j<n2; j++) {
        right_arr[j] = arr[mid + j + 1];
    }

    int i=0, j=0, k = left;

    while(i<n1 && j<n2) {
        if(left_arr[i]<right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        } else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while(j<n2) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if(left<right) {
        int mid = left + (right-left)/2;
        #pragma omp parallel sections
        {
            #pragma omp section 
            {
                mergeSort(arr, left, mid);
            }
            #pragma omp section 
            {
                mergeSort(arr, mid+1, right);
            }
        }
        merge(arr, left, mid, right);
    }
}

int main() {
    int a[] = {5,4,2,3,1};
    int arr1[] = {5,4,2,3,1};
    int n = 5;
    double start_time, end_time, seq_time, par_time;
    start_time = omp_get_wtime();
    mergeSort(a,0,n-1);
    end_time = omp_get_wtime();
    seq_time = end_time - start_time;
    cout<<"\nSequential Time: "<<seq_time<<endl;

    start_time = omp_get_wtime();
    #pragma omp parallel 
    {
        #pragma omp single
        {
            mergeSort(a, 0, n-1);
        }
    }
    end_time = omp_get_wtime();
    par_time = end_time - start_time;

    cout<<"\nParallel Time: "<<par_time<<endl;

    cout<<"\nSorted Array: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<endl;
    }

    return 0;

}


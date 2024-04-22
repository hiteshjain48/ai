#include<iostream>
#include<stdlib.h>
#include <omp.h>
using namespace std;

void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left_start, int left_end, int right_start, int right_end);

void mergeSort(int arr[], int left, int right) 
{
    int mid;
    if(left<right) {
        mid = left + (right-left)/2;
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
        merge(arr, left, mid, mid+1, right);
    }
}

void merge(int arr[], int left_start, int left_end, int right_start, int right_end) 
{
    int temp[1000];
    int i,j,k;
    i = left_start;
    j = right_start;
    k = 0;

    while(i<left_end && j<right_end) 
    {
        if(arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        } 
        else 
        {
            temp[k++] = arr[j++];
        }
    }

    while(i<=left_end)
    {
        temp[k++] = arr[i++];
    }

    while(j<=right_end) 
    {
        temp[k++] = arr[j++];
    }

    for(i=left_start, j=0; i<=right_end; i++, j++) 
    {
        arr[i] = temp[j];
    }
}

int main() {
    int *a, n, i;
    double start_time, end_time, seq_time, par_time;

    cout<<"Enter total no. of elements: "<<endl;
    cin>>n;
    a = new int[n];

    cout<<"\nEnter elements: "<<endl;
    for(i=0; i<n; i++) 
    {
        cin>>a[i];
    }

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
    for(i=0; i<n; i++)
    {
        cout<<a[i]<<endl;
    }

    return 0;
}
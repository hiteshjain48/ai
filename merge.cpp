#include<iostream>
#include<omp.h>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left +1;
    int n2 = right - mid;

    int left_arr[n1], right_arr[n2];
    for(int i = 0; i<n1; i++) {
        left_arr[i] = arr[left + i];
    }

    for(int j = 0; j < n2; j++) {
        right_arr[j] = arr[mid + j + 1];
    }

    int i = 0, j = 0, k = left;

    while(i<n1 && j<n2) {
        if(left_arr[i]<right_arr[j]){
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
    int mid;
    if(left<right) {
        mid  = left + (right-left)/2;
        #pragma omp parallel sections 
        {
            #pragma omp section 
            {
                mergeSort(arr, left,  mid);
            }
            #pragma omp section 
            {
                mergeSort(arr, mid + 1, right);
            }
        }
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {6,5,3,1,8,7,2,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    #pragma omp parallel {
        #pragma omp single {
            mergeSort(arr, 0, n-1);
        }
    }

    {
        for(int i = 0; i < n; i++) {
            cout<<arr[i]<<" "
        }
    }
}

//
// Created by 12268 on 2023/12/3.
//

#ifndef SORT_SORT_H
#define SORT_SORT_H
#include "iostream"
using namespace std;

int *bubbleSort(int a[],int n){
    for (int j = n-1; j > 0; --j) {
        for(int i = 0; i < j; i++){
            if(a[i] < a[i+1])
                swap(a[i], a[i+1]);
        }
    }
    return a;
}

int *insertSort(int a[], int n){
    for(int j = 0; j<n; j++){
        int temp = a[j];
        int i;
        for(i = j-1; i >= 0; i--){
            if(a[i] <= temp) break;
            else a[i+1] = a[i];
        }
        a[i+1] = temp;
    }
    return a;
}

int *shellSort(int a[], int n){
    int step, i, j;
    int tmp;
    for(step = n/2; step>0; step/=2){
        for(i = step; i<n; i++){//for each i, insertSort with step
            tmp = a[i];
            j = i;
            while ((j-step >= 0)&&(tmp<=a[j-step])){
                a[j] = a[j-step];
                j-=step;
            }
            a[j] = tmp;
        }
    }
    return a;
}

int *selectSort(int a[], int n){
    int i,j,minIndex;
    int temp;
    for(i = 0; i<n; i++){
        minIndex = i;
        for(j = i+1; j < n; j++){
            if(a[j]<a[minIndex])
                minIndex = j;
        }
        if(minIndex != i){
            swap(a[i], a[minIndex]);
        }
    }
    return a;
}

int *merge(int a[], int low, int mid, int high){
    int i, j, k;
    int *c = new int[high-low+1];
    i = low;
    j = mid+1;
    k = 0;
    while ((i<=mid)&&(j<high)){
        if(a[i]<a[j]){
            c[k] = a[i];
            i++;
        }
        else {
            c[k] = a[j];
            j++;
        }
        k++;
    }
    while (i<=mid){
        c[k]=a[i];
        i=i+1;
        k=k+1;
    }
    while (j<=high){
        c[k]=a[j];
        j=j+1;
        k=k+1;
    }

    for (i=0;i<high-low+1; i++)   a[i+low] = c[i];
    delete []c;
    return a;
}

void mergeSort(int a[], int low, int high)
{
    int mid;
    if (low>=high) return;
    mid =(low+high)/2;
    mergeSort(a, low, mid);
    mergeSort(a, mid+1, high);
    merge(a, low, mid, high);
}

int *quickSort(int a[], int start, int end);

int *quickSort(int a[], int n){
    return quickSort(a, 0, n-1);
}

int *quickSort(int a[], int start, int end){
    if(end<=start) return a;
    int i = start, j = end, hole;
    int temp = a[i];
    while (i<j){
        while ((j>i)&&(a[j]>=temp)) j--;
        if (j==i) break;
        a[hole]=a[j];
        hole = j;

        while ((i<j)&&(a[i]<temp)) i++;
        if (j==i) break;
        a[hole]=a[i];
        hole = i;
    }
    a[hole] = temp;
    return a;
}

#endif //SORT_SORT_H

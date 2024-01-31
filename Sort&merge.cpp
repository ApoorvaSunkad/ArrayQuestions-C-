#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int r, int mid){
    int* merged = new int[r-1+1];
    int i = l;
    int j = mid+1;
    int k = 0;

    while(i<=mid && j<=r){
        if(arr[i]<=arr[j]){
            merged[k] = arr[i];
            i++;
            k++;
        }
        else{
            merged[k] = arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        merged[k] = arr[i];
        i++;
        k++;
    }
    while(j<=r){
        merged[k] = arr[j];
        j++;
        k++;
    }

    for(int i = 0, j=l; j<=r;i++,j++){
        arr[j] = merged[i];
    }
}
void mergeSort(int arr[], int l ,int r){
    if(l>=r){
        return;
    }

    int mid = (l+r)/2;

    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,r,mid);
}

int main(){
    int arr[] = {6,2,8,4,9,1,16,3};

    int n = 8;

    mergeSort(arr,0,7);
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
}
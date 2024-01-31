/*
Merge sort uses the concept of Divide and conquer where we divide the unsorted array
into 2 equal halves. We divide until it is impossible to divide the array further 
and then we merge the sorted arrays into one array.

Also this algorithm uses "Recursion" the divide the array

The time complexity to divide the array is O(LogN) because we divide the array
every time into 2 halves.
and to merge we traverse the array which takes O(N) where N is the number of elements 
in the array.

so the Total Time complexity boils down to O(n*logn)
and the space complexity is O(N) because we are taking an auxillary array
to add elements of merged array

T.C = O(NLOGN)
S.C = O(N)

This algorithm is better than the insertion, bubble, selection sort algorithms.
because of the Time complexity.

*/



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
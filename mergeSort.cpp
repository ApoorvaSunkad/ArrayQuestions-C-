#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r)
    {
        m = (l+r)/2;

        int len1 = m-l+1;
        int len2 = r-m;

        int *first = new int[len1];
        int *second = new int[len2];

        //copy values
        int mainArrayIndex = l;
        for(int i = 0; i<len1;i++){
           first[i] = arr[mainArrayIndex++];
        }
        mainArrayIndex =  m+1;

        for(int i = 0; i<len2;i++){
           second[i] = arr[mainArrayIndex++];
        }

        //merge 2 sorted arrays
        int index1 = 0;
        int index2 = 0;

        mainArrayIndex = l;

        while(index1 < len1 && index2 < len2){
            if(first[index1] < second[index2]){
             arr[mainArrayIndex++] = first[index1++];
           }
           else{
             arr[mainArrayIndex++] = second[index2++];
           }
        }
        while(index1 < len1){
            arr[mainArrayIndex++] = first[index1++];
        }
        while(index2 < len2){
            arr[mainArrayIndex++] = second[index2++];
        }

        //Deallocating the memory
        delete []first;
        delete []second;

}
void mergeSort(int arr[], int l, int r)
{
        //base case
        if(l>=r){
           return;
        }

       int m = (l+r)/2;

       //sorting left part
       mergeSort(arr,l,m);

       //sorting right part
       mergeSort(arr,m+1,r);

       //merge
       merge(arr,l,m,r);
}
int main(){
    int arr[5] = {2,8,10,4,1};
    int n = 5;

    mergeSort(arr,0,4);
    for(int i = 0; i<n;i++){
        cout << arr[i] << " ";
    }
}
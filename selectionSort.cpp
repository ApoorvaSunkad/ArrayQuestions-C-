/*
The selection sort algorithm works by finding the smallest element in the array and 
placing it to its correct place 

The time complexity of the algorithm is 
the first loop runs till n-1 then n-2,n-2,n-4
so it is like sum of first n natural numbers

n*(n+1)/2 = which boils down to O(N^2)

Disadvantage - This algorithm is not suitable for larger inputs
and also this algorithm is not a stable algorithm which means the relative order
of the elements will not be maintained.
*/

#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[],int n){
    for(int i = 1; i<=n-1;i++){
        int mini = i-1;
        for(int j = i-1; j<=n-1;j++){
            if(arr[j]<arr[mini]){
                mini = j;
            }
        }
        swap(arr[mini],arr[i-1]);
    }
}
int main(){
    int arr[] = {9,1,4,5,2};

    int n = 5;

    selectionSort(arr,n);
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
}
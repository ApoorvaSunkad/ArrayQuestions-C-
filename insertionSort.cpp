//Insertion sort algorithm works same as how we arrange the playing cards
//In this algorithm lets say we have an array {4,3,2,10,1,5,12,6}
//we will start the loop with the first ele of array i.e 3 we store it in a key
// and we run another loop in reverse order to compare the jth element with the key
//if its greater than key then will change the first ele i.e 3 to 4 and we will decrease
//j pointer and after inner loop completes we will put key in the arr[j+1]

//For better understanding watch this video:
//https://www.youtube.com/watch?v=p1iDSL13gag&t=1050s


#include<bits/stdc++.h>
using namespace std;

//T.C = Worst case will be O(N^2)
//Best case O(N) if the array is already sorted
//Avg case also O(N^2)


void insertionSort(int arr[], int n){
    for(int i = 1; i<=n-1;i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
int main(){
    int arr[] = {4,3,2,10,1,5,12,6};

    int n = 8;

    insertionSort(arr,n);
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
}
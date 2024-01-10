/*
This is explained by Prince aggarwal - Youtube channel - HELLO WORLD

*/

//You have given an array that contains both positive and negative values which are
//in the range from -MAX to MAX Assume MAX = 1000

//our task is to search some number is present in array or not in O(1) time

#include<bits/stdc++.h>
using namespace std;

#define MAX 1000

bool hashTable[MAX+1][2]; //Creating a 2D array to store the values and their keys in this array.
//here in this hash array automatically all the values will be 0.

bool search(int key){
    if(key>=0){
        if(hashTable[key][0] == 1){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        key = abs(key);
        if(hashTable[key][1] == 1){
            return true;
        }
        else{
            return false;
        }
    }
}

void insert(int a[], int n){
    for(int i = 0; i<n; i++){
        if(a[i]>0){
            hashTable[a[i]][0] = 1;
        }
        else{
            hashTable[abs(a[i])][1] = 1;
        }
    }
}
int main()
{
    int arr[] = {2, -1, 3, 4, -6};
    int n = sizeof(arr)/sizeof(arr[0]);
    insert(arr,n);
    int find = 5;

    if(search(find)){
        cout << "Element is present " << endl;
    }
    else{
        cout << "Element is not present " << endl;
    }
}
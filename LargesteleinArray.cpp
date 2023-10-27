/*
Given an array A[] of size n. The task is to find the largest element in it.
 

Example 1:

Input:
n = 5
A[] = {1, 8, 7, 56, 90}

Output:
90

*/


#include<bits/stdc++.h>
using namespace std;

int largest(vector<int> &arr, int n)
    {
        int maxwell = INT_MIN;
        for(int i = 0; i<n;i++){
            if(arr[i] > maxwell){
                maxwell = arr[i];
            }
        }
        return maxwell;
        
    }
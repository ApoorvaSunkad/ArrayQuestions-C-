/*
Given an array Arr of size N, print second largest distinct element from an array.

Example 1:

Input: 

N = 6
Arr[] = {12, 35, 1, 10, 34, 1}
Output: 34

Explanation: The largest element of the 
array is 35 and the second largest element
is 34.

*/

#include<bits/stdc++.h>
using namespace std;

int print2largest(int arr[], int n) {
	    // code here
	    int max = INT_MIN;
	    int Smax = -1;
        for(int i = 0; i<n;i++){
            if(arr[i] > max){
                Smax = max;
                max = arr[i];
            }
            else if(arr[i]>Smax && arr[i]!=max){
                Smax = arr[i];
            }
        }
        return Smax;
}
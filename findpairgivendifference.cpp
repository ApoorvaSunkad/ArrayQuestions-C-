/*
Given an array Arr[] of size L and a number N, you need to write a program to find if 
there exists a pair of elements in the array whose difference is N.

Example 1:

Input:
L = 6, N = 78
arr[] = {5, 20, 3, 2, 5, 80}
Output: 1
Explanation: (2, 80) have difference of 78.

Input:
L = 5, N = 45
arr[] = {90, 70, 20, 80, 50}
Output: -1
Explanation: There is no pair with difference of 45.

*/

//Brute force approach
//T.C = O(N^2)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

bool findPair(int arr[], int size, int n){
    for(int i = 0; i<size;i++){
        for(int j = i+1; j<size;j++){
            if((long long)abs(arr[i]-arr[j])==n){
                return true;
            }
        }
    }
    return false;
}


//Optimised approach: using binary search
//T.C =
//S.C =

#include<bits/stdc++.h>
using namespace std;



/*
You are given an array Arr of size N. You need to find all pairs in the array that sum to 
a number K. If no such pair exists then output will be -1. The elements of the array are 
distinct and are in sorted order.
Note: (a,b) and (b,a) are considered same. Also, an element cannot pair with itself, 
i.e., (a,a) is invalid.

Example 1:

Input:
n = 7
arr[] = {1, 2, 3, 4, 5, 6, 7}
K = 8
Output:
3
Explanation:
We find 3 such pairs that
sum to 8 (1,7) (2,6) (3,5)

Example 2:

Input:
n = 7
arr[] = {1, 2, 3, 4, 5, 6, 7}
K = 98 
Output:
-1 


*/


//Brute force approach:
//T.C = O(N^2)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

int Countpair(int arr[], int n, int sum){
    
    int cntPairs = 0;
        
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(arr[i]+arr[j]==sum){
                    cntPairs++;
            }
        }
    }
        
    if(cntPairs == 0){
        return -1;
    }
        
    return cntPairs;
}


//Optimal approach:
//T.C = O(N)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

int Countpair(int arr[], int n, int sum){
    
    int cntPairs = 0;
        
    int i = 0, j = n-1;
        
    while(i<j){
        if(arr[i]+arr[j] == sum){
            cntPairs++;
            i++;
            j--;
        }
        else if(arr[i]+arr[j] < sum){
            i++;
        }
        else{
            j--;
        }
    }

    if(cntPairs == 0){
        return -1;
    }
        
    return cntPairs;  
    
}
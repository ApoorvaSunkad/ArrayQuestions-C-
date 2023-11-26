/*
Given a sorted array containing only 0s and 1s, find the transition point, i.e., 
the first index where 1 was observed, and before that, only 0 was observed.

Example 1:

Input:
N = 5
arr[] = {0,0,0,1,1}
Output: 3
Explanation: index 3 is the transition 
point where 1 begins.
Example 2:

Input:
N = 4
arr[] = {0,0,0,0}
Output: -1
Explanation: Since, there is no "1",
the answer is -1.

*/

//Brute force:
//T.C = O(N)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n) { 
        int ans = -1;
        for(int i = 0; i<n;i++){
            if(arr[i] == 1){
                ans = i;
                break;
            }
        }
        return ans;
}


//Optimised solution: Using Binary search

//T.C = O(Log N)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n) {
        // code here
        int s = 0 , e = n-1 ;
        int mid = s+(e-s)/2 ;
        while(s<=e){
            if(arr[mid]==1 && arr[mid-1]==0){
                return mid  ;
            }
            if( arr[mid] == 0){
                s = mid +1 ;
            }
            if( arr[mid] == 1){
                e = mid ;
            }
            mid = s + (e-s)/2 ;
        }
        return -1 ;
} 
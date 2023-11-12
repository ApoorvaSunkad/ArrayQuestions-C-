/*
Given an array of positive numbers, the task is to find the number of 
possible contiguous subarrays having product less than a given number k.

Example 1:

Input : 
n = 4, k = 10
a[] = {1, 2, 3, 4}
Output : 
7

Explanation:
The contiguous subarrays are {1}, {2}, {3}, {4} 
{1, 2}, {1, 2, 3} and {2, 3}, in all these subarrays
product of elements is less than 10, count of
such subarray is 7.
{2,3,4} will not be a valid subarray, because 
2*3*4=24 which is greater than 10.

*/
//Brute force approach done by me
//T.C = O(N^2)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

long long countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long cnt = 0;
        
        for(int i = 0; i<n; i++){
            long long prod = 1;
            for(int j = i; j<n;j++){
                prod = prod*a[j];
                if(prod < k){
                    cnt++;
                }else{
                    break;
                }
            }
        }
        return cnt;
}
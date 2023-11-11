/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.


Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2

*/

//Brute force approach:
//T.C = O(N^3)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        
        for(int i = 0; i<n;i++){
            for(int j = i; j<n;j++){
                int sum = 0;
                for(int m = i; m<=j;m++){
                    sum+=nums[m];
                }
                if(sum == k){
                    cnt++;
                }
            }
        }
        return cnt;
}

//Better Approach
//T.C = O(N^2)
//S.C = O(1)

int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        
        for(int i = 0; i<n;i++){
            int sum = 0;
            for(int j = i; j<n;j++){
                sum+=nums[j];
                if(sum == k){
                    cnt++;
                }
            }
        }
        return cnt;
}

//Optimized Approach- Prefix sum - striver's video

//T.C = O(N * Log N) -> because we are using an unordered map which in worst case can
//take logN T.C
//S.C = O(N) in worst case because of unodered map
int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;

        mp[0] = 1;

        int preSum = 0, cnt  = 0;

        for(int i = 0; i<nums.size();i++){
            preSum+=nums[i];
            int remove = preSum - k;
            cnt+=mp[remove];
            mp[preSum] += 1;
        }
        return cnt;
}

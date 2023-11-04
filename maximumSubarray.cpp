/*
Given an integer array nums, find the 
subarray
with the largest sum, and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

*/
#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
        int sum = 0, maxi = INT_MIN;
        for(int i = 0; i<nums.size();i++){
            sum+=nums[i];
            maxi = max(maxi,sum);
            if(sum<0){
                sum = 0;
            }
            /* if(maxi < 0){
                maxi = 0;
            }  
            This piece of code should be written when the maximum is negative and
            if in question they have asked to return empty array */
        }
        return maxi;
}
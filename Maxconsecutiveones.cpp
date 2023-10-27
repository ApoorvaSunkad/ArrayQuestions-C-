/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.


Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. 
The maximum number of consecutive 1s is 3.

*/
#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0,cnt=0,ans=0;

        for(int i = 0; i<nums.size();i++){
            if(nums[i]==1){
                cnt++;
                ans = max(ans,cnt);
            }
            else if(nums[i] == 0){
                cnt = 0;
            }
        }
        return ans;
}
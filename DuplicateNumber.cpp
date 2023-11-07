/*
Given an array of integers nums containing n + 1 integers where each integer is in the 
range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant 
extra space.

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3

*/

#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {

        unordered_map<int,int>mp;

        for(int i = 0; i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            if(it.second > 1){
                return it.first;
            }
        }
        return 0;
}

//T.C = O(N)
//S.C = O(N)
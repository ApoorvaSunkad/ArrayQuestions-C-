/*
Given an array of integers nums and an integer target, return indices of the two numbers 
such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use 
the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

*/

//Brute force:
//T.C = O(N^2)
//S.C = O(1)
#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;

        for(int i = 0; i<nums.size();i++){
            for(int j = i+1; j<nums.size();j++){
                if(nums[i]+nums[j] == target){
                    v.push_back(i);
                    v.push_back(j);
                }
            }
        }
        return v;
}

//Optimised solution:
#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int x = target - num;
            if (mpp.find(x) != mpp.end()) {
               return {mpp[x],i};
            }
            mpp[num] = i;
        }
        return {-1,-1};
}


/*
Given an array nums of distinct integers, return all the possible permutations. 
You can return the answer in any order.


Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]

*/

#include<bits/stdc++.h>
using namespace std;

//Brute force approach: striver's recursion series video

/* T.C = O(N! * N) --> N! because if N = 3 then we are generating 6 permutations which is 
exaclty equal to 3! = 6.

where N is length of array and also we are returning permutations 
of N length only */

void recurPermute(vector<int>& v, vector<int>& nums,vector<vector<int>>& ans, int freq[]){
        //base case
        if(v.size()==nums.size()){
            ans.push_back(v);
            return;
        }
        for(int i = 0; i<nums.size();i++){
            if(!freq[i]){
                v.push_back(nums[i]);
                freq[i] = 1;
                recurPermute(v,nums,ans,freq);
                freq[i] = 0;
                v.pop_back();
            }
        }
}

vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;

        int freq[nums.size()];
        for(int i = 0; i<nums.size();i++) {
            freq[i] = 0;
        }
        recurPermute(v,nums,ans,freq);
        return ans;

}


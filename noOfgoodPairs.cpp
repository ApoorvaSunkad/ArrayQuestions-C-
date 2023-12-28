/*
Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.

 

Example 1:

Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
Example 2:

Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.
Example 3:

Input: nums = [1,2,3]
Output: 0

*/

#include<bits/stdc++.h>
using namespace std;

//Brute force: 
//T.C = O(N^2)
//S.C = O(1)

int numIdenticalPairs(vector<int>& nums) {
        int cntPairs = 0;
        int n = nums.size();

        for(int i = 0; i<n;i++){
            for(int j = i+1; j<n; j++){
                if(i<j && nums[i]==nums[j]){
                    cntPairs++;
                }
            }
        }
        return cntPairs;
}


//Using Hashing

//T.C = O(N)
//S.C = O(N)
int numIdenticalPairs(vector<int>& nums) {
    int ans=0;
    int n=nums.size();

    map<int,int> mp;
    
    for(auto it:nums) mp[it]++;
    for(auto it:mp) ans+=(it.second-1)*(it.second)/2;
    return ans;
}
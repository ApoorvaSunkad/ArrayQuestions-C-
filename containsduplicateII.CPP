/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105

*/

#include<bits/stdc++.h>
using namespace std;

//Brute force 
//T.C = O(N^2) got TLE error
//S.C = O(1)

bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int n = nums.size();

        for(int i =0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(nums[i] == nums[j] && abs(i - j) <= k){
                    return true;
                }
            }
        }
        return false;
}

//Optimised approach using map
//T.C = O(N)
//S.C = O(N)


bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for(int i = 0; i < nums.size(); i++){
            int val = nums[i];
                if(m.find(val) != m.end()){
                    if (i - m[val] <= k) {
                        return true; // Found a pair with difference <= k
                    }
                }
            m[val] = i;
    }
    return false;
}

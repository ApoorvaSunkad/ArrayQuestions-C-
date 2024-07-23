/*
Given an array of integers nums, sort the array in increasing 
order based on the frequency of the values. If multiple values 
have the same frequency, sort them in decreasing order.

Return the sorted array.

 

Example 1:

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, 
and '2' has a frequency of 3.

Example 2:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted 
in decreasing order.

Example 3:

Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]
 

Constraints:

1 <= nums.length <= 100
-100 <= nums[i] <= 100


*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

//T.C = O(NlogN)
//S.C = O(N)

vector<int> frequencySort(vector<int>& nums) {
    unordered_map<int, int> mp;
    for (int &num : nums) {
        mp[num]++;
    }

    auto lambda = [&](int &num1, int &num2) {
        if(mp[num1] == mp[num2]) {
            return num1 > num2;
        }

        return mp[num1] < mp[num2];
    };

    sort(begin(nums), end(nums), lambda);

    return nums;
}
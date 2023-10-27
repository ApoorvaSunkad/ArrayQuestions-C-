/*
Given an integer array nums, rotate the array to the right by k steps, 
where k is non-negative.


Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

*/
#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // To handle cases where k is greater than the array size

        // Create a temporary array of the same size as nums
        vector<int> temp(n);

       // Copy the last k elements to the beginning of temp
        for (int i = 0; i < k; i++) {
           temp[i] = nums[n - k + i];
        }

        // Copy the first n-k elements to the end of temp
        for (int i = k; i < n; i++) {
          temp[i] = nums[i - k];
        }

        // Copy the elements from temp back to nums
        for (int i = 0; i < n; i++) {
           nums[i] = temp[i];
        }
}
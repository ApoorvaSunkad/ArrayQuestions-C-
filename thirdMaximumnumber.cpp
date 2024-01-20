/*
Given an integer array nums, return the third distinct maximum number in this array. 
If the third maximum does not exist, return the maximum number.

 

Example 1:

Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.
Example 2:

Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.
Example 3:

Input: nums = [2,2,3,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same 
value).
The third distinct maximum is 1.
 
*/


//Brute force: Sorting
#include<bits/stdc++.h>
using namespace std;


//T.C = O(nlogn)
//S.C = O(1)

int thirdMax(vector<int>& nums) {
        // Sort the array in non-increasing order.
        sort(nums.begin(), nums.end(), greater<int>());
        
        int elemCounted = 1;
        int prevElem = nums[0];
        
        for (int index = 1; index < nums.size(); ++index) {
            // Current element is different from previous.
            if (nums[index] != prevElem) {
                elemCounted += 1;
                prevElem = nums[index];
            }
            
            // If we have counted 3 numbers then return current number.
            if (elemCounted == 3) {
                return nums[index];
            }
        }
        
        // We never counted 3 distinct numbers, return largest number.
        return nums[0];
}


//optimised solution - 3 pointers

//T.C = O(N)
//S.C = O(1)
int thirdMax(vector<int>& nums) {
        
         int maxi1 = INT_MIN;
        int maxi2 = INT_MIN;
        int maxi3 = INT_MIN;
        int flag = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > maxi1) {
                maxi3 = maxi2;
                maxi2 = maxi1;
                maxi1 = nums[i];
            }
            else if(nums[i] < maxi1 && nums[i] > maxi2) {
                maxi3 = maxi2;
                maxi2 = nums[i];
            }
            else if(nums[i] < maxi2 && nums[i] > maxi3) maxi3 = nums[i];

            if(nums[i] == INT_MIN) flag = 1;
        }

        if(nums.size() < 3) return maxi1;
        if(nums.size() >= 3 && flag == 0 && maxi3 == INT_MIN) return maxi1;
        if(flag == 1 && maxi2 == INT_MIN) return maxi1;
        return maxi3;

}

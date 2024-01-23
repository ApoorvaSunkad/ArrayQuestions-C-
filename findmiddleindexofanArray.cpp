/*
Given a 0-indexed integer array nums, find the leftmost middleIndex (i.e., the smallest 
amongst all the possible ones).

A middleIndex is an index where nums[0] + nums[1] + ... + 
nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] + ... + 
nums[nums.length-1].

If middleIndex == 0, the left side sum is considered to be 0. Similarly, 
if middleIndex == nums.length - 1, the right side sum is considered to be 0.

Return the leftmost middleIndex that satisfies the condition, or -1 if there is no 
such index.

 

Example 1:

Input: nums = [2,3,-1,8,4]
Output: 3
Explanation: The sum of the numbers before index 3 is: 2 + 3 + -1 = 4
The sum of the numbers after index 3 is: 4 = 4
Example 2:

Input: nums = [1,-1,4]
Output: 2
Explanation: The sum of the numbers before index 2 is: 1 + -1 = 0
The sum of the numbers after index 2 is: 0
Example 3:

Input: nums = [2,5]
Output: -1
Explanation: There is no valid middleIndex.

*/

//Using extra Array
//Using the concept of prefix and suffix sum

#include<bits/stdc++.h>
using namespace std;

//T.C = O(N)
//S.C = O(N)

int findMiddleIndex(vector<int>& nums) {
    int n = nums.size();

    long long prefixSum[n];
    long long suffixSum[n];
    if(n==1)return 0;
    for(int i=1;i<n;i++){
        prefixSum[0]=nums[0];
        prefixSum[i]=prefixSum[i-1]+nums[i];
    }
    for(int i=n-2;i>=0;i--){
        suffixSum[n-1]=nums[n-1];
        suffixSum[i]=suffixSum[i+1]+nums[i];
    }
    for(int i=0;i<n;i++){
        if(prefixSum[i]==suffixSum[i]){
            return i;
        }
    }
    return -1;
}

//Single pass
//T.C = O(N)
//S.C = O(1)

int findMiddleIndex(vector<int>& nums) {
    int sumLeft = 0 ;
    int sumRight = 0 ;
    for (int i=0; i<nums.size(); i++){
        sumRight += nums[i] ;
    }
    for (int i=0; i<nums.size(); i++){
        if (i==0) sumLeft = 0 ;
        else sumLeft += nums[i-1] ;
        sumRight -= nums[i] ;
        if (sumLeft == sumRight) return i ;
    }
    return -1 ;
}


//This question is same as finding Pivot in an array
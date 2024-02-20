/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 
Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 
2 is the missing number in the range since it does not appear in nums.

*/

//Brute force 1:

//Using map
//T.C = O(2N)
//S.C = O(N)

int missingNumber(vector<int>& nums) {
    int n = nums.size();

    map<int,int> mp;

    for(int i = 0; i<n; i++){
        mp[nums[i]]++;
    }

    for(int i = 0; i<=n; i++){
        int key = i;
        if(mp.find(key)==mp.end()){
            return key;
        }
    }
    return 0;
}

//2nd brute force
//T.C = O(N)
//S.C = O(1)
#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n)*(n+1)/2;
        int sum1 = 0;
        for(int i = 0; i<nums.size();i++){
            sum1+=nums[i];
        }
        int diff = sum-sum1;
        return diff;
}


//Optimised Solution: Using bit manipulation(XOR operator)
//T.C = O(N)
//S.C = O(1)

int missingNumber(vector<int>& nums) {
    int Xorr = 0;

    for(int i = 0; i<=nums.size(); i++){
        Xorr = Xorr^i;
    }

    for(int i = 0; i<nums.size(); i++){
        Xorr = Xorr^nums[i];
    }

    return Xorr;
}
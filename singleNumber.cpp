/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.


Example 1:

Input: nums = [2,2,1]
Output: 1

*/

//Brute force method: Using maps
#include<bits/stdc++.h>
using namespace std;

//T.C = O(N)
//S.C = O(N)

int singleNumber(vector<int>& nums) {

    unordered_map<int,int> mp;

    for(int i = 0; i<nums.size();i++){
        mp[nums[i]]++;
    }

    for(auto it:mp){
        if(it.second == 1){
            return it.first;
        }
    }
    return -1;
}

//Using sorting: Not constant space

#include<bits/stdc++.h>
using namespace std;
//T.C = O(NLOGN)
//S.C = O(1)
int singleNumber(vector<int>& nums) { 

    sort(nums.begin(),nums.end());

    for(int i=1;i<nums.size();i+=2)
    {
        if(nums[i]!=nums[i-1])
            return nums[i-1];
    }
    return nums[nums.size()-1];
}

//Using sets
//T.C = O(N^2)
//S.C = O(N)

#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums){
    unordered_set<int>st;
    for(int num:nums)
    {
        if(st.find(num)==st.end())
        {
            st.insert(num);
        }
        else
        {
            st.erase(num);
        }
    }
    return *st.begin();
}

//Using XOR
#include<bits/stdc++.h>
using namespace std;
int singleNumber(vector<int>& nums) {
        int xorr = 0;
        for(int i = 0; i<nums.size();i++){
            xorr = xorr ^ nums[i];
        }
        return xorr;
}
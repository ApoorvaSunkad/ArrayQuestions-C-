/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]

Output: [[-1,-1,2],[-1,0,1]]

Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

*/

//brute Force:
//T.C = O(N^3)
//S.C = O(No. of triplets)
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        for(int i = 0; i<nums.size();i++){
            for(int j = i+1; j<nums.size();j++){
                for(int k = j+1;k<nums.size();k++){
                    if(nums[i]+nums[j]+nums[k] == 0){
                       vector<int> triplet = {nums[i], nums[j], nums[k]};
                       sort(triplet.begin(),triplet.end());
                       st.insert(triplet);
                    }
                }
                
            }
        }
        vector<vector<int>> v(st.begin(),st.end());
        return v;
}

//Better approach:

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;

        for(int i = 0; i<nums.size();i++){
            set<int> hashset;
            for(int j = i+1; j<nums.size();j++){
                int third = -(nums[i]+nums[j]);
                if(hashset.find(third)!=hashset.end()){
                    vector<int> temp = {nums[i],nums[j],third};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }


//Optimal Solution:

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j = i+1;
            int k = nums.size()-1;

            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j < k && nums[j]==nums[j-1]) j++;
                    while(j < k && nums[k]==nums[k+1]) k--;
                }
            }

        }
        return ans;
    }




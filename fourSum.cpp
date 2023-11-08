/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.


Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

*/

//Brute force approach
//T.C = O(N^4)
//S.C = O(N^4)
//Error: TLE

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
set<vector<int>> st;
        for(int i = 0; i<nums.size();i++){
            for(int j = i+1; j<nums.size();j++){
                for(int k = j+1;k<nums.size();k++){
                    for(int l = k+1; l<nums.size();l++){
                       if(nums[i]+nums[j]+nums[k]+nums[l] == target){
                          vector<int> qudralet = {nums[i], nums[j], nums[k],nums[l]};
                          sort(qudralet.begin(),qudralet.end());
                          st.insert(qudralet);
                        }
                    }
                }
                
            }
        }
        vector<vector<int>> v(st.begin(),st.end());
        return v;
}

//better approach
//T.C = O(N^3*Log(M)) - for hashset used (watch striver's video)
//S.C = O(N)*O(Quads * 2)

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st;
        for(int i = 0; i<nums.size();i++){
            for(int j = i+1; j<nums.size();j++){
                set<long long> hashset;
                for(int k = j+1;k<nums.size();k++){
                    int sum = nums[i]+nums[j];
                    sum+=nums[k];
                    long long fourSum = target - sum;
                    if(hashset.find(fourSum)!=hashset.end()){
                      vector<int> qudralet = {nums[i], nums[j], nums[k],(int)fourSum};
                      sort(qudralet.begin(),qudralet.end());
                      st.insert(qudralet);
                    }
                    hashset.insert(nums[k]);
                }
                
            }
        }
        vector<vector<int>> v(st.begin(),st.end());
        return v;
}


//Optimal solution:
// T.C = O(N^3) because 2 "for" loops and 1 while loop which runs almost for "n" times in 
// worst case
//S.C = O(no. of qudralets)


vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size(); //size of the array
        vector<vector<int>> ans;

        // sort the given array:
        sort(nums.begin(), nums.end());

       //calculating the quadruplets:
    for (int i = 0; i < n; i++) {
        // avoid the duplicates while moving i:
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            // avoid the duplicates while moving j:
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // 2 pointers:
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++; l--;

                    //skip the duplicates:
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
                else if (sum < target) k++;
                else l--;
            }
        }
    }
     return ans;
}
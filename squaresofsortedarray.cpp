/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares 
of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

*/

#include<bits/stdc++.h>
using namespace std;

//T.C = O(nlogN)
//S.C = O(1)

//Brute force
vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        
        
        for(int i = 0; i<n; i++){
            nums[i] = nums[i]*nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
}


//Two pointer approach
//T.C = O(N)
//S.C = O(N)

#include<bits/stdc++.h>
using namespace std;


vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> v(n);

        int i = 0, j = n-1;

        for(int k = n-1; k>=0; k--){
            if(abs(nums[i])>abs(nums[j])){
                v[k] = nums[i]*nums[i];
                i++;
            }
            else{
                v[k] = nums[j]*nums[j];
                j--;
            }
        }
        return v;
}

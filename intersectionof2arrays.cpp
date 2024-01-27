/*
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must be unique and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000

*/

//Using hash set
//T.C - O(m + n + m * log n)
//In the worst case, this operation takes O(log n) time for each element, 
//resulting in a total of O(m * log n) time complexity.

//S.C - O(m + n + min(m, n))

#include<bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    
    vector<int> v;
    
    set<int> s1;
    set<int> s2;
    
    for(int i = 0; i<m; i++){
        s1.insert(nums1[i]);
    }
    
    for(int i = 0; i<n; i++){
        s2.insert(nums2[i]);
    }
    
    for(auto it = s1.begin(); it!=s1.end(); it++){
        int val = (*it);
        if(s2.find(val) != s2.end()){
            v.push_back(val);
        }
    }
    
    return v;
}
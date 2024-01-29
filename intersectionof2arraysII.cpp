/*
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must appear as many 
times as it shows in both arrays and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
 

Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you 
cannot load all elements into the memory at once?

*/

#include<bits/stdc++.h>
using namespace std;

//T.C - O(n1 + n2), where n1 and n2 are the sizes of the input arrays nums1 and nums2
//S.C - O(n1 + n2)

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
    vector<int> v;
    
    int n1 = nums1.size();
    int n2 = nums2.size();
    
    unordered_map<int,int> mp1;
    unordered_map<int,int> mp2;
    
    for(int i = 0; i<n1; i++){
        mp1[nums1[i]]++;
    }
    
    for(int i = 0; i<n2; i++){
        mp2[nums2[i]]++;
    }
    
    for(auto it:mp1){
        int key = it.first;
        if(mp2.find(key)!=mp2.end()){
            int commonFreq = min(it.second, mp2[key]);
            while(commonFreq--){
                v.push_back(key);
            }
        }
    }
    return v;
}
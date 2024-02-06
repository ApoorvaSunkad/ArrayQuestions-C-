/*
Given two 0-indexed integer arrays nums1 and nums2, return a list answer of 
size 2 where:

answer[0] is a list of all distinct integers in nums1 which are not present in 
nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in 
nums1.
Note that the integers in the lists may be returned in any order.

 

Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4,6]
Output: [[1,3],[4,6]]
Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 
and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].

Example 2:

Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
Output: [[3],[]]
Explanation:
For nums1, nums1[2] and nums1[3] are not present in nums2. Since 
nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
-1000 <= nums1[i], nums2[i] <= 1000


*/

#include<bits/stdc++.h>
using namespace std;

//My solution
//T.C = O(N1+N2)
//S.C = O(N1+N2)

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

    vector<vector<int>> v;

    int n1 = nums1.size();
    int n2 = nums2.size();

    unordered_set<int>st1;
    unordered_set<int>st2;
    unordered_set<int> added1; // To keep track of elements already added to diff1
    unordered_set<int> added2;

    for(int i = 0; i<n1; i++){
        st1.insert(nums1[i]);
    }

    for(int i = 0; i<n2; i++){
        st2.insert(nums2[i]);
    }

    vector<int> diff1; // to store distinct integers in nums1 not present in nums2
    vector<int> diff2;
    

    for(int i = 0; i<n1; i++){
        int key = nums1[i];
        if(st2.find(key)==st2.end() && added1.find(key) == added1.end()){
            diff1.push_back(key);
            added1.insert(key);
        }
    }

    for(int i = 0; i<n2; i++){
        int key = nums2[i];
        if(st1.find(key)==st1.end() && added2.find(key) == added2.end()){
            diff2.push_back(key);
            added2.insert(key);
        }
    }

    v.push_back(diff1);
    v.push_back(diff2);

    return v;
}

//2nd solution

#include<bits/stdc++.h>
using namespace std;

//T.C = O(N+M)
//S.C = O(N+M)

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        
        vector<int> distinct_nums1, distinct_nums2;
        for (int num : set1) {
            if (set2.count(num) == 0) {
                distinct_nums1.push_back(num);
            }
        }

        for (int num : set2) {
            if (set1.count(num) == 0) {
                distinct_nums2.push_back(num);
            }
        }

        return {distinct_nums1, distinct_nums2};
    }
/*
Given an unsorted array Arr of size N of positive integers. One number 'A' 
from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. 
Find these two numbers.

Example 1:

Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.

*/

#include<bits/stdc++.h>
using namespace std;

//brute force approach
//T.C = O(N)
//S.C = O(1)

vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int> v;
        
        unordered_map<int,int>m;
        
        for(int i = 0; i<n;i++){
            m[arr[i]]++;
        }
        
        for(auto it:m){
            if(it.second>1){
                v.push_back(it.first);
            }
        }
        
        for (int i = 1; i <= n; i++) {
        if (m.find(i) == m.end()) {
            v.push_back(i); // Finding the missing number
            break;
        }
    }
    return v;
}
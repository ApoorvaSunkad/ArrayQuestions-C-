/*
Union of two arrays can be defined as the common and distinct elements in the two arrays.
Given two sorted arrays of size n and m respectively, find their union.


Example 1:

Input: 
n = 5, arr1[] = {1, 2, 3, 4, 5}  
m = 3, arr2 [] = {1, 2, 3}
Output: 1 2 3 4 5
Explanation: Distinct elements including 
both the arrays are: 1 2 3 4 5.
 

Example 2:

Input: 
n = 5, arr1[] = {2, 2, 3, 4, 5}  
m = 5, arr2[] = {1, 1, 2, 3, 4}
Output: 1 2 3 4 5
Explanation: Distinct elements including 
both the arrays are: 1 2 3 4 5.
 

Example 3:

Input:
n = 5, arr1[] = {1, 1, 1, 1, 1}
m = 5, arr2[] = {2, 2, 2, 2, 2}
Output: 1 2
Explanation: Distinct elements including 
both the arrays are: 1 2.

Your Task: 
You do not need to read input or print anything. Complete the function findUnion() 
that takes two arrays arr1[], arr2[], and their size n and m as input parameters and 
returns a list containing the union of the two arrays. 
 

Expected Time Complexity: O(n+m).
Expected Auxiliary Space: O(n+m).


*/

//Using set
#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(n + m + s)
//Space Complexity: O(n + m)

vector<int> findUnion(int arr1[], int arr2[], int n, int m){
        //Your code here
        //return vector with correct order of elements
    
        
        set<int> s;
        vector<int> v;
        
        for(int i = 0; i<n; i++){
            s.insert(arr1[i]);
        }
        
        for(int i = 0; i<m; i++){
            s.insert(arr2[i]);
        }
        
        for(auto itr = s.begin(); itr!=s.end(); itr++){
            v.push_back(*itr);
        }
        
        return v;
}
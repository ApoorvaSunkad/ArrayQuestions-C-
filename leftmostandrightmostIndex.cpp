/*
Given a sorted array with possibly duplicate elements. The task is to find indexes of 
first and last occurrences of an element X in the given array.

Note: If the element is not present in the array return {-1,-1} as pair.

 

Example 1:

Input:
N = 9
v[] = {1, 3, 5, 5, 5, 5, 67, 123, 125}
X = 5
Output:
2 5
Explanation:
Index of first occurrence of 5 is 2
and index of last occurrence of 5 is 5.
Example 2:

Input:
N = 9
v[] = {1, 3, 5, 5, 5, 5, 7, 123, 125}
X = 7
Output:
6 6

*/

#include<bits/stdc++.h>
using namespace std;


//My code: Brute force
//T.C = O(N)
//S.C = O(1)

pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        pair<long,long> p;
        
        p.first = -1;
        p.second = -1;
        
        int n = v.size();
        
        for(int i = 0; i<n; i++){
            if(v[i]==x){
                p.first = i;
                break;
            }
        }
        
        for(int i = n-1; i>=0; i--){
            if(v[i]==x){
                p.second = i;
                break;
            }
        }
        
        return p;
        
        
}

//Optimal is using binary search
//this is question is exact copy of first and last occurrances so please check that out.
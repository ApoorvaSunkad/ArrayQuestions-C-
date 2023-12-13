/*
Given a vector of N positive integers and an integer X. The task is to find the 
frequency of X in vector.

Example 1:

Input:
N = 5
vector = {1, 1, 1, 1, 1}
X = 1
Output: 
5
Explanation: Frequency of 1 is 5.

*/

//Brute force:
//T.C = O(N)
//S.C = O(N)

#include<bits/stdc++.h>
using namespace std;

int findFrequency(vector<int> v, int x){
    // Your code here
    int ans = 0;
    unordered_map<long long int,long long int> mp;
    
    for(int i = 0; i<v.size();i++){
        mp[v[i]]++;
    }
    
    for(auto it:mp){
        if(it.first == x){
            ans = it.second;
        }
        
    }
    return ans;
}

//2 Optimised solutions

//T.C = O(N)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

int findFrequency(int arr[], int x){
      int co=0;
        for(int i=0;i<arr.length;i++){
           
            if(x==arr[i])
            co++;
        }
        return co;
}


//Using lower bound and upper bound

#include<bits/stdc++.h>
using namespace std;

int findFrequency(vector<int> v, int x){
    
    sort(v.begin(), v.end());  // Sort the vector in ascending order
    
    auto lo = v.begin(), high = v.begin();  // Initialize two iterators
    
    lo = lower_bound(v.begin(), v.end(), x);  // Find the lower bound of x in the vector
    high = upper_bound(v.begin(), v.end(), x);  // Find the upper bound of x in the vector
    
    return (high - lo);  // Return the frequency of x by subtracting the lower bound from the upper bound
}

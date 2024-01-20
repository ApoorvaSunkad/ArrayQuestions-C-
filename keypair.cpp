/*

Given an array Arr of N positive integers and another number X. Determine whether or not 
there exist two elements in Arr whose sum is exactly X.

Example 1:

Input:
N = 6, X = 16
Arr[] = {1, 4, 45, 6, 10, 8}
Output: Yes
Explanation: Arr[3] + Arr[4] = 6 + 10 = 16
Example 2:

Input:
N = 5, X = 10
Arr[] = {1, 2, 4, 3, 6}
Output: Yes
Explanation: Arr[2] + Arr[4] = 4 + 6 = 10
Your Task:
You don't need to read input or print anything. Your task is to complete the function 
hasArrayTwoCandidates() which takes the array of integers arr, n and x as parameters and 
returns a boolean denoting the answer.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

*/


//Brute force: using two nested for loops
//T.C => got TLE

#include<bits/stdc++.h>
using namespace std;

bool hasArrayTwoCandidates(int arr[], int n, int x) {
	for(int i = 0; i<n; i++){
	    for(int j = i+1; j<n;j++){
	        if(arr[i]+arr[j]==x){
	            return true;
	        }
	    }
	}
	return false;
}


//Using unordered_set 
//But there is a loop hole here
//by using set it can count the same element 2 times hence the output will not be correct

#include<bits/stdc++.h>
using namespace std;


bool hasArrayTwoCandidates(int arr[], int n, int x) {

	unordered_set<int> s;
	for(int i = 0; i<n; i++){
	    s.insert(arr[i]);
	}
	   
	for(int i = 0; i<n; i++){
	    int key = arr[i];
	    int ans = x-key;
	    if(s.find(ans) != s.end()){
	        return true;
	    }
	}

	return false;
}

/*
Example why the unordered_set fails
For Input: 
5 4
1 2 5 6 7
Your Code's output is: 
Yes
It's Correct output is: 
No

Dry run this example for above code for unordered set code and see why it fails

*/


//Optimal approach: Using unordered map 
//T.C = O(N)
//S.C = O(N)

bool hasArrayTwoCandidates(int arr[], int n, int x) {
	   
	unordered_map<int,int> mp;
	for(int i = 0; i<n; i++){
	    mp[arr[i]]++;
	}
	   
	for(auto it=mp.begin(); it!=mp.end(); it++){
	    int key = it->first;
	    int value = it->second;
	      
	    int pair = x-key;
	    if(pair == key){
	       if(value > 1){
	            return true;
	        }
	    }
	    else{
	        if(mp.find(pair)!=mp.end()){
	            return true;
	        }
	    }
	}
	return false;
}
//Dry run this code too for better understanding 

//Also watch "Hello world" youtube channel for this question

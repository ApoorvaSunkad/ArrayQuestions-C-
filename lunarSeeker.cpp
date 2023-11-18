/*

QUESTION: LUNAR SEEKER: FIND THE MINI CHAMP

Chandrayaan-3, the lunar exploration mission, has gathered a dataset of N integer values 
representing various lunar attributes. Your task is to analyze this lunar data.

Given an integer arrayA of size N and another integer B, your goal is to identify the 
smallest integer within the lunar data array that occurs at least B times. If there is no
integer within the dataset that meets or surpasses the B-frequency criterion, 
your function should return -1.

Example 1:

Input

5 2
2 3 4 4 3

Output
3

Example 2:

Input
5 3
2 5 6 3 2

Output
-1

*/
#include<bits/stdc++.h>
using namespace std;

//T.C = O(N)
//S.C = O(N)
/*
In the worst case, where all elements in A are unique, the space complexity is O(N).
In the best case, where all elements are the same, the space complexity is O(1).
Therefore, the space complexity is O(N) in the worst case and O(1) in the best case.
*/

int lunarSeeker(vector<int>& A, int B) {
		// write your code here
		map<int,int> mp;
		
		for(int i = 0; i<A.size();i++){
		    mp[A[i]]++;
		}
		for(auto it:mp){
		    if(it.second >= B){
		        return it.first;
		    }
		}
		return -1;
}
/*
Given an array of integers of size, N. Assume ‘0’ as the invalid number and all others 
as a valid number. Write a program that modifies the array in such a way that if the next 
number is a valid number and is the same as the current number, double the current number 
value and replace the next number with 0. After the modification, rearrange the array such 
that all 0’s are shifted to the end and the sequence of the valid number or new doubled 
number is maintained as in the original array.

Example 1:

â€‹Input : arr[ ] = {2, 2, 0, 4, 0, 8}
Output : 4 4 8 0 0 0
Explanation:
At index 0 and 1 both the elements are same.
So, we can change the element at index 0 to 
4 and element at index 1 is 0 then we shift 
all the values to the end of the array. 
So, array will become [4, 4, 8, 0, 0, 0].

Example 2:

Input : arr[ ] = {0, 2, 2, 2, 0, 6, 6, 0, 0, 8}
Output :  4 2 12 8 0 0 0 0 0 0

*/


//Brute force: My solution

#include<bits/stdc++.h>
using namespace std;

//T.C = O(N)
//S.C = O(N)

  void modifyAndRearrangeArr(int arr[], int n) 
    { 
    	// Complete the function
    	vector<int>v;
    	int cnt = 0;
    	
    	for(int i = 0; i<n; i++){
    	    if(arr[i]==arr[i+1]){
    	        arr[i] = 2*arr[i];
    	        arr[i+1] = 0;
    	    }
    	}
    	
    	for(int i = 0; i<n; i++){
    	    if(arr[i]==0){
    	        cnt++;
    	    }
    	}
    	
    	for(int i = 0; i<n; i++){
    	    if(arr[i]!=0){
    	        v.push_back(arr[i]);
    	    }
    	}
    	
    	for(int i = 0; i<cnt; i++){
    	    v.push_back(0);
    	}
    	
    	for(int i = 0; i<n; i++){
    	    arr[i] = v[i];
    	}
}


//Optimise solution
//T.C = O(N)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

void modifyAndRearrangeArr(int arr[], int n) { 
    	// Complete the function
    	int cnt = 0;

      // Modify the array in place
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] != 0 && arr[i] == arr[i + 1]) {
               arr[i] = 2 * arr[i];
               arr[i + 1] = 0;
           }
        }

        // Rearrange the array to shift zeros to the end
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
               swap(arr[cnt], arr[i]);
               cnt++;
            }
        }
}

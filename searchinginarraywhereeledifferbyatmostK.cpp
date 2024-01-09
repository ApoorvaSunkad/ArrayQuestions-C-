/*
A step array is an array of integers where each element has a difference of at most k 
with its neighbor. Given a key x, we need to find the index value of x if multiple elements 
exist, and return the first occurrence of the key.

Example 1:

Input : arr[ ] = {4, 5, 6, 7, 6}, K = 1 
        and X = 6
Output : 2
Explanation:
In an array arr 6 is present at index 2.
So, return 2.

Example 2:

Input : arr[ ] = {20 40 50}, K = 20 
        and X = 70
Output :  -1 
 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

*/


#include<bits/stdc++.h>
using namespace std;

//T.C = O(N)
//S.C = O(1)

int search(int arr[], int n, int x, int k)
{
    // Complete the function
    
    for(int i = 0; i<n; i++){
        if(arr[i]==x){
            return i;
            break;
        }
    }
    return -1;
    
}    	

//Taking advantage of fact that elements differ by k

//T.C = O(N)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int x, int k)
{
    // Complete the function
  // Travers the given array starting from
	// leftmost element
	int i = 0;
	while (i < n)
	{
		// If x is found at index i
		if (arr[i] == x)
			return i;

		// Jump the difference between current
		// array element and x divided by k
		// We use max here to make sure that i
		// moves at-least one step ahead.
		i = i + max(1, abs(arr[i]-x)/k);
	}

	return -1;
    
}    	
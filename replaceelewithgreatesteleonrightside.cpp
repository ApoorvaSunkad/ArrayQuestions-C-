/*
Given an array arr, replace every element in that array with the greatest element among 
the elements to its right, and replace the last element with -1.

After doing so, return the array.

 

Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
Explanation: 
- index 0 --> the greatest element to the right of index 0 is index 1 (18).
- index 1 --> the greatest element to the right of index 1 is index 4 (6).
- index 2 --> the greatest element to the right of index 2 is index 4 (6).
- index 3 --> the greatest element to the right of index 3 is index 4 (6).
- index 4 --> the greatest element to the right of index 4 is index 5 (1).
- index 5 --> there are no elements to the right of index 5, so we put -1.
Example 2:

Input: arr = [400]
Output: [-1]
Explanation: There are no elements to the right of index 0.
 

Constraints:

1 <= arr.length <= 104
1 <= arr[i] <= 105


*/

//Brute force: My solution
//T.C = O(N^2)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        
        for(int i = 0; i<n; i++){
            int maxi = INT_MIN;
            for(int j = i+1; j<n; j++){
                if(arr[j]>maxi){
                    maxi = arr[j];
                    arr[i] = maxi;
                }
            }
        }
        arr[n-1] = -1;
        return arr;
}

//Optimised solution - In one pass
//T.C = O(N)
//S.C = O(1)

vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxRight = -1; // Initialize maxRight to -1 since there are no elements to the right of the last one
    
        for (int i = n - 1; i >= 0; i--) {
            int currentElement = arr[i];
            arr[i] = maxRight; // Update current element with the maximum element to its right
            maxRight = max(maxRight, currentElement); // Update maxRight if the current element is greater
        }
        return arr;
}
/*
Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting 
the remaining elements to the right.

Note that elements beyond the length of the original array are not written. 
Do the above modifications to the input array in place and do not return anything.

 

Example 1:

Input: arr = [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]
Explanation: After calling your function, the input array is modified to: 
[1,0,0,2,3,0,0,4]

Example 2:

Input: arr = [1,2,3]
Output: [1,2,3]
Explanation: After calling your function, the input array is modified to: [1,2,3]
 

Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 9

*/

#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(n)
//Space Complexity: O(1)

void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        
        
        int a[10000];
        
        for (int i = 0, j = 0; i < n && j < n; ++i, ++j) {
            if (arr[i] != 0) {
               a[j] = arr[i];
            } else {
              a[j] = 0;
              ++j;
              if (j < n) {
                a[j] = 0;
              }
           }
        }

    // Copy elements from a back to arr
    for (int i = 0; i < n; ++i) {
        arr[i] = a[i];
    }
}
/*
Given an array arr[] of size N, find the prefix sum of the array. A prefix sum array is 
another array prefixSum[] of the same size, such that the value of prefixSum[i] is 
arr[0] + arr[1] + arr[2] . . . arr[i].

Examples: 

Input: arr[] = {10, 20, 10, 5, 15}
Output: prefixSum[] = {10, 30, 40, 45, 60}
Explanation: While traversing the array, update the element by adding it with its previous 
element.
prefixSum[0] = 10, 
prefixSum[1] = prefixSum[0] + arr[1] = 30, 
prefixSum[2] = prefixSum[1] + arr[2] = 40 and so on.


Approach: To solve the problem follow the given steps:

Declare a new array prefixSum[] of the same size as the input array
Run a for loop to traverse the input array
For each index add the value of the current element and the previous value of the prefix sum array
Below is the implementation of the above approach:

*/

//Time Complexity: O(N)
//Auxiliary Space: O(N)

#include <bits/stdc++.h> 
using namespace std; 
  
// Fills prefix sum array 
void fillPrefixSum(int arr[], int n, int prefixSum[]) 
{ 
    prefixSum[0] = arr[0]; 
    // Adding present element with previous element 
    for (int i = 1; i < n; i++) 
        prefixSum[i] = prefixSum[i - 1] + arr[i]; 
} 
  
// Driver Code 
int main() 
{ 
    int arr[] = { 10, 4, 16, 20 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int prefixSum[n]; 
    
      // Function call 
    fillPrefixSum(arr, n, prefixSum); 
    for (int i = 0; i < n; i++) 
        cout << prefixSum[i] << " "; 
} 


//Example
/*
Consider an array of size N with all initial values as 0. Perform the given ‘m’ 
add operations from index ‘a’ to ‘b’ and evaluate the highest element in the array. 
An add operation adds 100 to all the elements from a to b (both inclusive). 

Example:  

Input: n = 5, m = 3 
a = 2, b = 4.
a = 1, b = 3.
a = 1, b = 2.
Output: 300
Explanation: 
After I operation – A[] = {0, 100, 100, 100, 0}
After II operation – A[] = {100, 200, 200, 100, 0}
After III operation – A[] = {200, 300, 200, 100, 0}
Highest element: 300

Naive Approach: To solve the problem follow the below idea:

A simple approach is running a loop ‘m’ times. Inputting a and b and running a loop from 
a to b, adding all elements by 100. 

Time Complexity: O(N * M)
Auxiliary Space: O(1)

Efficient Approach: To solve the problem follow the below idea:

The efficient approach is to use Prefix Sum Array

Follow the given steps to solve the problem:

Run a loop for ‘m‘ times, inputting ‘a‘ and ‘b‘.
Add 100 at index ‘a-1‘ and subtract 100 from index ‘b‘.
After completion of ‘m‘ operations, compute the prefix sum array.
Scan the largest element and we’re done.
Explanation: We added 100 at ‘a’ because this will add 100 to all elements while 
taking the prefix sum array. Subtracting 100 from ‘b+1’ will reverse the changes made 
by adding 100 to elements from ‘b’ onward.

Below is the illustration of the above approach:

After I operation –
A[] = {0, 100, 0, 0, -100}

After II operation –
A[] = {100, 100, 0, -100, -100}

After III operation –
A[] = {200, 100, -100, -100, -100}

Final Prefix Sum Array : 200 300 200 100 0 
The required highest element : 300

Below is the implementation of the above approach:

*/

#include <bits/stdc++.h> 
using namespace std; 
  
int find(int m, vector<pair<int, int> > q) 
{ 
    int mx = 0; 
    vector<int> pre(5, 0); 
  
    for (int i = 0; i < m; i++) { 
        // take input a and b 
        int a = q[i].first, b = q[i].second; 
  
        // add 100 at first index and 
        // subtract 100 from last index 
  
        // pre[1] becomes 100 
        pre[a - 1] += 100; 
  
        // pre[4] becomes -100 and this 
        pre[b] -= 100; 
        // continues m times as we input diff. values of a 
        // and b 
    } 
    for (int i = 1; i < 5; i++) { 
        // add all values in a cumulative way 
        pre[i] += pre[i - 1]; 
  
        // keep track of max value 
        mx = max(mx, pre[i]); 
    } 
  
    return mx; 
} 
  
// Driver Code 
int main() 
{ 
  
    int m = 3; 
    vector<pair<int, int> > q 
        = { { 2, 4 }, { 1, 3 }, { 1, 2 } }; 
  
    // Function call 
    cout << find(m, q); 
    return 0; 
}

//Time Complexity: O(N + M), 
//where N is the size of the array and M is the number of operations
//Auxiliary Space: O(N)

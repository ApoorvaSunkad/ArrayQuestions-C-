/*

Given two sorted arrays arr and brr and a number x, find the pair whose sum is closest to 
x and the pair has an element from each array. In the case of multiple closest pairs return 
any one of them.
Note: Can return the two numbers in any manner. The driver code takes care of the printing 
of the closest difference.

Example 1:

Input : N = 4, M = 4
arr[ ] = {1, 4, 5, 7}
brr[ ] = {10, 20, 30, 40} 
X = 32
Output : 
1, 30
Explanation:
The closest pair whose sum is closest
to 32 is {1, 30} = 31.
Example 2:

Input : N = 4, M = 4
arr[ ] = {1, 4, 5, 7}
brr[ ] = {10, 20, 30, 40}
X = 50 
Output : 
7, 40 
Explanation: 
The closest pair whose sum is closest
to 50 is {7, 40} = 47.

*/

#include<bits/stdc++.h>
using namespace std;


//Brute force approach -> Got TLE Error
//T.C = O(N^2)
//S.C = O(1)

vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
        vector<int> v;
        
        int minDiff = INT_MAX;
        int res_a, res_b;
        
        
        for (int i = 0; i < n; i++) {
           for (int j = 0; j < m; j++) {
              int sum = arr[i] + brr[j];
              int diff = abs(sum - x);

               // Update the result if the current pair has a smaller difference
               if (diff < minDiff) {
                  minDiff = diff;
                  res_a = arr[i];
                  res_b = brr[j];
                }
           }
        }
        
        v.push_back(res_a);
        v.push_back(res_b);
        
        return v;
}

//Two pointer approach

//T.C = O(N)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
        vector<int> v;
        
        int minDiff = INT_MAX;
        int res_a, res_b;
        
        
        int i = 0, j = m-1;
      
        while(i<n && j>=0){
            
            int sum = arr[i] + brr[j];
            int diff = abs(sum - x);

            // Update the result if the current pair has a smaller difference
            if (diff < minDiff) {
                minDiff = diff;
                res_a = arr[i];
                res_b = brr[j];
            }
            if(sum>x){
                j--;
            }
            else{
                i++;
            }
       }
        
        v.push_back(res_a);
        v.push_back(res_b);
        
        return v;
}
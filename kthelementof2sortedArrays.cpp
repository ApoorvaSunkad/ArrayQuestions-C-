/*
Given two arrays arr1 and arr2 of size N and M respectively and an element K. The task is to find the element that would be at the kth position of the final sorted array.
 

Example 1:

Input:
arr1[] = {2, 3, 6, 7, 9}
arr2[] = {1, 4, 8, 10}
k = 5
Output:
6
Explanation:
The final sorted array would be -
1, 2, 3, 4, 6, 7, 8, 9, 10
The 5th element of this array is 6.

*/

//Brute force approach done by me
//T.C = O(N+M)
//S.C = O(N+M)

#include<bits/stdc++.h>
using namespace std;
vector<int> merge(int arr1[], int arr2[], int n,int m) {
        int i = 0;
        int j = 0;
      
      vector<int> temp;
      
        while(i < n && j < m){
            if(arr1[i]<arr2[j]){
              temp.push_back(arr1[i]);
              i++;
            }
            else{
               temp.push_back(arr2[j]);
               j++;
            }
        }
        // If there are remaining elements in arr1
        while (i < n) {
            temp.push_back(arr1[i]);
            i++;
        }

        // If there are remaining elements in arr2
        while (j < m) {
            temp.push_back(arr2[j]);
            j++;
        }
        return temp;
        
    }
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        vector<int> v;
        v = merge(arr1,arr2,n,m);
        
       if (k >= 1 && k <= v.size()) {
            return v[k - 1];
        } else {
            // Handle the case where k is out of bounds
            return -1;  // You can choose a suitable out-of-bounds indicator
        }
}
/*
Given two sorted arrays of distinct elements. There is only 1 difference between the arrays. 
First array has one element extra added in between. Find the index of the extra element.

Example 1:

Input:
N = 7
A[] = {2,4,6,8,9,10,12}
B[] = {2,4,6,8,10,12}
Output: 4
Explanation: In the second array, 9 is
missing and it's index in the first array
is 4.
Example 2:

Input:
N = 6
A[] = {3,5,7,9,11,13}
B[] = {3,5,7,11,13}
Output: 3
Your Task:
You don't have to take any input. Just complete the provided function findExtra() 
that takes array A[], B[] and size of A[] and return the valid index (0 based indexing).

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

*/

#include<bits/stdc++.h>
using namespace std;

//Brute force
//T.C = O(N)
//.C = O(1)

int findExtra(int a[], int b[], int n) {
        // add code here.
        
        int i=0;
        for(;i<n;i++){
            if(a[i]!=b[i]){
               break;
            }
        }
        return i;
}

//Using map 
//T.C = O(3N)
//S.C = O(N)

#include<bits/stdc++.h>
using namespace std;

int findExtra(int a[], int b[], int n) {
        // add code here.
        
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[a[i]]++;
        }

        for(int i=0;i<n-1;i++)
        {
            mp[b[i]]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(mp[a[i]]==1)
            {
                return i;
            }
        }
}

//Optimised solution
//T.C = O(LOGN)
//S.C = O(1)


int findExtra(int arr1[], int arr2[], int n)
{
    // Initialize result
    int index = n; 

    // left and right are end 
    // points denoting the current range.
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        // If middle element is same 
        // of both arrays, it means 
        // that extra element is after 
        // mid so we update left to mid+1
        if (arr2[mid] == arr1[mid])
            left = mid + 1;

        // If middle element is different 
        // of the arrays, it means that 
        // the index we are searching for 
        // is either mid, or before mid. 
        // Hence we update right to mid-1.
        else
        {
            index = mid;
            right = mid - 1;
        }
    }

    // when right is greater than 
    // left our search is complete.
    return index;
}
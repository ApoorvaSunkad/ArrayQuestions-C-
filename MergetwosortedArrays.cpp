/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be 
stored inside the array nums1. To accommodate this, nums1 has a length of m + n,
where the first m elements denote the elements that should be merged, and the last n 
elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]

*/
//Brute force:  
//T.C = O(N+M) + O(N+M)
//S.C = O(N+M)

#include<bits/stdc++.h>
using namespace std;

//watch striver's video for this question

void mergeTwoSortedArrays(vector<long long> &arr1, vector<long long> &arr2){

    int i=0,j=0;

    vector<long long>temp;

    int m=arr1.size(),n=arr2.size();

    while(i<m && j<n)

    {

        if(arr1[i]<=arr2[j])

        {

            temp.push_back(arr1[i]);

            i++;

        }
        else
        {
            temp.push_back(arr2[j]);

            j++;

        }
    }
    while(i<m)

    {

        temp.push_back(arr1[i]);

        i++;

    }

    while(j<n)

    {

        temp.push_back(arr2[j]);

        j++;

    }

    for(int i=0;i<m+n;i++)

    {

        if(i<m)

        arr1[i]=temp[i];

        else

        arr2[i-m]=temp[i];

    }
}


//Please watch ayushi sharma's video for this it is very nicely explained by her.
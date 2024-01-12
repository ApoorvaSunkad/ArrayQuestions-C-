/*
The hiring team aims to find 3 candidates who are great collectively. 
Each candidate has his or her ability expressed as an integer. 3 candidates are great 
collectively if product of their abilities is maximum. Given abilities of N candidates 
in an array arr[], find the maximum collective ability from the given pool of candidates.


Example 1:

Input:
N = 5
Arr[] = {10, 3, 5, 6, 20}
Output: 1200
Explanation:
Multiplication of 10, 6 and 20 is 1200.
Example 2:

Input:
N = 5
Arr[] = {-10, -3, -5, -6, -20}
Output: -90
Explanation:
Multiplication of -3, -5 and -6 is -90.

Your Task:
You don't need to read input or print anything. Your task is to complete the function 
maxProduct() which takes the array of integers arr[] and n as input parameters and returns 
the maximum product.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

*/

//Brute force approach
// Gives TLE

//T.C = O(N^3)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

long long maxProduct(int arr[], int n) {
        // code here
        long long maxProd = 1;
        
        long long maxi = LLONG_MIN;
        
        
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                for(int k = j+1; k<n; k++){
                    maxProd = arr[i]*arr[j]*arr[k];
                    maxi = max(maxProd, maxi);
                }
            }
        }
        return maxi;
}

//Sorting approach
//T.C = O(NLOGN)
//S.C = O(1)

long long maxProduct(int arr[], int n)
{
    // if size is less than 3, no triplet exists
    if (n < 3)
        return -1;

    // Sort the array in ascending order
    sort(arr, arr + n);

    // Return the maximum of product of last three
    // elements and product of first two elements
    // and last element
    return max(arr[0] * arr[1] * arr[n - 1],arr[n - 1] * arr[n - 2] * arr[n - 3]);
}


//Optimised approach

#include<bits/stdc++.h>
using namespace std;

//T.C = O(N)
//S.C = O(1)

long long maxProduct(int arr[], int n) {
        // code here
        
        if (n < 3){
           return -1;
        }
        
        long long prod=arr[0]*arr[1]*arr[2];
        long long maxi = prod;
        long long maxA = INT_MIN;
        long long maxB = INT_MIN;
        long long maxC = INT_MIN;
        
        long long minA = INT_MAX;
        long long minB = INT_MAX;
        long long minC = INT_MAX;
        
        if(n==3) return prod;
        
        for(int i=0;i<n;i++){
            // for 3 largest positive numbers
            if(arr[i]>=maxA){
                maxC=maxB;
                maxB=maxA;
                maxA=arr[i];
            }
            else if(maxB<=arr[i]){
                maxC=maxB;
                maxB=arr[i];
            }
            else if(maxC<=arr[i]){
                maxC=arr[i];
            }
            
            // for 3 lowest numbers or negative numbers
            if(arr[i]<=minA){
                minB=minA;
                minA=arr[i];
            }
            else if(minB>arr[i]){
                minB=arr[i];
            }
        }
        return max(maxA*maxB*maxC,minA*minB*minC);
}
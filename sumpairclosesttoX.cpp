/*

Given a sorted array and a number x, find a pair in an array whose sum is closest to x.

Examples:

Input: arr[] = {10, 22, 28, 29, 30, 40}, x = 54
Output: 22 and 30

Input: arr[] = {1, 3, 4, 7, 10}, x = 15
Output: 4 and 10

*/

#include<bits/stdc++.h>
using namespace std;

//Brute force
//T.C = O(N^2)
//S.C = O(1)

// Prints the pair with sum closest to x 
void printClosest(int arr[], int n, int x) 
{ 
    int res_l, res_r;  // To store indexes of result pair 
    
      //variable to store current minimum difference 
      int temp = INT_MAX; 
    
      //iterating over array 
      for(int i=0;i<n-1;i++) 
    { 
          for(int j=i+1;j<n;j++) 
        { 
              //if found more closest pair 
              if(abs(arr[i]+arr[j]-x)<temp) 
            { 
                  res_l=i; 
                  res_r=j; 
                  temp=abs(arr[i]+arr[j]-x); 
            } 
        } 
    } 
  
    cout <<" The closest pair is " << arr[res_l] << " and " << arr[res_r]; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    int arr[] =  {10, 22, 28, 29, 30, 40}, x = 54; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printClosest(arr, n, x); 
    return 0; 
} 

//Optimised approach:
//Using binary search

//T.C = O(nlogn)
//S.C = O(1)

vector<int> sumClosest(vector<int>arr, int x)
    {
        int n = arr.size() - 1;
        int left = 0;
        int right = n;
        int diff = INT_MAX;
        vector<int> output;


        while (left < right) {
            int sum = arr[left] + arr[right];
            int curdiff = abs(sum - x);

            if (curdiff < diff) {
                diff = curdiff;
                output.clear();
                output.push_back(arr[left]);
                output.push_back(arr[right]);
            }

            if (sum == x) return output;
            if (sum > x) {
                right--;
            } else {
                left++;
            }
        }

        return output;
}
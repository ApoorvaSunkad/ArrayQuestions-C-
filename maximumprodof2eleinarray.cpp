/*
Given the array of integers nums, you will choose two different indices i and j of that 
array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
 

Example 1:

Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the 
maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 

Example 2:

Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum 
value of (5-1)*(5-1) = 16.

Example 3:

Input: nums = [3,7]
Output: 12
 

Constraints:

2 <= nums.length <= 500
1 <= nums[i] <= 10^3

*/

//Brute force: My solution
#include<bits/stdc++.h>
using namespace std;

//T.C = O(N^2)
//S.C = O(1)

int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN;

        for(int i = 0; i<n; i++){
             int prod = 1;
            for(int j = i+1; j<n; j++){
                prod = ((nums[i]-1)*(nums[j]-1));
                if(prod>maxi){
                    maxi = max(maxi,prod);
                }
            }
        }
        return maxi;
}

//Better approach
//T.C = O(NLOGN)
//S.C = O(logn) in worst case for sorting algorithms

#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end()); //sorting

        return (nums[n-1]-1)*(nums[n-2]-1);
}

//Optimised approach: finding largest and second largest element in the array
#include<bits/stdc++.h>
using namespace std;

//T.C = O(N)
//S.C = O(1)

    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxi = nums[0];
        int smaxi = -1;

        for(int i = 1; i<n; i++){
            if(nums[i]>maxi){
                smaxi = maxi;
                maxi = nums[i];
            }
            else if(nums[i]>smaxi){
                smaxi = nums[i];
            }
        }
        return (maxi-1)*(smaxi-1);
}
/*
Given an array nums with n objects colored red, white, or blue, sort them in-place 
so that objects of the same color are adjacent, with the colors in the order
red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 
Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]

*/

//Brute force:
//T.C = O(NLogN)
//S.C O(1)
#include<bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {

    sort(nums.begin(),nums.end());    
}

//Optimised approach
//T.C: O(N)
//S.C = O(1)

//This approach uses DUTCH NATIONAL FLAG ALGORITHM
/*
--> The Dutch National Flag algorithm, also known as 3-way partitioning, is an algorithm 
for sorting an array containing three distinct values. The algorithm was designed to solve
the problem of sorting an array containing only 0s, 1s, and 2s, 
which is similar to the problem in the given question.

--> The algorithm works by maintaining three pointers: low, mid, and high. 
The low pointer points to the beginning of the array, the high pointer points to 
the end of the array, and the mid pointer starts at the beginning of the array and
moves through it.

--> The idea behind the algorithm is to keep all the 0s before the low pointer, all the 
2s after the high pointer, and all the 1s between the low and high pointers. 

--> The algorithm moves the mid pointer through the array, comparing the value at each 
position with 1. If the value is 0, the element is swapped with the element at the 
low pointer, and the low and mid pointers are incremented. If the value is 2, the 
element is swapped with the element at the high pointer, and the high pointer is decremented. 
If the value is 1, the mid pointer is simply incremented.

--> The algorithm terminates when the mid pointer crosses the high pointer, indicating that 
all the elements have been processed and the array is sorted.

--> The Dutch National Flag algorithm is called one-pass because it sorts the array in a 
single pass through the elements. The time complexity of the algorithm is O(n), 
where n is the size of the array.

*/
void sortColors(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        int low = 0, mid = 0, high = nums.size()-1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
}
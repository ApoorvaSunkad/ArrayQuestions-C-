/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, 
find two numbers such that they add up to a specific target number. Let these two numbers 
be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer 
array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the 
same element twice.

Your solution must use only constant extra space.

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].

*/

#include<bits/stdc++.h>
using namespace std;

//Brute force: 
//T.C = O(N^2) -> Got TLE Error
//S.C = O(1)

vector<int> twoSum(vector<int>& numbers, int target) {

        int n = numbers.size();
        vector<int> v;

        for(int i = 0; i<n; i++){
            for(int j = i+1;j<n;j++){
                if(numbers[i]+numbers[j] == target){
                    v.push_back(i+1);
                    v.push_back(j+1);
                }
            }
        }
        return v;
}

//Optimised approach: Using two pointer approach
//T.C = O(N)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {

      vector<int> v;

       int n = numbers.size();

       int start = 0, end = n-1;

       while(start<end){
           if((numbers[start]+numbers[end]) == target){
               v.push_back(start+1);
               v.push_back(end+1);
               start++;
               end--;
           }
           else if((numbers[start]+numbers[end])<target){
               start++;
           }
           else{
               end--;
           }
        } 
        return v;
}
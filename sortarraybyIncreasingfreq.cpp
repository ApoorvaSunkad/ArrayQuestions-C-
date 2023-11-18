/*
Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Example 1:

Input
6
1 1 2 2 2 3

Output
3 1 1 2 2 2
*/


//Optimal and brute force approach:

#include<bits/stdc++.h>
using namespace std;

vector<int> sortByIncreasingFrequency(vector<int>& arr) {
        // write your code here
        //vector<int> v;
        
        map<int,int> mpp;
        
        for(int i = 0; i<arr.size();i++){
            mpp[arr[i]]++;
        }
        
        //This is using lambda function which is then passed to the sort function
        //Learn more about this is GFG article.
        
        auto comparator = [&](int a, int b) {
           if (mpp[a] == mpp[b]) {
               return a > b;  
            }
            return mpp[a] < mpp[b];  
        };

   
        sort(arr.begin(), arr.end(), comparator);

        return arr;
        
    }
/*
Time Complexity (T.C):
Counting Frequencies (for loop):

Iterating through the array takes O(n) time, where n is the size of the input array.
Sorting (std::sort):

Sorting the array takes O(n log n) time, where n is the size of the input array. 
The dominating factor is the sorting operation.

Total Time Complexity:
O(n + n log n) = O(n log n) (sorting dominates for large n)


Space Complexity (S.C):
Map (mpp):

The space required for the mpp map is O(u), where u is the number of unique elements in the 
input array. In the worst case,where all elements are unique, the space complexity is O(n).

Sorting In-Place:
The sorting is done in-place, so there is no additional space used for the sorting operation.

Total Space Complexity:O(u) = O(n) in the worst case.

In summary, the time complexity is O(n log n) and the space complexity is O(n) 
in the worst case, where n is the size of the input array.

*/
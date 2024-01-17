/*
Given an array of integers arr, return true if the number of occurrences of each value 
in the array is unique or false otherwise.

 

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have 
the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
 

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000

*/

//Brute force:
//T.C = O(NLOGN) Sorting
//S.C = O(N)
#include<bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
         sort(arr.begin(), arr.end());
         vector<int> v;

         for (int i = 0; i < arr.size(); i++) {
            int cnt = 0;

            // Count occurrences of the current element
            while (i + 1 < arr.size() && arr[i] == arr[i + 1]) {
                cnt++;
                i++;
            }

            v.push_back(cnt);
        }

        sort(v.begin(), v.end());

        for (int i = 1; i < v.size(); i++) {
            if (v[i] == v[i - 1]) {
                return false;
            }
        }

        return true;
}


//Using sets and maps
//T.C = O(N)
//S.C = O(N)

#include<bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {

      unordered_map<int,int>freq;
      for(auto x: arr){
          freq[x]++;
      }  
      unordered_set<int>s;
      for(auto x: freq){
          s.insert(x.second);
      }
      return freq.size()==s.size();

      /*
      freq.size(): This returns the number of unique keys in the freq unordered_map. 
      In the context of the problem, each key represents a distinct element in the input 
      array (arr), and the corresponding value is the frequency of that element in the 
      array.

      s.size(): This returns the number of unique values (occurrences) in the s 
      unordered_set. In this case, s is used to store the frequencies of elements from 
      the freq map. So, the size of s represents the number of unique frequencies.

      The return statement checks if the number of unique elements in the input array is 
      equal to the number of unique frequencies. If these counts are equal, it means that 
      each element in the array has a unique frequency, and the function returns true. 
      Otherwise, it returns false, indicating that there are elements with the same 
      frequency in the array.
      
      */
}
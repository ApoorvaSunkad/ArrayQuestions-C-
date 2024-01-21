/*
Given an array nums of n integers where nums[i] is in the range [1, n], return an array 
of all the integers in the range [1, n] that do not appear in nums.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
Example 2:

Input: nums = [1,1]
Output: [2]
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
 

Follow up: Could you do it without extra space and in O(n) runtime? You may assume the 
returned list does not count as extra space.

*/

//Brute force
//T.C = O(N^2)
//S.C = O(1)

/*
A brute-force way to solve this question is to take each number in range [1, n] and 
push it into ans array if it doesn't occur in nums.

*/
#include<bits/stdc++.h>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(int i = 1; i <= size(nums); i++) 
            if(find(begin(nums), end(nums), i) == end(nums))  // linear search in nums for each i
                ans.push_back(i);
        return ans;
}


//2nd solution: SORT AND BINARY SEARCH
//T.C = O(nlogn)
//S.C = O(1)

/*
Instead of linear-searching if every element in range [1, n] is present in nums or not, 
we could instead sort nums and then apply binary-search every time. 
If the element is not found in nums, we include it in ans.
*/

#include<bits/stdc++.h>
using namespace std;

//T.C = O(nlogn) + O(logn) ~ O(nlogn)
//S.C = O(1)

vector<int> findDisappearedNumbers(vector<int>& nums) {
    sort(begin(nums), end(nums));
    vector<int> ans;
    for(int i = 1; i <= size(nums); i++) 
        if(!binary_search(begin(nums), end(nums), i))   // binary search in nums for each i
            ans.push_back(i);
    return ans;
}


//3rd solution = Hashset

/*
We can do even better if we just insert every element from nums into a hashset and then 
iterate over the range [1, n] and only add those elements to ans and are not present 
in hashset.
*/

//T.C = O(N)
//S.C = O(N)

#include<bits/stdc++.h>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    unordered_set<int> s(begin(nums), end(nums));   // insert every nums[i] in hashset
    vector<int> ans(size(nums) - size(s));
    for(int i = 1, j = 0; i <= size(nums); i++)  
        if(!s.count(i)) ans[j++] = i;               // add all elements not found in hashset to ans
    return ans;
}


//4th solution - Boolean Array
//T.C = O(N)
//S.C = O(N)

vector<int> findDisappearedNumbers(vector<int>& nums) {
        
    int n = nums.size();
    vector<int> hashed(n + 1, 0);

    vector<int> v;
        
    for(int i = 0; i<n; i++){
        hashed[nums[i]]++;
    }
        
    for(int i = 1; i<=n;i++){
        if(hashed[i]==0){
            v.push_back(i);
        }
    }
        
    return v;
}



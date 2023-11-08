/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. 
Therefore its length is 4.

Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

*/
#include<bits/stdc++.h>
using namespace std;

//Another brute force approach by striver 
//T.C = O(N^2) but for me in leetcode I got TLE Error
//S.C = O(1)
bool linearSearch(vector<int>& nums,int x){
        for(int i = 0; i<nums.size();i++){
            if(nums[i]==x){
                return true;
            }
        }
        return false;
}
int longestConsecutive(vector<int>& nums) {
        //Brute force:
        int n = nums.size();
        if(n<=1){
            return n;
        }

        int longest = 1;

        for(int i = 0; i<nums.size();i++){
            int x = nums[i];
            int cnt = 1;
            while(linearSearch(nums,x+1)==true){
                x = x+1;
                cnt++;
            }
            longest = max(longest,cnt);
        }
        return longest;
    }

//This is my brute force approach(somewhat better) took help from chatGPT
// T.C = O(NLOGN)
//S.C = O(1)

int longestConsecutive(vector<int>& nums) {

        if (nums.size() <= 1) {
          return nums.size();
        }

        sort(nums.begin(), nums.end());

        int cnt = 1; // Minimum consecutive count
        int maxi = 1; // Maximum consecutive count

        for (int i = 1; i < nums.size(); i++) {
           if (nums[i] != nums[i - 1]) {
             if (nums[i] - nums[i - 1] == 1) {
                 cnt++;
             } else {
                maxi = max(maxi, cnt);
                cnt = 1;
            }
        }
    }
    
    return max(maxi, cnt);
}

//optimal solution
// T.C = O(2N+N) ~ O(3N) Striver's video
// S.C = O(N) For set 
#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if(n==0) return 0;
        int longest = 1;

        unordered_set<int> st;

        for(int i = 0; i<n; i++){
            st.insert(nums[i]);
        }
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int cnt = 1;
                int x = it;
                while(st.find(x+1)!=st.end()){
                    x++;
                    cnt++;
                }
                longest = max(longest,cnt);
            }
        }
        return longest;
}
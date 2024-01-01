/*
There are n kids with candies. You are given an integer array candies, where each candies[i]
represents the number of candies the ith kid has, and an integer extraCandies, denoting 
the number of extra candies that you have.

Return a boolean array result of length n, where result[i] is true if, after giving the 
ith kid all the extraCandies, they will have the greatest number of candies among all the 
kids, or false otherwise.

Note that multiple kids can have the greatest number of candies.

 

Example 1:

Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true] 
Explanation: If you give all extraCandies to:
- Kid 1, they will have 2 + 3 = 5 candies, which is the greatest among the kids.
- Kid 2, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
- Kid 3, they will have 5 + 3 = 8 candies, which is the greatest among the kids.
- Kid 4, they will have 1 + 3 = 4 candies, which is not the greatest among the kids.
- Kid 5, they will have 3 + 3 = 6 candies, which is the greatest among the kids.

Example 2:

Input: candies = [4,2,1,1,2], extraCandies = 1
Output: [true,false,false,false,false] 
Explanation: There is only 1 extra candy.
Kid 1 will always have the greatest number of candies, even if a different kid is given 
the extra candy.

Example 3:

Input: candies = [12,1,12], extraCandies = 10
Output: [true,false,true]
 
*/


#include<bits/stdc++.h>
using namespace std;

//This is my solution
//T.C = O(N^2)
//S.C = O(1) Without counting the space of input and output, we are not using any 
//space except for some integers like maxCandies and candy.

private:
int Maxi(vector<int>& candies){
    int n = candies.size();

    int largest = INT_MIN;

    for(int i = 0; i<n; i++){
        if(candies[i]>largest){
            largest = candies[i];
        }
    }
    return largest;
}
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {

        int n = candies.size();

        int maxValue = Maxi(candies);
        
        vector<bool> result;


        for(int i = 0; i<n; i++){
            int ans = 0;
            ans = candies[i] + extraCandies;

            bool value;
            for(int j = 0; j<n; j++){
                if(ans>=maxValue){
                   value = true;
                }else{
                   value = false;
                }
            }
            result.push_back(value);
        }
        return result;
}


//Leetcode's solution
//T.C = O(N)
//S.C = O(1) Without counting the space of input and output, we are not using any 
//space except for some integers like maxCandies and candy.

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
               // Find out the greatest number of candies among all the kids.
        int maxCandies = 0;
        for (int candy : candies) {
            maxCandies = max(maxCandies, candy);
        }
        // For each kid, check if they will have greatest number of candies
        // among all the kids.
        vector<bool> result;
        for (int candy : candies) {
            result.push_back(candy + extraCandies >= maxCandies);
        }

        return result;
}
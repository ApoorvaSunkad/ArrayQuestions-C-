/*
You are given an integer array prices representing the prices of various chocolates in a store. 
You are also given a single integer money, which represents your initial amount of money.

You must buy exactly two chocolates in such a way that you still have some non-negative 
leftover money. You would like to minimize the sum of the prices of the two chocolates you buy.

Return the amount of money you will have leftover after buying the two chocolates. If there 
is no way for you to buy two chocolates without ending up in debt, return money. Note that 
the leftover must be non-negative.

 

Example 1:

Input: prices = [1,2,2], money = 3
Output: 0
Explanation: Purchase the chocolates priced at 1 and 2 units respectively. 
You will have 3 - 3 = 0 units of money afterwards. Thus, we return 0.

Example 2:

Input: prices = [3,2,3], money = 3
Output: 3
Explanation: You cannot buy 2 chocolates without going in debt, so we return 3.

*/

#include<bits/stdc++.h>
using namespace std;

//My code
//T.C =  O(NLOGN) + O(N^2)
//S.C = O(1)

int buyChoco(vector<int>& prices, int money) {

        sort(prices.begin(),prices.end());
        int n = prices.size();

        int diff  = 0, ans = 0;
        for(int i = 0; i<n;i++){
            for(int j = i+1;j<n;j++){
                ans = prices[i]+prices[j];
                diff = abs(ans-money);

                if(money >=ans){
                    return diff;
                    break;
                }
            }
        }
        return money;
}



#include<bits/stdc++.h>
using namespace std;

//Same complexity but is code is cleaner
//T.C =  O(NLOGN) + O(N^2)
//S.C = O(1)

int buyChoco(vector<int>& prices, int money) {

        int ans = INT_MAX;
        int fin;
        for (int i = 0; i < prices.size(); i++) {
            for (int j = 0; j < prices.size(); j++) {
                if (i != j ) {
                    int sum = prices[i] + prices[j];
                    ans = min(ans, sum);
                }
            }
        }
       
        fin = money - ans;

        if(fin>=0){
          return fin;
        }
        else{
            return money;
        }
}

//Greedy approach - The approach was figured out by me but didn't know it was greedy approach.

#include<bits/stdc++.h>
using namespace std;

//T.C = O(Nlogn)
//S.C = O(1)

int buyChoco(vector<int>& prices, int money) {
        // Sort the Array in Increasing Order
        sort(prices.begin(), prices.end());

        // Minimum Cost
        int minCost = prices[0] + prices[1];

        // We can buy chocolates only if we have enough money
        if (minCost <= money) {
            // Return the Amount of Money Left
            return money - minCost;
        } else {
            // We cannot buy chocolates. Return the initial amount of money
            return money;
        }
}
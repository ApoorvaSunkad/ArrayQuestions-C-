/*
You are given a 0-indexed integer array nums and an integer k.

Return an integer that denotes the sum of elements in nums whose corresponding indices 
have exactly k set bits in their binary representation.

The set bits in an integer are the 1's present when it is written in binary.

For example, the binary representation of 21 is 10101, which has 3 set bits.
 

Example 1:

Input: nums = [5,10,1,5,2], k = 1
Output: 13
Explanation: The binary representation of the indices are: 
0 = 0002
1 = 0012
2 = 0102
3 = 0112
4 = 1002 
Indices 1, 2, and 4 have k = 1 set bits in their binary representation.
Hence, the answer is nums[1] + nums[2] + nums[4] = 13.
Example 2:

Input: nums = [4,3,2,1], k = 2
Output: 1
Explanation: The binary representation of the indices are:
0 = 002
1 = 012
2 = 102
3 = 112
Only index 3 has k = 2 set bits in its binary representation.
Hence, the answer is nums[3] = 1.

*/


//My solution a bit lengthy but git submitted
//T.C = O(N * log(max_value)) 
/*
where n is the size of the input array nums, and max_value is the maximum value in the array. The O(n) part comes from the outer loop iterating over each element in nums, and the O(log(max_value)) part comes from 
the inner loop that converts the index to its binary representation.
*/

//S.C =  O(log(max_value)) due to the space required for the binary representation string
//s in each iteration.


#include<bits/stdc++.h>
using namespace std;

int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n = nums.size();
        long long mul = 1, sum = 0;

        for(int i = 0; i<n; i++){
          int ans = 0, cnt = 0;
          int value = i;
            while(value != 0){
               int ld = value%2;
               value/=2;
               ans = (ld*mul)+ans;
               mul*=10;
            }

            string s = to_string(ans);
            for(int j = 0; j<s.length();j++){
               if(s[j]=='1'){
                  cnt++;
                }
            }

            if(cnt==k){
               sum+=nums[i];
            }
            mul = 1;
        }
        return sum;
}


//2nd solution
//T.C = O(n * log(m))
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

int countSetBits(int num) {
    int count = 0;
    while (num > 0) {
        count += (num & 1);
        num >>= 1;
    }
    return count;
}
int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
           if (countSetBits(i) == k) {
              sum += nums[i];
            }
        }

        return sum;
}


//3rd efficent solution

//T.C = O(N)
//S.C = O(1)

int countset(int n)
{
    int count=0;
    while(n)
    {
       
       if(n%2==1)
        count++;
        n=n/2;
    }
    return count;
}
int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans=0;
       int n=nums.size();
       for(int i=0;i<n;i++)
       {
           int a=countset(i);
           if(a==k)
           ans=ans+nums[i];
       }
       return ans; 
}
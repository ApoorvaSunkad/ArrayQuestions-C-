/*
Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N} is 
missing and one number 'B' occurs twice in array. Find these two numbers.

Example 1:

Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.

*/

#include<bits/stdc++.h>
using namespace std;

//T.C = O(N^2) //Got TLE
//S.C = O(1)

vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int repeating = -1, missing = -1;
        for(int i = 1; i<=n; i++){
            int cnt = 0;
            for(int j = 0; j<n;j++){
                if(arr[j]==i){
                    cnt++;
                }
            }
            if(cnt == 2) repeating = i;
            else if(cnt == 0) missing = i;
            
            if(repeating != -1 && missing != -1){
               break;
            }
        }
        return {repeating,missing};
}

//Better approach using Hashmaps or hasharray:
//T.C = O(3N)
//S.C = O(N)

#include<bits/stdc++.h>
using namespace std;

vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int> v;
        
        unordered_map<int,int>m;
        
        for(int i = 0; i<n;i++){
            m[arr[i]]++;
        }
        
        for(auto it:m){
            if(it.second>1){
                v.push_back(it.first);
            }
        }
        
        for (int i = 1; i <= n; i++) {
        if (m.find(i) == m.end()) {
            v.push_back(i); // Finding the missing number
            break;
        }
    }
        
    return v;
}
//Better approach 2:
//T.C = O(2N)
//S.C = O(1)

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size(); // size of the array
    int hash[n + 1] = {0}; // hash array

    //update the hash array:
    for (int i = 0; i < n; i++) {
        hash[a[i]]++;
    }

    //Find the repeating and missing number:
    int repeating = -1, missing = -1;
    for (int i = 1; i <= n; i++) {
        if (hash[i] == 2) repeating = i;
        else if (hash[i] == 0) missing = i;

        if (repeating != -1 && missing != -1)
            break;
    }
    return {repeating, missing};

}

//Better approach 3:
//Using vector

//T.C = O(N)
//S.C = O(N)

#include<bits/stdc++.h>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {

    int n =nums.size();

    vector<int>v(n+1,0);

    int missing=0,duplicate =0;

    for(int i =0;i<n;i++){
        v[nums[i]]++;
    }

    for(int i =1;i<v.size();i++){
        if(v[i]==2)duplicate = i;
        if(v[i]==0)missing = i;
    }

    return {duplicate,missing};
}

//Better approach: 4
//Set + sum
//T.C = O(N)
//S.C = O(N)

#include<bits/stdc++.h>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {

    int n = nums.size();

    int actual_sum = n * (n + 1) / 2;

    int array_sum = 0, unique_sum = 0;

    unordered_set<int> s(nums.begin(), nums.end());

    for (int a : nums) {
        array_sum += a;
    }


    for (int a : s) {
        unique_sum += a;
    }

    int missing = actual_sum - unique_sum;
    int duplicate = array_sum - unique_sum;

    return {duplicate, missing};
}

//Optimised Approach:

// T.C = O(N)
// S.C = O(1)
#include<bits/stdc++.h>
using namespace std;

vector<int> findTwoElement(vector<int> arr, int n) {
       
        //s-sn -> X-Y
        //s2-s2n -> X^2 - Y^2
        
        long long SN = ((long long)n*(long long)(n+1))/2;
        
        long long S2N = ((long long)n*(long long)(n+1)*(2*n+1))/6;
        
        long long S = 0, S2 = 0;
        
        for(int i = 0; i<n;i++){
            S+=arr[i];
            S2+=(long long)arr[i]*(long long)arr[i];
        }
        
        long long val1 = S-SN; //x-y
        long long val2 = S2-S2N; // x^2-y^2 = val2, //nothing but (x-y)*(x+y) = val2;
        //(x+y) = val2/(x-y) = (x+y) = val2/val1
        //(x+y) is nothing but val2 
        
        val2 = val2/val1; //x+y
        
        long long x = (val1 + val2)/2;
        long long y = x-val1; //y = x-val1
        
        return {int(x),int(y)};
        
        //Best explaination given by striver for this approach
        //XOR approach is also present for this question but I have not done it 
        //watch striver's video for that approach.
        
    }




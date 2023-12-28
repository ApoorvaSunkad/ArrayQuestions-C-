/*
Given a non-negative number represented as a list of digits, add 1 to the number (increment the number represented by the digits). The digits are stored such that the most significant digit is first element of array.
 

Example 1:

Input: 
N = 3
arr[] = {1, 2, 4}
Output: 
1 2 5
Explanation:
124+1 = 125, and so the Output
Example 2:

Input: 
N = 3
arr[] = {9,9,9}
Output: 
1 0 0 0
Explanation:
999+1 = 1000, and so the output

Your Task:
You don't need to read input or print anything. You only need to complete the function increment() that takes an integer N, and an array arr of size N as input and returns a list of integers denoting the new number which we get after adding one to the number denoted by the array arr.


Expected Time Complexity:  O(N)
Expected Auxilliary Space: O(1)
 

Constraints:
1 <= N <= 105
0 <= arri <= 9

Company:
Microsoft, Google

*/


//My solution Brute force: failed for larger inputs

//T.C = O(N)
//S.C = O(N)

  vector<int> increment(vector<int> arr ,int N) {
        
        long long int ans = 0;
        
        vector<int> v;
        
        for(int i = 0; i<N;i++){
            ans = (ans*10) + arr[i];
        }
        
        ans+=1;
        
        while(ans!=0){
            int ld = ans%10;
            
            v.push_back(ld);
            ans/=10;
        }
        
        reverse(v.begin(),v.end());
        return v;
}


//Optimal solution
//T.C = O(N)
//S.C = O(1)

vector<int> increment(vector<int> arr ,int N) {

        int carry = 1;
        for(int i = N-1; i>=0 ; i--){
            int sum = carry+ arr[i];
            carry = sum/10;
            arr[i] = sum%10;
        }
        if(carry !=0){
            arr.insert(arr.begin(), carry);
        }
        return arr;
}
//
/*
Given three arrays sorted in increasing order. Find the elements that are 
common in all three arrays.
Note: can you take care of the duplicates without using any additional Data 
Structure?

Example 1:

Input:
n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80
Explanation: 20 and 80 are the only
common elements in A, B and C.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete 
the function commonElements() which take the 3 arrays A[], B[], C[] and 
their respective sizes n1, n2 and n3 as inputs and returns an array 
containing the common element present in all the 3 arrays in sorted order. 
If there are no such elements return an empty array. In this case the 
output will be printed as -1.

 

Expected Time Complexity: O(n1 + n2 + n3)
Expected Auxiliary Space: O(n1 + n2 + n3)

 

Constraints:
1 <= n1, n2, n3 <= 10^5
The array elements can be both positive or negative integers.


*/


//Brute force using set
//T.C = O(N1+N2+N3)
//S.C = O(N1+N2+N3)

#include<bits/stdc++.h>
using namespace std;

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
    
    vector<int>ans;

    set<int>st;

    int i,j,k;

    i=j=k=0;

    while(i<n1 && j<n2 && k<n3)
    {
        if(A[i]==B[j] && B[j]==C[k])
        {
        st.insert(A[i]);
            i++;j++;k++;
        }
        else if(A[i]<B[j])
        {
            i++;
        }
        else if(B[j]<C[k])
        {
            j++;
        }
        else{
            k++;
        }
        
    }
    for(auto i:st){
        ans.push_back(i);
    }
    return ans;
}

//Using 3-pointer approach

 vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
    {   
        int i=0, j=0, k=0;
        vector<int>ans;
        while(i<n1 && j<n2 && k<n3){
            if(A[i]==B[j] && A[i]==C[k]){
                ans.push_back(A[i]);
                i++;j++;k++;
            }
            else if(A[i]<B[j]) i++;
            else if(B[j]<C[k]) j++;
            else k++;
            while(A[i]==A[i-1]) i++;
            while(B[j]==B[j-1]) j++;
            while(C[k]==C[k-1]) k++;
        }
        
        return ans;
        
    }
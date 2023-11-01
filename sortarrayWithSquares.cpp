/*
Given a sorted array A containing N integers both positive and negative.

You need to create another array containing the squares of all the elements in A and 
return it in non-decreasing order.

Try to this in O(N) time.

*/
#include<bits/stdc++.h>
using namespace std;

//Brute force approach done by me:
//T.C: O(N) + O(N*Log N) ~ Overall T.C = O(N * Log N)

vector<int>solve(vector<int> &A) {
    vector<int> v;
    
    for(int i = 0; i<A.size();i++){
        int ans = abs(A[i]*A[i]);
        v.push_back(ans);
    }
    sort(v.begin(),v.end());
    return v;
}

//optimised approach
//T.C = O(N)

#include<bits/stdc++.h>
using namespace std;

vector<int>solve(vector<int> &A) {
    int n = A.size();
    vector<int> result(n);
    int left = 0, right = n - 1;
    int index = n - 1;

    while (left <= right) {
        int leftSquare = A[left] * A[left];
        int rightSquare = A[right] * A[right];

        if (leftSquare > rightSquare) {
            result[index] = leftSquare;
            left++;
        } else {
            result[index] = rightSquare;
            right--;
        }
        index--;
    }
    return result;
}
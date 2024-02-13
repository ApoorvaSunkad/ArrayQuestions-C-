/*
Given an array A of positive integers. Your task is to find the leaders in 
the array. An element of array is a leader if it is greater than or equal to 
all the elements to its right side. The rightmost element is always a leader. 

Example 1:

Input:
n = 6
A[] = {16,17,4,3,5,2}
Output: 17 5 2
Explanation: The first leader is 17 
as it is greater than all the elements
to its right.  Similarly, the next 
leader is 5. The right most element 
is always a leader so it is also 
included.
Example 2:

Input:
n = 5
A[] = {1,2,3,4,0}
Output: 4 0
Explanation: 0 is the rightmost element
and 4 is the only element which is greater
than all the elements to its right.


*/

//T.C = O(N^2)
//S.C = O(N)


vector<int> leaders(int a[], int n){
    // Code here
    vector<int> ans;
    
    for(int i = 0; i<n; i++){
        bool leader = true;
        for(int j = i+1; j<n; j++){
            if (a[j] > a[i]) {
                leader = false;
                break;
            }
        }
        if (leader == true) {
            ans.push_back(a[i]);
        }
    }
    return ans;
    
}

//Optimised solution

public:
//T.C = O(N)
//S.C = O(N)

vector<int> leaders(int a[], int n){
    // Code here
    vector<int>ans;
    int leader=a[n-1];
    ans.push_back(leader);
    for(int i=n-2;i>=0;i--){
        if(a[i]>=leader){
            ans.push_back(a[i]);
            leader=a[i];
        } 
    }
    reverse(ans.begin(),ans.end()); // TC = O(n)
    return ans;
}
/*
Given an integer array nums, move all 0's to the end of it while maintaining the 
relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you minimize the total number of operations done?


*/

#include<bits/stdc++.h>
using namespace std;

//Brute force: 
//T.C = O(N)
//S.C = O(N)
void moveZeroes(int nums[],int n) {
        vector<int> v;
        int cntZero = 0;
        for(int i = 0; i<n;i++){
            if(nums[i]!=0){
                v.push_back(nums[i]);
            }
            else{
                cntZero++;
            }
        }
        for(int i = 0; i<cntZero; i++){
            v.push_back(0);
        }
        
        for(int i = 0; i<v.size(); i++){
            nums[i] = v[i];
        }
}
int main(){
    int n;
    cin>>n;

    int arr[1000];
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    moveZeroes(arr,n);
    for(int i = 0; i<n;i++){
        cout << arr[i];
    }
}


//Optimal solution using TWO POINTERS

//T.C = O(N)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
        
    int n = nums.size();
        
    int i = 0, j = i+1;
        
    while(i<n && j<n){
        if(nums[i]==0 && nums[j]!=0){
            swap(nums[i],nums[j]);
            i++;
            j++;
        }
        else if(nums[i]==0 && nums[j]==0){
            j++;
        }
        else if(nums[i]!=0 && nums[j]!=0){
            i++;
            j++;
        }
        else if(nums[i]!=0 && nums[j]==0){
            i++;
            j++;
        }   
}
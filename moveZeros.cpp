#include<bits/stdc++.h>
using namespace std;

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
        int n1 = v.size();
        for(int i = n1-1; i>=cntZero;i--){
            v[i] = 0;
        }
        for(int i = 0; i < n;i++){
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
#include<bits/stdc++.h>
using namespace std;

// Question on GFG Practice

// This brute force approach was solved by me using some hints from GFG.

// But the issue with this approach is that it doesn't work for "larger inputs" 
// like n = 30k or n = 10^6
// and gives RUNTIME ERROR

//T.C = O(N * Log (N)) // dominating T.C is sorting.
//S.C = O(N) // storing array elements in even and odd vector.

string solve(int arr[], int n) {
        
        sort(arr,arr+n);
        
        string minSum;
        
        vector<int> even;
        vector<int> odd;
        
        for(int i = 0; i<n;i++){
            if(i%2 ==0){
                even.push_back(arr[i]);
            }
            else{
                odd.push_back(arr[i]);
            }
        }
        
        long long ans1 = 0, ans2 = 0;
        
        int n1 = even.size();
        int n2 = odd.size();
        
        for(int i = 0; i<n1; i++){
            ans1 = (ans1 * 10) + even[i];
        }
        
        for(int i = 0; i<n2; i++){
            ans2 = (ans2 * 10) + odd[i];
        }
        
        long long sum = 0;
        
        sum = ans1+ans2;
        
        minSum = to_string(sum);
        
        return minSum;
}
/*int main(){
    int n;
    cin>> n;

    int arr[1000];
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }

    string minSum = solve(arr,n);

    cout << minSum << endl;
}*/

//Optimsied approach:
//T.C = O(NlogN) because we are sorting the given array.
//Auxiliary Space: O(1) 

string sumof(string s2, string s1){

    int i = s1.size()-1;
    int j = s2.size()-1;

    string sum = "";
    int carry = 0;

    while(i>=0 && j>=0){
        int d1 = s1[i]-'0';
        int d2 = s2[i]-'0';
        sum = to_string((d1+d2+carry)%10) + sum;
        carry = (d1+d2+carry)/10;
        i--,j--;
    }
    while(i>=0){
        int d1 = s1[i]-'0';
        sum = to_string((d1+carry)%10)+sum;
        carry = (d1+carry)/10;
        i--;
    }
    while(j>=0){
        int d1 = s2[j]-'0';
        sum = to_string((d1+carry)%10)+sum;
        carry = (d1+carry)/10;
        j--;
    }
    if(carry != 0){
        sum = to_string(carry)+sum;
    }
    for(int i = 0; i<sum.size();i++){
        if(sum[i]!='0'){
            return sum.substr(i);
        }
    }
    return "0";
}
string solved(int arr[], int n)
{
    string s1 = "", s2 = "";
    sort(arr,arr+n);

    for(int i = 0; i<n; i++){
        if(i%2==0){
            s1+=to_string(arr[i]); //s1.push_back(arr[i] + '0');
            //this push back doesn't give TLE error hence use push_back method
        }
        else{
            s2+=to_string(arr[i]); //s2.push_back(arr[i] + '0');
        }
    }
    return sumof(s1,s2);
}
int main(){
    int n;
    cin>> n;

    int arr[1000];
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }

    string minSum = solved(arr,n);

    cout << minSum << endl;
}

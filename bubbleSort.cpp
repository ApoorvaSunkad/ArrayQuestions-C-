//Bubble sort sorts the array elements by comparing them adjacently and swapping them

//The best case time complexity of bubble sort is O(N) because

//Lets suppose if the array is already sorted arr => {1,2,3,4,5}
//Then the inner jth loop will traverse the array once and since we have declared
//a "flag swapped" it checks if the value of that flag is false after each iteration
//If it is false that no swap took place hence we break out of the loop.

//Hence it takes one iteration and T.C boils down to O(N)

//But still the worst and avg T.C is O(N^2)
//Best case time complexity of bubble sort is O(N)


//This is a stable algorithm

//Stable means while processing the elements in the input array or while sorting them
//the original order of the elements which is in the input array will not get changed
//Hence the algorithm is stable




#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){
    bool swapped = false;
    int cnt = 0;
    for(int i = 1; i<=n-1;i++){
        for(int j = 0; j<=n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        cnt++;
        if(swapped == false){
            break;
        }
    }
    cout << "No of iterations: " << cnt << endl;
}
int main(){
    int arr[] = {4,3,2,10,1,5,12,6};

    int n = 8;

    bubbleSort(arr,n);
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
}
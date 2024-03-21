<<<<<<< HEAD
/*
Given a positive integer n, find the pivot integer x such that:

The sum of all elements between 1 and x inclusively equals the sum 
of all elements between x and n inclusively.
Return the pivot integer x. If no such integer exists, return -1. 
It is guaranteed that there will be at most one pivot index for the 
given input.

 

Example 1:

Input: n = 8
Output: 6
Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 is the pivot integer since: 1 = 1.
Example 3:

Input: n = 4
Output: -1
Explanation: It can be proved that no such integer exist.
 

Constraints:

1 <= n <= 1000

*/

//My brute force:
//T.C = O(N)
//S.C = O(N)

int pivotInteger(int n) {
    if(n==1){
        return 1;
    }
    vector<int> pre(n);
    vector<int> suf(n);

    pre[0] = 1;
    for (int i = 1; i <= n-1; i++) {
        pre[i] = pre[i - 1] + i+1;
    }

    suf[n - 1] = n;
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1] + i+1;
    }

    int i = 0, j = 0;
    while (i < n-1 && j < n-1) {
        if (abs(pre[i] - suf[j]) == 0) {
            return i + 1;
        }
        i++;
        j++;
    }
    return -1;
}

//Another brute force:
//T.C = O(N^2)
//S.C = O(1)

int pivotInteger(int n) {
    for(int i = 1; i<=n; i++){
        int leftsum = 0, rightsum = 0;
        for(int j = 1; j<=i;j++){
            leftsum+=j;
        }
        for(int k = i; k<=n; k++){
            rightsum+=k;
        }

        if(leftsum==rightsum) return i;
    }
    return -1;
}

//2nd approach
//T.C = O(N)
//S.C = O(1)

int pivotInteger(int n) {

    int leftValue = 1, rightValue = n;

    int leftsum = leftValue, rightsum = rightValue;

    if(n==1){
        return n;
    }
    while(leftValue<rightValue){
        if(leftsum<rightsum){
            leftValue++;
            leftsum+=leftValue;
        }else{
            rightValue--;
            rightsum+=rightValue;
        }
        if(leftsum==rightsum && leftValue+1==rightValue-1){
            return leftValue+1;
        }
    }
    return -1;
}

//Optimised approach
int pivotInteger(int n) {
        int sum = n*(n+1)/2;
        int ans = sqrt(sum);

        if(ans*ans==sum){
            return ans;
        }
        return -1;
}
=======
/*
Given a positive integer n, find the pivot integer x such that:

The sum of all elements between 1 and x inclusively equals the sum 
of all elements between x and n inclusively.
Return the pivot integer x. If no such integer exists, return -1. 
It is guaranteed that there will be at most one pivot index for the 
given input.

 

Example 1:

Input: n = 8
Output: 6
Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 is the pivot integer since: 1 = 1.
Example 3:

Input: n = 4
Output: -1
Explanation: It can be proved that no such integer exist.
 

Constraints:

1 <= n <= 1000

*/

//My brute force:
//T.C = O(N)
//S.C = O(N)

int pivotInteger(int n) {
    if(n==1){
        return 1;
    }
    vector<int> pre(n);
    vector<int> suf(n);

    pre[0] = 1;
    for (int i = 1; i <= n-1; i++) {
        pre[i] = pre[i - 1] + i+1;
    }

    suf[n - 1] = n;
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1] + i+1;
    }

    int i = 0, j = 0;
    while (i < n-1 && j < n-1) {
        if (abs(pre[i] - suf[j]) == 0) {
            return i + 1;
        }
        i++;
        j++;
    }
    return -1;
}

//Another brute force:
//T.C = O(N^2)
//S.C = O(1)

int pivotInteger(int n) {
    for(int i = 1; i<=n; i++){
        int leftsum = 0, rightsum = 0;
        for(int j = 1; j<=i;j++){
            leftsum+=j;
        }
        for(int k = i; k<=n; k++){
            rightsum+=k;
        }

        if(leftsum==rightsum) return i;
    }
    return -1;
}

//2nd approach
//T.C = O(N)
//S.C = O(1)

int pivotInteger(int n) {

    int leftValue = 1, rightValue = n;

    int leftsum = leftValue, rightsum = rightValue;

    if(n==1){
        return n;
    }
    while(leftValue<rightValue){
        if(leftsum<rightsum){
            leftValue++;
            leftsum+=leftValue;
        }else{
            rightValue--;
            rightsum+=rightValue;
        }
        if(leftsum==rightsum && leftValue+1==rightValue-1){
            return leftValue+1;
        }
    }
    return -1;
}

//Optimised approach
int pivotInteger(int n) {
        int sum = n*(n+1)/2;
        int ans = sqrt(sum);

        if(ans*ans==sum){
            return ans;
        }
        return -1;
}
>>>>>>> a213008ff4fbfbaf0f0ca62fc9a7dd05f314304a
//Watch Aryan mittal's video for this approach
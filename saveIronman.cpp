/*
Jarvis is weak in computing palindromes for Alphanumeric characters.
While Ironman is busy fighting Thanos, he needs to activate sonic punch but Jarvis is stuck 
in computing palindromes.
You are given a string S containing alphanumeric characters. Find out whether the string 
is a palindrome or not.

If you are unable to solve it then it may result in the death of Iron Man.

Example 1:

â€‹Input : S = "I am :IronnorI Ma, i"
Output : YES
Explanation:
Ignore all the symbol and whitespaces S = "IamIronnorIMai".
Now, Check for pallandrome ignoring uppercase and lowercase
english letter.

â€‹Example 2:

Input : S = Ab?/Ba 
Output :  YES 


*/

#include<bits/stdc++.h>
using namespace std;

bool saveIronman(string ch)
{
    // Complete the function
    //transform(ch.begin(), ch.end(), ch.begin(), ::toupper);
    
    string ans="";
    
    for(int i = 0 ; i < ch.size() ; i++)
    {
        if(ch[i] >= 'a' && ch[i] <= 'z')
            ans.push_back(ch[i]) ;
        else if(ch[i] >= 'A' && ch[i] <= 'Z')
            ans.push_back(tolower(ch[i])) ;
        else if(ch[i] >= '0' && ch[i] <= '9')
            ans.push_back(ch[i]) ;
    }
    
    int n=ans.size();
    for(int i=0;i<n/2;i++)
    {
        if(ans[i] !=ans[n-i-1])
        {
            return false;
        }
    }
    return true;
    
}

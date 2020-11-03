#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits.h>
#include<string>
#include<stdio.h>
#include<unordered_set>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
const int N = 100005, M = 11;
int mod = 1000000007;
bool flag = false;
int freq[26];
bool checkPallindrome(string str)
{
    int l = 0, r = str.length() - 1;
    while(l <= r)
    {
        if(str[l] != str[r])
            return false;
        l++;
        r--;
    }
    return true;
}
void permute(int n, string ans, int length){
    
    if(length == n)
    {
        if(checkPallindrome(ans)){
            cout<<ans<<endl;
            flag = true;
        }
        return;
    }
    for(int i = 0; i < 26; i++)
    {
        if(freq[i] > 0)
        {
            char a = i+'a';
            freq[i]--;
            permute(n, ans+a, length+1);
            freq[i]++;

        }

    }
}
int32_t main(){
    string str;
    cin>>str;
    for(int i = 0; i < str.length(); i++)
    {
        freq[str[i]-'a']++;
    }
    permute(str.length(), "", 0);
    if(!flag)
        cout<<-1<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
const int N = 100005, M = 11;
int mod = 1000000007;
void helper(string word, int i, string ans, int count)
{
    if(i == word.length())
    {
        if(count == 0)
            cout<<ans<<endl;
        else
            cout<<ans+to_string(count)<<endl;
        return;
    }
    if(count == 0)
        helper(word, i+1, ans+word[i], 0);
    else
        helper(word, i+1, ans+to_string(count)+word[i], 0);
    helper(word, i+1, ans, count+1);
}
int32_t main(){
    string word;
    cin>>word;
    helper(word, 0, "", 0);
    return 0;
}
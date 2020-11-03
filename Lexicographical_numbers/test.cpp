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
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
const int N = 100005, M = 11;
int mod = 1000000007;
void printLex(int n, int ans)
{
    if(ans > n)
        return;
    cout<<ans<<endl;
    for(int i = 0; i < 10; i++)
    {
        printLex(n, ans*10+i);
    }
}
int32_t main(){
    int n;
    cin>>n;
    for(int i =1 ; i <= 9; i++)
    {
        printLex(n, i);
    }
    return 0;
}
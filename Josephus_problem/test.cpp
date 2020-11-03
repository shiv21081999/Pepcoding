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
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
const int N = 100005, M = 11;
int mod = 1000000007;
int count(bool* arr, int n)
{
    int s = 0;
    for(int i =0 ; i < n; i++)
        if(arr[i])
            s++;
    return s;
}
int pos(bool * arr, int n)
{
    for(int i = 0; i < n; i++)
        if(arr[i])
            return i;
    return 0;
}
int getAlive(bool *arr, int k, int n, int j)
{
    if(count(arr, n) == 1)
    {
        return pos(arr, n);
    }
    if(arr[j])
    {
        arr[j] = false;
        int x = (j+1)%n;
        int t = k;
        while(t > 0)
        {
            if(arr[x])
                t--;
            if(t == 0)
                break;
            x=(x+1)%n;
        }
        return getAlive(arr, k, n, x);
    }
    
    return getAlive(arr, k, n, (j+1)%n);
}
int32_t main(){
    int n, k;
    cin>>n>>k;
    if(n == 1)
    {
        cout<<0<<endl;
        exit(0);
    }
    bool *arr = new bool[n];
    for(int i =0 ; i < n; i++)
        arr[i] = true;
    int ans = getAlive(arr, k, n, ((k-1)%n));
    cout<<ans<<endl;
    return 0;
}
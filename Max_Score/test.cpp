#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits.h>
#include<string>
#include<stdio.h>
#include<unordered_set>
#include<set>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
const int N = 100005, M = 11;
int mod = 1000000007;
bool possible(string a, unordered_map<char, int> mp)
{
    for(int i = 0; i < a.length(); i++)
    {
        if(mp.find(a[i])!=mp.end())
        {
            if(mp[a[i]]<=0)
                return false;
            mp[a[i]]--;
        }
    }
    return true;
}
void remove(unordered_map<char, int> &mp, string word)
{
    for(int i = 0; i < word.length(); i++)
    {
        if(mp.find(word[i])!=mp.end())
            mp[word[i]]--;
    }
}
void add(unordered_map<char, int> &mp, string word)
{
    for(int i = 0; i < word.length(); i++)
    {
        if(mp.find(word[i])!=mp.end())
            mp[word[i]]++;
    }
}
int getScore(string word, int *score)
{
    int s = 0;
    for(int i =0; i < word.length(); i++)
    {
        s+=(score[word[i]-97]);
    }
    return s;
}
int getMaxScore(string *arr, int *score, unordered_map<char, int> &mp, int i, int n)
{
    if(i == n)
        return 0;
    int ans = 0;
    if(possible(arr[i], mp))
    {
        remove(mp, arr[i]);
        ans = getScore(arr[i], score)+getMaxScore(arr, score, mp, i+1, n);
        add(mp, arr[i]);
    }
    return max(ans, getMaxScore(arr, score, mp, i+1, n));
}
int32_t main(){
    int n, m;
    cin>>n;
    string *arr = new string[n];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cin>>m;
    unordered_map<char, int> mp;
    for(int i = 0; i < m; i++)
    {
        char s;
        cin>>s;
        if(mp.find(s)== mp.end())
        {
            mp[s] = 1;
        }
        else
        {
            mp[s]+=1;
        }
    }
    int *score = new int[26];
    for(int i = 0; i < 26; i++)
    {
        cin>>score[i];
    }
    int ans = getMaxScore(arr, score, mp, 0, n);
    cout<<ans<<endl;
    return 0;
}
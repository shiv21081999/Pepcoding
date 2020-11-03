#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
#include <string>
#include <stdio.h>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back
const int N = 100005, M = 11;
int mod = 1000000007;
bool isPallindrome(string s)
{
    int l = 0, r = s.length() - 1;
    while(l <= r)
    {
        if(s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}
void printAllPalPartitions(string s, int index, string ans)
{
    if (index == s.length())
    {
        cout << ans << endl;
        return;
    }
    string check = "";
    for (int i = index; i < s.length(); i++)
    {
        check += s[i];
        if(isPallindrome(check))
        {
            printAllPalPartitions(s, i+1, ans + "("+check+") ");
        }
    }
}
int32_t main()
{
    string s;
    cin >> s;
    printAllPalPartitions(s, 0, "");
    return 0;
}
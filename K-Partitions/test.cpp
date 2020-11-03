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
int counter = 1;
void print(vector<vector<int>> ans)
{
    cout<<counter++<<". ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        int j = 0;
        for (j = 0; j < ans[i].size() - 1; j++)
        {
            cout << ans[i][j] << ", ";
        }
        cout << ans[i][j] << "] ";
    }
    cout << endl;
}
void solution(int i, int n, int k, bool *visited, vector<vector<int>> ans, int left)
{
    if(left == 0 && k == 0)
    {
        print(ans);
        return;
    }
    if(i > n)
        return;
    for(int j = 0; j < ans.size(); j++)
    {
        if(ans[j].size() > 0)
        {
            ans[j].push_back(i);
            solution(i+1, n, k, visited, ans, left-1);
            ans[j].pop_back();
        }
        else
        {
            ans[j].push_back(i);
            solution(i+1, n, k-1, visited, ans, left-1);
            ans[j].pop_back();
            break;
        }
        
    }
}
int32_t main()
{
    int n, k;
    cin >> n >> k;
    bool *visited = new bool[n + 1]();
    vector<vector<int>> ans(k);
    solution(1, n, k, visited, ans, n);
    return 0;
}
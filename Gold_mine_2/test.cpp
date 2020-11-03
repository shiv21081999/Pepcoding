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
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int getSum(int **arr, int i, int j, int n, int m, bool **visited)
{
    if(i < 0 || j <0 || i >= n || j >= m || arr[i][j] == 0 || visited[i][j])
        return 0;
    int ans = 0;
    visited[i][j] = true;
    for(int k =0; k < 4 ; k++)
    {
        ans += getSum(arr, i + dx[k], j + dy[k], n, m, visited);
    }
    return ans + arr[i][j];
}
int32_t main(){
    int n, m;
    cin>>n>>m;
    int **arr = new int*[n];
    for(int i =0 ; i < n ; i++)
    {
        arr[i] = new int[m];
        for(int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }    
    }
    bool **visited = new bool*[n];
    for(int i =0 ; i < n; i++)
    {
        visited[i] = new bool[m];
        for(int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }
    int ans = INT_MIN;
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j < m; j++)
        {
            if(arr[i][j] != 0 && !visited[i][j])
            {
                ans = max(ans, getSum(arr, i, j, n, m, visited));
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
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
bool check(int **grid, int row, int col, int val)
{
    for(int i = 0; i < 9; i++)
    {
        if(grid[i][col] == val)
            return false;
        if(grid[row][i] == val)
            return false;
    }
    for(int i = ((row/3)*3); i < ((row/3)*3) + 3; i++)
    {
        for(int j = ((col/3)*3); j < ((col/3)*3)+3; j++)
        {
            if(grid[i][j] == val)
                return false;
        }
    }
    return true;
}
void print(int **grid)
{
    for(int i =0 ; i < 9; i++)
    {
        for(int j =0; j < 9 ; j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}
void solve(int **grid, int row, int col)
{
    if(row == 9)
    {
        print(grid);
        exit(0);
    }
    if(col == 9)
    {
        solve(grid, row+1, 0);
        return;
    }
    if(grid[row][col] != 0)
    {
        solve(grid, row, col + 1);
        return;
    }
    for(int i = 1; i <= 9; i++)
    {
        if(check(grid, row, col, i))
        {
            grid[row][col] = i;
            solve(grid, row, col+1);
            grid[row][col] = 0;
        }
    }

}
int32_t main(){
    int **grid = new int*[9];
    for(int i = 0; i < 9 ; i++)
    {
        grid[i] = new int[9];
        for(int j = 0 ; j < 9; j++)
        {
            cin>>grid[i][j];
        }
    }
    solve(grid, 0, 0);
    return 0;
}
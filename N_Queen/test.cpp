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
bool row[11];
bool col[11];
bool diag1[22];
bool diag2[22];
void print(bool **board, int n)
{
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j])
            {
                cout<<i<<"-"<<j<<", ";
            }
        }
    }
    cout<<"."<<endl;
}
bool possible(bool **board, int r, int c, int n)
{
    if(row[r])
        return false;
    if(col[c])
        return false;
    if(diag1[r-c+n])
        return false;
    if(diag2[r+c])
        return false;
    return true;
}
void nQueen(bool **board, int r, int c, int n, int count)
{
    if(r == n)
    {
        
        if(count == n)
            print(board, n);
        return;
    }
    if(c == n)
    {
        nQueen(board, r+1, 0, n, count);
        return;
    }
    // cout<<r<<" "<<c<<endl;
    if(possible(board, r, c, n))
    {
        board[r][c] = true;
        row[r] = true;
        col[c] = true;
        diag1[r-c+n] = true;
        diag2[r+c] = true;
        nQueen(board, r+1, 0, n, count+1);
        board[r][c] = false;
        row[r] = false;
        col[c] = false;
        diag1[r-c+n] = false;
        diag2[r+c] = false;
    }
    nQueen(board, r, c+1, n, count);

}
int32_t main(){
    int n;
    cin>>n;
    bool **board = new bool*[n];
    for(int i = 0; i < n; i++)
    {
        board[i] = new bool[n];
        for(int j = 0; j < n; j++)
        {
            board[i][j] = false;
        }
    }
    for(int i = 0; i <= 10; i++)
    {
        row[i] = false;
        col[i] = false;
    }
    for(int i = 0; i < 22; i++)
    {
        diag1[i] = false;
        diag2[i] = false;
    }
    nQueen(board, 0, 0, n, 0);
    return 0;
}
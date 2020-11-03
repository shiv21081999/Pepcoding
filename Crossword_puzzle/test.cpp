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
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back
const int N = 100005, M = 11;
int mod = 1000000007;
char **copy(char **grid)
{
    char **arr = new char *[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = new char[10];
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = grid[i][j];
        }
    }
    return arr;
}
bool checkVertical(char **grid, int row, int col, string word)
{
    int c = 0, i = 0;
    if (row - 1 >= 0)
    {
        if (grid[row - 1][col] != '+')
        {
            if (grid[row - 1][col] == word[0])
            {
                c++;
                i++;
            }
            if (grid[row - 1][col] != word[0])
                return false;
        }
    }
    for (; i < word.length() && row < 10; i++)
    {
        if (grid[row][col] == '-')
            c++;
        else if (grid[row][col] == word[i])
            c++;
        else
            return false;
        row++;
    }
    if (c == word.length())
        return true;
    return false;
}
bool checkHorizontal(char **grid, int row, int col, string word)
{
    int c = 0, i = 0;
    if (col - 1 >= 0)
    {
        if (grid[row][col - 1] != '+')
        {
            if (grid[row][col - 1] == word[0])
            {
                c++;
                i++;
            }
            if (grid[row][col - 1] != word[0])
                return false;
        }
    }
    for (; i < word.length() && col < 10; i++)
    {
        if (grid[row][col] == '-')
            c++;
        else if (grid[row][col] == word[i])
            c++;
        else
            return false;
        col++;
    }
    if (c == word.length())
        return true;
    return false;
}
void fillVertical(char **grid, int row, int col, string word)
{
    int c = 0;
    if (row - 1 >= 0)
    {
        if (grid[row - 1][col] == word[0])
        {
            c++;
        }
    }
    for (int i = c; i < word.length(); i++)
    {
        grid[row][col] = word[i];
        row++;
    }
}

void fillHorizontal(char **grid, int row, int col, string word)
{
    int c = 0;
    if (col - 1 >= 0)
    {
        if (grid[row][col - 1] == word[0])
        {
            c++;
        }
    }
    for (int i = c; i < word.length(); i++)
    {
        grid[row][col] = word[i];
        col++;
    }
}

void print(char **grid)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
}
bool getEmpty(char **grid, int &row, int &col)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (grid[i][j] == '-')
            {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}
void fillCrossword(char **grid, string *arr, int n)
{
    int row, col;
    if (!getEmpty(grid, row, col))
    {
        print(grid);
        exit(0);
    }
    for (int i = 0; i < n; i++)
    {
        if (checkVertical(grid, row, col, arr[i]))
        {
            char **copyGrid = copy(grid);
            fillVertical(copyGrid, row, col, arr[i]);
            fillCrossword(copyGrid, arr, n);
        }
        if (checkHorizontal(grid, row, col, arr[i]))
        {
            char **copyGrid = copy(grid);
            fillHorizontal(copyGrid, row, col, arr[i]);
            fillCrossword(copyGrid, arr, n);
        }
    }
}
int32_t main()
{
    char **grid = new char *[10];
    for (int i = 0; i < 10; i++)
    {
        string a;
        cin >> a;
        grid[i] = new char[10];
        for (int j = 0; j < 10; j++)
        {
            grid[i][j] = a[j];
        }
    }
    int n;
    cin >> n;
    string *arr = new string[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    fillCrossword(grid, arr, n);
    return 0;
}
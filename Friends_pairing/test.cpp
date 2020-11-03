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
void solution(int i, int n, bool *visited, string asf)
{
    if (i > n)
    {
        cout << counter++ << "." << asf << endl;
        return;
    }
    if (visited[i])
    {
        solution(i + 1, n, visited, asf);
        return;
    }
    visited[i] = true;
    solution(i + 1, n, visited, asf + "(" + to_string(i) + ") ");
    visited[i] = false;
    for (int j = i + 1; j <= n; j++)
    {
        if (!visited[j])
        {
            visited[j] = true;
            visited[i] = true;
            solution(i + 1, n, visited, asf + "(" + to_string(i) + "," + to_string(j) + ") ");
            visited[i] = false;
            visited[j] = false;
        }
    }
}
int32_t main()
{
    int n;
    cin >> n;
    bool *visited = new bool[n + 1]();
    solution(1, n, visited, "");
    return 0;
}
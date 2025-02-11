#include <bits/stdc++.h>

using namespace std;

#define MAX 212345

int dp[MAX][2][3];

auto dfs(int i, int t, int n, vector<int> &vs)
{
    if(i >= n)
        return 0;

    if(dp[i][t][1] != INT_MAX)
        return min(dp[i][t][1], dp[i][t][2]);

    dp[i][t][1] = (vs[i]&t) + dfs(i + 1, 1 - t, n, vs);

    if(i + 1 < n)
        dp[i][t][2] = (vs[i]&t) + (vs[i + 1]&t) + dfs(i + 2, 1 - t, n, vs);

    return min(dp[i][t][1], dp[i][t][2]);
}

auto solve()
{
    int n;
    cin >> n;

    vector<int> vs(n);
    for(auto &x : vs)
    {
        cin >> x;
    }

    for(int i = 0; i <= n; i++)
    {
        dp[i][0][1] = INT_MAX;
        dp[i][0][2] = INT_MAX;
        dp[i][1][1] = INT_MAX;
        dp[i][1][2] = INT_MAX;
    }

    auto ans = dfs(0, 1, n, vs);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        cout << solve() << "\n";
    }

    return 0;
}

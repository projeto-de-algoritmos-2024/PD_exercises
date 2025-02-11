#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> vs(n);
    for(auto &x : vs)
        cin >> x;

    map<int, int> dp;
    pair<int, int> ans {0, 0};
    for(auto v : vs)
    {
        dp[v] = dp[v - 1] + 1;

        if(ans.second < dp[v])
        {
            ans.first = v;
            ans.second = dp[v];
        }
    }

    vector<int> res;
    for(int i = n - 1; i >= 0; i--)
    {
        if(vs[i] != ans.first)
            continue;

        --ans.first;
        res.emplace_back(i + 1);
    }

    reverse(res.begin(), res.end());
    cout << res.size() << "\n";

    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " \n"[i + 1 == res.size()];

    return 0;
}

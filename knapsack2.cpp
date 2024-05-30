#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define viip vector<pair<ll, ll>>
#define ff(i, a, b) for (ll i = a; i < b; ++i)
#define fr(i, a, b) for (ll i = a; i >= b; --i)
#define vs vector<string>
#define vec vector<ll>
#define mpll map<ll, ll>
#define mpcl map<char, ll>
#define mpsl map<string, ll>
#define pb push_back
#define vvi vector<vector<ll>>
#define srtv(v, n) sort(v.begin(), v.end())

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

void precal(string &s, vec &pre)
{
    for (int i = 1; i < s.length(); i += 1)
    {
        int pre_ind = pre[i - 1];
        while (pre_ind > 0 && s[i] != s[pre_ind])
        {
            pre_ind = pre[pre_ind - 1];
        }
        if (s[i] == s[pre_ind])
        {
            pre[i] = pre_ind + 1;
        }
        else
        {
            pre[i] = 0;
        }
    }
}
ll mod = 1e9 + 7;

int main()
{

    ll n, w;
    cin >> n >> w;
    vector<ll> value(n), weight(n);

    for (ll i = 0; i < n; ++i)
    {
        cin >> weight[i];
        cin >> value[i];
    }

    ll max_val = 1e5;
    vector<vector<ll>> dp(n, vector<ll>(max_val + 1, LLONG_MAX));

    // base case
    dp[0][0] = 0;
    if (value[0] <= max_val)
    {
        dp[0][value[0]] = weight[0];
    }

    for (ll i = 1; i < n; ++i)
    {
        for (ll val_left = 0; val_left <= max_val; ++val_left)
        {
            dp[i][val_left] = dp[i - 1][val_left];
            if (val_left >= value[i] && dp[i - 1][val_left - value[i]] != LLONG_MAX)
            {
                dp[i][val_left] = min(dp[i][val_left], dp[i - 1][val_left - value[i]] + weight[i]);
            }
        }
    }

    ll ans = 0;
    for (ll val = 0; val <= max_val; ++val)
    {
        if (dp[n - 1][val] <= w)
        {
            ans = val;
        }
    }

    cout << ans << endl;
    // for (int i = 0; i < 5; i += 1)
    // {
    //     for (int j = 0; j < 4; j += 1)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
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

    ff(i, 0, n)
    {
        cin >> weight[i];
        cin >> value[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(w + 1, 0));

    // dp[0][0] = 0;
    // base case if i am at 0th index then if i have the weight greater than the desired weight then i will take all the value indexed at 0th
    for (int i = weight[0]; i <= w; i += 1)
    {
        dp[0][i] = value[0];
    }

    for (int i = 1; i < n; i += 1)
    {
        for (int j = 0; j <= w; j += 1)
        {
            ll skip = 0 + dp[i - 1][j];
            ll take = 0;

            if (j >= weight[i])
                take = dp[i - 1][j - weight[i]] + value[i];
            dp[i][j] = max(take, skip);
        }
    }

    cout << dp[n - 1][w];

    return 0;
}
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
ll mod = 1e9 + 7;

int main()
{
    ll n, x;
    cin >> n >> x;
    vec v(n);
    for (int i = 0; i < n; i += 1)
    {
        cin >> v[i];
    }
    vec dp(x + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= x; i += 1)

    {
        for (int j = 0; j < n; j += 1)
        {
            if (i >= v[j])
            {
                dp[i] = min(dp[i], dp[i - v[j]] + 1);
            }
        }
    }
    if (dp[x] == 1e9)
    {
        cout << -1;
    }
    else
    {
        cout << dp[x];
    }

    return 0;
}
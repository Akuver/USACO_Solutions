#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MODA 998244353
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sorta(A, N) sort(A, A + N)
#define debug(x) cerr << #x << " is " << x;
#define rep(i, a, N) for (ll i = a; i < N; i++)
#define f first
#define s second
#define uniq(v)                                       \
    {                                                 \
        sort(v.begin(), v.end());                     \
        v.erase(unique(v.begin(), v.end()), v.end()); \
    }
#define speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
void solve(ll tcase)
{
    ll N, K;
    cin >> N >> K;
    ll a[N + 1], prefix[N + 1];
    rep(i, 1, N + 1) cin >> a[i];
    a[0] = 0, prefix[0] = 0;
    rep(i, 1, N + 1) prefix[i] = prefix[i - 1] + a[i];
    pair<ll, ll> dp[N + 1][K + 1];
    rep(k, 0, K + 1) dp[0][k] = {0, 0};
    ll maxi = 0;
    rep(n, 1, N + 1)
    {
        maxi = max(maxi, a[n]);
        ll waste = maxi * n - prefix[n];
        dp[n][0] = {waste, maxi};
    }
    rep(n, 1, N + 1)
    {
        rep(k, 1, K + 1)
        {
            ll mn = 1e18, sz = -1;
            if (dp[n - 1][k].s >= a[n])
            {
                mn = dp[n - 1][k].f + dp[n - 1][k].s - a[n];
                sz = dp[n - 1][k].s;
            }
            maxi = a[n];
            for (ll j = n - 1; j >= 0; j--)
            {
                if (mn > dp[j][k - 1].f + maxi * (n - j) - prefix[n] + prefix[j])
                {
                    mn = dp[j][k - 1].f + maxi * (n - j) - prefix[n] + prefix[j];
                    sz = maxi;
                }
                maxi = max(maxi, a[j]);
            }
            dp[n][k] = {mn, sz};
        }
    }
    cout << dp[N][K].f;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
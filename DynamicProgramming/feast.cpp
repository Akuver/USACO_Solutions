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
    ll T, A, B;
    cin >> T >> A >> B;
    ll dp[T + 1][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = dp[0][1] = 1;
    rep(i, 1, T + 1)
    {
        if (i - A >= 0)
            dp[i][0] |= dp[i - A][0];
        if (i - B >= 0)
            dp[i][0] |= dp[i - B][0];
    }

    for (ll i = T; i >= 0; i--)
        dp[i / 2][1] |= dp[i][0];
    for (ll i = 0; i <= T; i++)
    {
        dp[i][1] |= (dp[i / 2][1] & dp[(i + 1) / 2][0]);
        if (i - A >= 0)
        {
            dp[i][1] |= dp[i - A][1];
        }
        if (i - B >= 0)
        {
            dp[i][1] |= dp[i - B][1];
        }
    }
    for (ll i = T; i >= 0; i--)
    {
        if (dp[i][0] || dp[i][1])
        {
            cout << i;
            return;
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
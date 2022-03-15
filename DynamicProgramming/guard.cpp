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
const ll MAXN = 20;
ll dp[1 << MAXN], height[1 << MAXN], N, H;
ll h[MAXN], w[MAXN], str[MAXN], maxi = -1;

void solve(ll tcase)
{
    cin >> N >> H;
    rep(i, 0, N) cin >> h[i] >> w[i] >> str[i];
    dp[0] = 1e18;
    rep(s, 1, (1 << N))
    {
        dp[s] = -1;
        rep(x, 0, N)
        {
            if (s & (1 << x))
            {
                height[s] += h[x];
                if (dp[s - (1 << x)] >= w[x])
                    dp[s] = max(dp[s], min(dp[s - (1 << x)] - w[x], str[x]));
            }
        }
        if (height[s] >= H)
            maxi = max(maxi, dp[s]);
    }

    (maxi >= 0)
        ? cout << maxi
        : cout << "Mark is too tall";
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
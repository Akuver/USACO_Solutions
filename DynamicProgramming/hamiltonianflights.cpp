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
ll dp[1 << MAXN][MAXN + 1], n, m;
vector<ll> adj[MAXN + 1];
ll add(ll a, ll b, ll mod = MOD)
{
    a %= MOD, b %= MOD;
    a += b;
    a %= MOD;
    return a;
}
void solve(ll tcase)
{
    cin >> n >> m;
    rep(i, 0, m)
    {
        ll u, v;
        cin >> u >> v;
        adj[v].pb(u);
    }
    dp[1][1] = 1;
    for (ll s = 2; s < (1 << n); s++)
    {
        if (s & (1 << (n - 1)) && s != (1 << n) - 1)
            continue;
        for (ll i = 1; i <= n; i++)
        {
            if (s & (1 << (i - 1)))
                for (auto x : adj[i])
                {
                    if (s & (1 << (x - 1)))
                        dp[s][i] = add(dp[s][i], dp[s - (1 << (i - 1))][x]);
                }
        }
    }
    cout << dp[(1 << n) - 1][n];
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
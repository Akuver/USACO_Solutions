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
const ll N = 105;
vector<ll> adj[N];
ll vis[N], deg[N];
void foo(ll n)
{
    rep(i, 1, n + 1) vis[i] = 0;
}
void dfs(ll u)
{
    vis[u] = 1;
    for (auto v : adj[u])
        if (!vis[v])
            dfs(v);
}
void solve(ll tcase)
{
    ll n;
    cin >> n;
    rep(i, 0, n - 1)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    rep(i, 1, n + 1)
    {
        dfs(i);
        rep(j, 1, n + 1) deg[j] += vis[j];
        foo(n);
    }
    rep(i, 1, n + 1) if (deg[i] == n)
    {
        cout << i;
        return;
    }
    cout << -1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
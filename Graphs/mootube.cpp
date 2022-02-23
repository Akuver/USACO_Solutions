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
const ll MAXN = 5000;
vector<pair<ll, ll> > adj[MAXN];
ll relv[MAXN];
void dfs(ll node, ll par = -1, ll rel = 1e18)
{
    relv[node] = rel;
    for (auto child : adj[node])
        if (child.f != par)
            dfs(child.f, node, min(relv[node], child.s));
}
void solve(ll tcase)
{
    ll n, q;
    cin >> n >> q;
    rep(i, 0, n - 1)
    {
        ll u, v, r;
        cin >> u >> v >> r;
        u--, v--;
        adj[u].pb({v, r});
        adj[v].pb({u, r});
    }
    while (q--)
    {
        ll k, v, cnt = 0;
        cin >> k >> v;
        v--;
        rep(i, 0, n) relv[i] = 1e18;
        dfs(v);
        rep(i, 0, n) if (relv[i] >= k && i != v) cnt++;
        cout << cnt << "\n";
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
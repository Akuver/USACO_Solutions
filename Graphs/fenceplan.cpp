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
const ll N = 2e5;
vector<ll> adj[N];
ll vis[N];
array<ll, 4> dfs(ll node, const vector<pair<ll, ll> > &cows)
{
    array<ll, 4> res;
    res[0] = res[2] = 1e18;
    res[1] = res[3] = 0;
    vis[node] = 1;
    res[0] = min(res[0], cows[node].f);
    res[1] = max(res[1], cows[node].f);
    res[2] = min(res[2], cows[node].s);
    res[3] = max(res[3], cows[node].s);
    for (auto child : adj[node])
        if (!vis[child])
        {
            array<ll, 4> v = dfs(child, cows);
            res[0] = min(res[0], v[0]);
            res[1] = max(res[1], v[1]);
            res[2] = min(res[2], v[2]);
            res[3] = max(res[3], v[3]);
        }
    return res;
}
void solve(ll tcase)
{
    ll m, n, mini = 1e18;
    cin >> n >> m;
    vector<pair<ll, ll> > cows(n);
    rep(i, 0, n) cin >> cows[i].f >> cows[i].s;
    rep(i, 0, m)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    rep(i, 0, n)
    {
        if (!vis[i])
        {
            auto res = dfs(i, cows);
            mini = min(mini, 2 * (res[1] - res[0] + res[3] - res[2]));
        }
    }
    cout << mini;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
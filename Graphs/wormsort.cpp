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
const ll N = 1e5;
vector<pair<ll, ll> > adj[N];
vector<ll> grp(N);
ll p[N], n, m;
void dfs(ll node, ll label, ll minW)
{
    grp[node] = label;
    for (auto child : adj[node])
    {
        if (child.s < minW || grp[child.f] != -1)
            continue;
        dfs(child.f, label, minW);
    }
}
bool valid(ll x)
{

    rep(i, 0, n) grp[i] = -1;
    ll cnt = -1;
    rep(i, 0, n)
    {
        if (grp[i] != -1)
            continue;
        dfs(i, ++cnt, x);
    }
    rep(i, 0, n) if (grp[i] != grp[p[i]]) return false;
    return true;
}
void solve(ll tcase)
{
    cin >> n >> m;
    rep(i, 0, n)
    {
        cin >> p[i];
        p[i]--;
    }
    rep(i, 0, m)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    ll lo = 0, hi = 1e9 + 2;
    while (lo < hi)
    {
        ll mid = (lo + hi) / 2;
        if (valid(mid))
            lo = mid + 1;
        else
            hi = mid;
    }
    if (lo - 1 > 1e9)
        lo = 0;
    cout << lo - 1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
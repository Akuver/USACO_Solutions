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
const ll MAXN = 2e5;
vector<ll> adj[MAXN];
ll dis[MAXN], n;
void dfs(ll node, ll par = -1, ll dist = 0)
{
    dis[node] = dist;
    for (auto child : adj[node])
        if (child != par)
            dfs(child, node, dis[node] + 1);
}
void solve(ll tcase)
{
    cin >> n;
    rep(i, 0, n - 1)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0);
    ll maxdis = 0, maxdisnode = -1;
    rep(i, 0, n)
    {
        if (dis[i] > maxdis)
            maxdis = dis[i], maxdisnode = i;
        dis[i] = 0;
    }
    dfs(maxdisnode);
    rep(i, 0, n) maxdis = max(maxdis, dis[i]);
    cout << maxdis;
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
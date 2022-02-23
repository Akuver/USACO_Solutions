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
const ll MAXN = 1e5;
ll n, m, cnt;
string s;
vector<ll> adj[MAXN];
ll comp[MAXN];
void dfs(ll node)
{
    comp[node] = cnt;
    for (auto child : adj[node])
        if (!comp[child] && s[node] == s[child])
            dfs(child);
}
void solve(ll tcase)
{
    cin >> n >> m >> s;
    rep(i, 0, n - 1)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    rep(i, 0, n) if (!comp[i])
    {
        ++cnt;
        dfs(i);
    }
    rep(i, 0, m)
    {
        char c;
        ll u, v;
        cin >> u >> v >> c;
        u--, v--;
        if (comp[u] != comp[v] || s[u] == c)
            cout << 1;
        else
            cout << 0;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
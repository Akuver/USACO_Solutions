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
vector<ll> adj[N][2];
ll vis[N][2];
void dfs(ll node, ll t)
{
    vis[node][t] = 1;
    for (auto child : adj[node][t])
        if (!vis[child][t])
            dfs(child, t);
}
void solve(ll tcase)
{
    ll n, m;
    cin >> n >> m;
    rep(i, 0, m)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        adj[u][0].pb(v);
        adj[v][1].pb(u);
    }
    dfs(0, 0);
    dfs(0, 1);
    rep(i, 0, n)
    {
        if (!vis[i][0])
        {
            cout << "NO\n";
            cout << "1 " << i + 1;
            return;
        }
        if (vis[i][0] != vis[i][1])
        {
            cout << "NO\n";
            cout << i + 1 << ' ' << 1 << "\n";
            return;
        }
    }
    cout << "YES";
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
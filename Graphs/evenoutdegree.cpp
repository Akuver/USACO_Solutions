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
vector<ll> adj[MAXN];
ll tim[MAXN], odd[MAXN], timer;
vector<pair<ll, ll> > ans;
void dfs(ll node, ll par = -1)
{
    tim[node] = ++timer;
    for (auto child : adj[node])
    {
        if (child == par)
            continue;
        if (!tim[child])
        {
            dfs(child, node);
            if (odd[child])
            {
                ans.pb({child, node});
                odd[child] = 0;
            }
            else
            {
                ans.pb({node, child});
                odd[node] = !odd[node];
            }
        }
        else if (tim[node] > tim[child])
        {
            ans.pb({node, child});
            odd[node] = !odd[node];
        }
    }
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
        adj[u].pb(v);
        adj[v].pb(u);
    }
    rep(i, 0, n) if (!tim[i]) dfs(i);
    rep(i, 0, n) if (odd[i])
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (auto i : ans)
        cout << i.f + 1 << ' ' << i.s + 1 << "\n";
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
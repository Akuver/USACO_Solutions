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
const ll MAXN = 1e4;
vector<ll> adj[MAXN];
ll p[MAXN], vis[MAXN];
void dfs(ll node)
{
    vis[node] = 1;
    for (auto child : adj[node])
        if (!vis[child])
            dfs(child);
}
void solve(ll tcase)
{
    ll n, cnt = 0;
    cin >> n;
    rep(i, 0, n)
    {
        ll x;
        cin >> x;
        x--;
        adj[i].pb(x);
        adj[x].pb(i);
    }
    rep(i, 0, n) if (!vis[i])
    {
        dfs(i), cnt++;
    }

    cout << cnt;
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
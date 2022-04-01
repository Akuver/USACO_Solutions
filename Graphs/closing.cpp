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
const ll MAXN = 2e5 + 1;
ll p[MAXN], siz[MAXN];
vector<ll> adj[MAXN];
bool added[MAXN];
ll par(ll x)
{
    if (p[x] == x)
        return x;
    return p[x] = par(p[x]);
}
ll merg(ll a, ll b)
{
    ll pa = par(a), pb = par(b);
    if (pa == pb)
        return 0;
    if (siz[pa] >= siz[pb])
        siz[pa] += siz[pb], p[pb] = pa;
    else
        siz[pb] += siz[pa], p[pa] = pb;
    return 1;
}
void solve(ll tcase)
{
    ll n, m;
    cin >> n >> m;
    rep(i, 1, n + 1) p[i] = i, siz[i] = 1;
    vector<ll> remov(n), cnt;
    rep(i, 0, m)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    rep(i, 0, n) cin >> remov[i];
    reverse(remov.begin(), remov.end());
    ll count = 0;
    rep(i, 0, n)
    {
        ll u = remov[i];
        added[u] = 1;
        count++;
        for (auto v : adj[u])
        {
            if (added[v])
                count -= merg(u, v);
        }
        cnt.pb(count);
    }
    reverse(cnt.begin(), cnt.end());
    rep(i, 0, n)
    {
        if (cnt[i] == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
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
const ll MAXN = 1000;
vector<pair<ll, pair<ll, ll> > > edges;
ll p[MAXN], sz[MAXN];
ll dist(pair<ll, ll> a, pair<ll, ll> b)
{
    return (a.f - b.f) * (a.f - b.f) + (a.s - b.s) * (a.s - b.s);
}
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
    if (sz[pa] >= sz[pb])
    {
        sz[pa] += sz[pb];
        p[pb] = pa;
    }
    else
    {
        sz[pb] += sz[pa];
        p[pa] = pb;
    }
    return 1;
}
void solve(ll tcase)
{
    ll N;
    cin >> N;
    pair<ll, ll> cows[N];
    vector<ll> used;
    rep(i, 0, N)
    {
        cin >> cows[i].f >> cows[i].s;
        p[i] = i, sz[i] = 1;
    }
    rep(i, 0, N) rep(j, i + 1, N)
    {
        ll w = dist(cows[i], cows[j]);
        edges.pb({w, {i, j}});
        edges.pb({w, {j, i}});
    }
    sortv(edges);
    rep(i, 0, edges.size())
    {
        ll w = edges[i].f, u = edges[i].s.f, v = edges[i].s.s;
        if (merg(u, v))
            used.pb(w);
    }
    cout << *max_element(used.begin(), used.end());
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
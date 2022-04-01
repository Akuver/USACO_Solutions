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
const ll MAXN = 1e5 + 1;
vector<pair<ll, pair<ll, ll> > > edges;
ll p[MAXN], sz[MAXN];
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
    ll N, M;
    cin >> N >> M;
    set<ll> wrong;
    map<ll, ll> cur;
    vector<ll> used;
    rep(i, 1, N + 1)
    {
        ll x;
        cin >> x;
        if (x != i)
            wrong.insert(x), cur[x] = i;
    }
    rep(i, 1, N + 1) p[i] = i, sz[i] = 1;
    rep(i, 0, M)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        edges.pb({-w, {a, b}});
        edges.pb({-w, {b, a}});
    }
    if (wrong.empty())
    {
        cout << -1;
        return;
    }
    sortv(edges);
    rep(i, 0, edges.size())
    {
        if (wrong.empty())
            break;
        ll w = edges[i].f, a = edges[i].s.f, b = edges[i].s.s;
        if (merg(a, b))
        {
            used.pb(w);
            if (cur[a])
            {
                ll x = par(cur[a]);
                ll y = par(a);
                if (x == y)
                {
                    auto it = wrong.find(a);
                    if (it != wrong.end())
                        wrong.erase(it);
                    it = wrong.find(cur[a]);
                    if (it != wrong.end())
                        wrong.erase(it);
                }
            }
            if (cur[b])
            {
                ll x = par(cur[b]);
                ll y = par(b);
                if (x == y)
                {
                    auto it = wrong.find(b);
                    if (it != wrong.end())
                        wrong.erase(it);
                    it = wrong.find(cur[b]);
                    if (it != wrong.end())
                        wrong.erase(it);
                }
            }
        }
    }
    cout << -(*max_element(used.begin(), used.end()));
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
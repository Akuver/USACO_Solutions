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
ll maxi = 1, comps, n, m;
ll siz[MAXN], p[MAXN];
ll par(ll x)
{
    if (p[x] == x)
        return x;
    return p[x] = par(p[x]);
}
void merg(ll a, ll b)
{
    ll pa = par(a), pb = par(b);
    if (pa == pb)
        return;
    comps--;
    if (siz[pa] >= siz[pb])
    {
        siz[pa] += siz[pb];
        p[pb] = pa;
    }
    else
    {
        siz[pb] += siz[pa];
        p[pa] = pb;
    }
    maxi = max(maxi, max(siz[pb], siz[pa]));
}
void solve(ll tcase)
{
    cin >> n >> m;
    rep(i, 0, n) p[i] = i, siz[i] = 1;
    comps = n;
    rep(i, 0, m)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        merg(u, v);
        cout << comps << ' ' << maxi << "\n";
    }
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
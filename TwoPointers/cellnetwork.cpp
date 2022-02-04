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
void solve(ll tcase)
{
    ll n, m, r = 0;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    uniq(a);
    uniq(b);
    vector<pair<ll, ll> > c;
    ll posa = 0, posb = 0;
    while (posa < a.size() && posb < b.size())
    {
        if (a[posa] <= b[posb])
            c.pb({a[posa++], 0});
        else
            c.pb({b[posb++], 1});
    }
    while (posa < a.size())
        c.pb({a[posa++], 0});
    while (posb < b.size())
        c.pb({b[posb++], 1});
    ll x = c.size();
    ll pt[x], st[x];
    ll maxi = 1e18;
    ll prevt = -maxi;
    rep(i, 0, x)
    {
        if (c[i].s)
            prevt = c[i].f;
        pt[i] = prevt;
    }
    prevt = -maxi;
    for (ll i = x - 1; i >= 0; i--)
    {
        if (c[i].s)
            prevt = c[i].f;
        st[i] = prevt;
    }
    rep(i, 0, x)
    {
        if (!c[i].s)
        {
            ll a = (pt[i] != -maxi) ? abs(c[i].f - pt[i]) : maxi;
            ll b = (st[i] != -maxi) ? abs(c[i].f - st[i]) : maxi;
            r = max(r, min(a, b));
        }
    }
    cout << r;
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
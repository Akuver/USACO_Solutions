#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MODA 998244353
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sorta(A, N) sort(A, A + N)
#define debug(x) cerr << #x << "is" << x;
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
ll ans(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c)
{
    ll area = 0;
    ll x1 = a.f, y1 = a.s, x2 = b.f, y2 = b.s, x3 = c.f, y3 = c.s;
    if ((y1 == y2 && x1 == x3) || (y1 == y3 && x1 == x2) || (y2 == y3 && x2 == x1) || (x2 == x3 && y2 == y1) || (y3 == y1 && x3 == x2) || (x3 == x1 && y3 == y2))
        area = abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x3 * y2 - x2 * y1);

    return area;
}
void solve(ll tcase)
{
    ll n, area = 0;
    cin >> n;
    pair<ll, ll> points[n];
    rep(i, 0, n) cin >> points[i].f >> points[i].s;
    rep(i, 0, n)
        rep(j, i + 1, n)
            rep(k, j + 1, n)
                area = max(area, ans(points[i], points[j], points[k]));

    cout << area;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
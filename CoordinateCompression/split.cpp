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
bool legal(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4)
{
    ll cx = max(min(x2, x4) - max(x1, x3), 0LL);
    ll cy = max(min(y2, y4) - max(y1, y3), 0LL);
    ll commonarea = cx * cy;
    if (!commonarea && (min(x2, x4) != max(x1, x3)) && (min(y2, y4) != max(y1, y3)))
        return true;
    return false;
}
bool comp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    if (a.s == b.s)
        return a.f < b.f;
    return a.s < b.s;
}
void solve(ll tcase)
{
    ll n, ans1 = 0, ans2 = 0, maxx = 0, minx = 1e18, maxy = 0, miny = 1e18, res = -1e18;
    cin >> n;
    pair<ll, ll> p[n];
    rep(i, 0, n)
    {
        cin >> p[i].f >> p[i].s;
        maxx = max(maxx, p[i].f);
        minx = min(minx, p[i].f);
        maxy = max(maxy, p[i].s);
        miny = min(miny, p[i].s);
    }
    ans1 = (maxx - minx) * (maxy - miny);
    rep(k, 0, 2)
    {
        if (!k)
            sorta(p, n);
        else
            sort(p, p + n, comp);
        ll xupto[n][2], xback[n][2], yupto[n][2], yback[n][2];
        rep(i, 0, n)
        {
            rep(j, 0, 2)
            {
                // 0-max,1-min
                ll x = (!j) ? 0LL : max(maxx, maxy) + 1;
                xupto[i][j] = x;
                xback[i][j] = x;
                yupto[i][j] = x;
                yback[i][j] = x;
            }
        }
        rep(i, 0, n)
        {
            xupto[i][0] = max((i - 1 >= 0) ? xupto[i - 1][0] : 0LL, p[i].f);
            yupto[i][0] = max((i - 1 >= 0) ? yupto[i - 1][0] : 0LL, p[i].s);
            xupto[i][1] = min((i - 1 >= 0) ? xupto[i - 1][1] : max(maxx, maxy) + 1, p[i].f);
            yupto[i][1] = min((i - 1 >= 0) ? yupto[i - 1][1] : max(maxx, maxy) + 1, p[i].s);
        }
        for (ll i = n - 1; i >= 0; i--)
        {
            xback[i][0] = max((i + 1 < n) ? xback[i + 1][0] : 0LL, p[i].f);
            yback[i][0] = max((i + 1 < n) ? yback[i + 1][0] : 0LL, p[i].s);
            xback[i][1] = min((i + 1 < n) ? xback[i + 1][1] : max(maxx, maxy) + 1, p[i].f);
            yback[i][1] = min((i + 1 < n) ? yback[i + 1][1] : max(maxx, maxy) + 1, p[i].s);
        }
        rep(i, 0, n - 1)
        {
            ll a1 = (xupto[i][0] - xupto[i][1]) * (yupto[i][0] - yupto[i][1]);
            ll a2 = (xback[i + 1][0] - xback[i + 1][1]) * (yback[i + 1][0] - yback[i + 1][1]);
            if (legal(xupto[i][1], yupto[i][1], xupto[i][0], yupto[i][0], xback[i + 1][1], yback[i + 1][1], xback[i + 1][0], yback[i + 1][0]))
            {
                ans2 = a1 + a2;
                res = max(res, ans1 - ans2);
            }
        }
    }
    cout << res;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
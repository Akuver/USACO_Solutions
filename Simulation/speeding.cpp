#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define cd complex<double>
#define MOD 1000000007
#define MODA 998244353
#define pb push_back
#define mp make_pair
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
ll slimit(pair<ll, ll> a[], ll n, ll mile)
{
    ll res = 0;
    rep(i, 0, n)
    {
        if (mile <= a[i].f)
        {
            res = a[i].s;
            break;
        }
    }
    return res;
}
void solve(ll tcase)
{
    ll n, m, ans = 0;
    cin >> n >> m;
    pair<ll, ll> a[n], b[m];
    rep(i, 0, n)
    {
        cin >> a[i].f >> a[i].s;
        if (i)
            a[i].f += a[i - 1].f;
    }
    rep(i, 0, m)
    {
        cin >> b[i].f >> b[i].s;
        if (i)
            b[i].f += b[i - 1].f;
    }
    rep(mile, 1, 101) ans = max(ans, slimit(b, m, mile) - slimit(a, n, mile));
    cout << ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
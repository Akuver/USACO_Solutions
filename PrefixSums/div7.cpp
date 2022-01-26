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
    ll n;
    cin >> n;
    ll a[n];
    rep(i, 0, n) cin >> a[i];
    rep(i, 1, n) a[i] += a[i - 1];
    ll lo = 0, hi = n + 1;
    while (lo < hi)
    {
        ll m = (lo + hi) / 2;
        bool ok = false;
        rep(i, 0, n)
        {
            ll l = i, r = i + m - 1;
            if (r >= n)
                break;
            if ((a[r] - (l - 1 >= 0 ? a[l - 1] : 0LL)) % 7 == 0)
            {
                ok = true;
                break;
            }
        }
        if (!ok)
            hi = m;
        else
            lo = m + 1;
    }
    cout << lo - 1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
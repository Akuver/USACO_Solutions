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
    ll n, m, c;
    cin >> n >> m >> c;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sortv(a);
    ll lo = 0, hi = a[n - 1] - a[0] + 1;
    while (lo < hi)
    {
        ll mid = (lo + hi) / 2;
        ll pos = 0, left = m;
        while (true)
        {
            auto it = upper_bound(a.begin(), a.end(), a[pos] + mid);
            it--;
            ll x = min(it - a.begin() - pos + 1, c);
            pos += x;
            left--;
            if (pos >= n)
                break;
            if (!left)
                break;
        }
        if (pos >= n)
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
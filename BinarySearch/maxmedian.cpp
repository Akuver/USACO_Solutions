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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sortv(a);
    ll lo = a[n / 2], hi = a[n - 1] + k + 5;
    while (lo < hi)
    {
        ll m = (lo + hi) / 2;
        ll req = 0;
        rep(i, n / 2, n)
            req += max(m - a[i], 0LL);
        if (req <= k)
            lo = m + 1;
        else
            hi = m;
    }
    cout << lo - 1;
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
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
    ll n, t;
    cin >> n >> t;
    vector<ll> k(n);
    rep(i, 0, n) cin >> k[i];
    ll lo = 0, hi = 1e18;
    while (lo < hi)
    {
        ll mid = (lo + hi) / 2;
        ll prod = 0;
        rep(i, 0, n)
        {
            prod += mid / k[i];
            if (prod >= t)
                break;
        }
        if (prod >= t)
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << hi;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
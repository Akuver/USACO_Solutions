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
ll LIS(ll a[], ll n)
{
    vector<ll> d(n + 1, 1e18);
    d[0] = -1e18;
    rep(i, 1, n + 1)
    {
        auto j = upper_bound(d.begin(), d.end(), a[i - 1]) - d.begin();
        if (d[j - 1] < a[i - 1] && a[i - 1] < d[j])
            d[j] = a[i - 1];
    }
    ll maxi = 0;
    rep(i, 1, n + 1) if (d[i] < 1e18) maxi = i;
    return maxi;
}
void solve(ll tcase)
{
    ll n;
    cin >> n;
    ll a[n], b[n], pos[n], c[n];
    rep(i, 0, n)
    {
        cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
    }
    rep(i, 0, n)
    {
        cin >> b[i];
        b[i]--;
        c[i] = pos[b[i]];
    }
    cout << LIS(c, n);
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
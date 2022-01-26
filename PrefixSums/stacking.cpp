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
    vector<ll> a(n, 0);
    while (k--)
    {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        a[l]++;
        if (r + 1 < n)
            a[r + 1]--;
    }
    rep(i, 1, n) a[i] += a[i - 1];
    sortv(a);
    cout << a[n / 2];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("stacking.in", "r", stdin);
    freopen("stacking.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
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
    ll n, k, ans = 0;
    cin >> n >> k;
    vector<ll> a;
    rep(i, 0, n)
    {
        ll x;
        cin >> x;
        a.pb(x);
    }
    sortv(a);
    ll canTakeLeft[n];
    ll r = 0;
    rep(l, 0, n)
    {
        while (r < n && a[r] - a[l] <= k)
            r++;
        canTakeLeft[l] = r - l;
    }
    ll maxAfterI[n + 1]; // max at pos>=i
    maxAfterI[n] = 0;
    for (ll i = n - 1; i >= 0; i--)
        maxAfterI[i] = max(maxAfterI[i + 1], canTakeLeft[i]);
    rep(l, 0, n)
        ans = max(ans, canTakeLeft[l] + ((l + canTakeLeft[l] <= n) ? maxAfterI[l + canTakeLeft[l]] : 0LL));
    cout << ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
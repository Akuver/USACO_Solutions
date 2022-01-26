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
    ll n, k, b, ans = n + 1;
    cin >> n >> k >> b;
    ll a[n];
    memset(a, 0, sizeof(a));
    rep(i, 0, b)
    {
        ll x;
        cin >> x;
        x--;
        a[x] = 1;
    }
    rep(i, 1, n) a[i] += a[i - 1];
    rep(i, 0, n)
    {
        ll l = i, r = i + k - 1;
        if (r >= n)
            break;
        ans = min(ans, a[r] - (l - 1 >= 0 ? a[l - 1] : 0LL));
    }
    cout << ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
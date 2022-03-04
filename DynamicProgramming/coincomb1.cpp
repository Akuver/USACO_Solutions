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
const ll MAXN = 105;
const ll MAXX = 1e6 + 5;
ll c[MAXN], dp[MAXX], n, x;
ll add(ll a, ll b, ll mod = MOD)
{
    a %= mod, b %= mod;
    a += b;
    a %= mod;
    return a;
}
ll ans(ll sum)
{
    if (sum < 0)
        return 0;
    if (!sum)
        return 1;
    if (dp[sum] != -1)
        return dp[sum];
    ll res = 0;
    rep(i, 0, n) res = add(res, ans(sum - c[i]));
    return dp[sum] = res;
}
void solve(ll tcase)
{
    cin >> n >> x;
    rep(i, 0, n) cin >> c[i];
    memset(dp, -1, sizeof(dp));
    cout << ans(x);
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
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
const ll MAXN = 501;
const ll MAXSUM = 1e5;
ll n;
ll c[MAXN], dp[MAXN][MAXSUM];
ll power(ll a, ll b, ll mod = MOD)
{
    a %= mod;
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll add(ll a, ll b)
{
    a %= MOD, b %= MOD;
    a += b;
    a %= MOD;
    return a;
}
ll modInverse(ll a)
{
    return power(a, MOD - 2);
}
ll mult(ll a, ll b)
{
    a %= MOD, b %= MOD;
    a *= b;
    a %= MOD;
    return a;
}
void solve(ll tcase)
{
    cin >> n;
    rep(i, 1, n + 1) c[i] = i;
    ll sum = n * (n + 1);
    sum /= 2;
    if (sum & 1)
    {
        cout << 0;
        return;
    }
    sum /= 2;
    rep(i, 0, n + 1) dp[i][0] = 1;
    rep(i, 1, n + 1)
    {
        rep(j, 1, sum + 1)
        {
            dp[i][j] = add(dp[i][j], dp[i - 1][j]);
            if (j - c[i] >= 0)
                dp[i][j] = add(dp[i][j], dp[i - 1][j - c[i]]);
        }
    }
    dp[n][sum] = mult(dp[n][sum], modInverse(2));
    cout << dp[n][sum];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
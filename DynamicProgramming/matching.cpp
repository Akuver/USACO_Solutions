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
const ll MAXN = 21;
ll dp[1 << MAXN], n;
ll a[MAXN][MAXN];
ll add(ll a, ll b, ll mod = MOD)
{
    a %= mod, b %= mod;
    a += b;
    a %= mod;
    return a;
}
void solve(ll tcase)
{
    cin >> n;
    rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];
    dp[0] = 1;
    rep(s, 0, (1 << n))
    {
        ll pairs = __builtin_popcount(s);
        rep(j, 0, n)
        {
            if (s & (1 << j) || !a[pairs][j])
                continue;
            dp[s | (1 << j)] = add(dp[s | (1 << j)], dp[s]);
        }
    }
    cout << dp[(1 << n) - 1];
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
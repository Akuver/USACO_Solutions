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
    string a, b;
    cin >> a >> b;
    ll n = a.size(), m = b.size();
    ll dp[n + 1][m + 1];
    rep(i, 0, n + 1) rep(j, 0, m + 1) dp[i][j] = 1e18;
    rep(i, 0, n) dp[i][0] = i;
    rep(i, 0, m) dp[0][i] = i;
    rep(i, 1, n + 1)
    {
        rep(j, 1, m + 1)
        {
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]));
        }
    }
    cout << dp[n][m];
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
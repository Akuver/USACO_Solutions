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
const ll MAXN = 1e5 + 1;
const ll MAX_XOR = 512;
ll dp[MAXN][MAX_XOR];
void solve(ll tcase)
{
    ll n;
    cin >> n;
    ll a[n + 1];
    rep(i, 1, n + 1) cin >> a[i];
    rep(i, 0, n + 1) rep(j, 0, MAX_XOR) dp[i][j] = 1e18;
    a[0] = 0;
    rep(i, 0, n + 1) dp[i][0] = 0;
    rep(i, 1, n + 1)
    {
        rep(j, 0, MAX_XOR)
        {
            dp[i][j] = dp[i - 1][j];
            if (dp[i - 1][j ^ a[i]] < a[i])
                dp[i][j] = min(dp[i][j], a[i]);
        }
    }
    set<ll> res;
    rep(i, 0, MAX_XOR) if (dp[n][i] != 1e18) res.insert(i);
    cout << res.size() << "\n";
    for (auto i : res)
        cout << i << ' ';
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
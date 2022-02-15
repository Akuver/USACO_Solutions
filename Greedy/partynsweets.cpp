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
    ll n, m, ans = 0;
    cin >> n >> m;
    ll b[n], g[m];
    rep(i, 0, n) cin >> b[i];
    rep(i, 0, m) cin >> g[i];
    sorta(b, n);
    sorta(g, m);
    if (b[n - 1] > g[0])
    {
        cout << -1 << "\n";
        return;
    }
    if (b[n - 1] == g[0])
    {
        rep(i, 0, m) ans += g[i];
        rep(i, 0, n - 1) ans += m * b[i];
    }
    else
    {
        rep(i, 0, m) ans += g[i];
        rep(i, 0, n - 2) ans += m * b[i];
        ans += (m - 1) * b[n - 2];
        ans += b[n - 1];
    }
    cout << ans;
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
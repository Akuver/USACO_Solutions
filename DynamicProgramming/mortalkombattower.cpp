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
    ll n, INF = 1e18;
    cin >> n;
    ll cnt[n][2], a[n];
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) rep(j, 0, 2) cnt[i][j] = INF;
    cnt[0][1] = a[0];
    cnt[1][1] = a[0] + a[1];
    cnt[1][0] = cnt[0][1];
    rep(i, 2, n)
    {
        cnt[i][0] = min(cnt[i - 2][1], cnt[i - 1][1]);
        cnt[i][1] = min(cnt[i - 2][0] + a[i - 1] + a[i], cnt[i - 1][0] + a[i]);
    }
    cout << min(cnt[n - 1][0], cnt[n - 1][1]) << "\n";
}
int main()
{
    speed;
    ll t = 1;
    cin >> t;
    rep(i, 1, t + 1)
        solve(i);
}
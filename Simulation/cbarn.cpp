#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define cd complex<double>
#define MOD 1000000007
#define MODA 998244353
#define pb push_back
#define mp make_pair
#define sortv(v) sort(v.begin(), v.end())
#define sorta(A, N) sort(A, A + N)
#define debug(x) cerr << #x << "is" << x;
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
    ll n, ans = 1e18;
    cin >> n;
    ll r[n];
    rep(i, 0, n) cin >> r[i];
    rep(i, 0, n)
    {
        ll dist = 0;
        rep(j, 0, n)
        {
            dist += r[j] * ((j - i + n) % n);
        }
        ans = min(ans, dist);
    }
    cout << ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
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
    ll n, x, cnt = 0;
    cin >> n >> x;
    ll a[n];
    rep(i, 0, n) cin >> a[i];
    sorta(a, n);
    ll l = 0, r = n - 1;
    vector<ll> done(n, 0);
    while (l < r)
    {
        if (a[l] + a[r] <= x)
        {
            done[l] = done[r] = 1;
            l++, r--, cnt++;
        }
        else if (a[l] + a[r] > x)
        {
            done[r] = 1;
            r--, cnt++;
        }
    }
    rep(i, 0, n) if (!done[i]) cnt++;
    cout << cnt;
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
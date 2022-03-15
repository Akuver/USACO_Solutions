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
map<ll, ll> dp;
void solve(ll tcase)
{
    ll n;
    cin >> n;
    ll a[n];
    ll maxi = 0, lst = -1;
    rep(i, 0, n)
    {
        cin >> a[i];
        dp[a[i]] = 0;
    }
    rep(i, 0, n)
    {
        ll x = a[i];
        dp[x] = max(dp[x], dp[x - 1] + 1);
        if (maxi < dp[x])
            maxi = dp[x], lst = x;
    }
    set<ll> res;
    for (ll i = n - 1; i >= 0; i--)
        if (a[i] == lst)
            lst--, res.insert(i + 1);
    cout << maxi << "\n";
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
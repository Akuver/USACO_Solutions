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
    ll n, mini = 1e18;
    cin >> n;
    ll a[n];
    rep(i, 0, n) cin >> a[i];
    sorta(a, n);
    if (a[n - 2] - a[0] == n - 2 && a[n - 1] - a[n - 2] > 2)
        mini = 2;
    else if (a[n - 1] - a[1] == n - 2 && a[1] - a[0] > 2)
        mini = 2;
    else
    {
        ll p1 = 0, p2 = 0;
        while (p1 < n)
        {
            while (p2 < n - 1 && a[p2 + 1] - a[p1] <= n - 1)
                p2++;
            ll cowsinside = p2 - p1 + 1;
            mini = min(mini, n - cowsinside);
            p1++;
        }
    }
    cout << mini << "\n"
         << max(a[n - 2] - a[0], a[n - 1] - a[1]) - (n - 2) << "\n";
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
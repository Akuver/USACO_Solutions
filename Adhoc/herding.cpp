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
    ll a[3];
    cin >> a[0] >> a[1] >> a[2];
    sorta(a, 3);
    if (a[0] == a[2] - 2)
        cout << 0 << "\n";
    else if ((a[1] == a[2] - 2) || (a[0] == a[1] - 2))
        cout << 1 << "\n";
    else
        cout << 2 << "\n";

    cout << max(a[1] - a[0] - 1, a[2] - a[1] - 1);
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
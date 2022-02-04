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
    ll n, ans = 0;
    cin >> n;
    pair<ll, ll> c[n];
    rep(i, 0, n) cin >> c[i].s >> c[i].f;
    sorta(c, n);
    ll left = 0, right = n - 1;
    while (left <= right)
    {
        ll x = min(c[left].s, c[right].s);
        c[left].s -= x;
        if (left != right)
            c[right].s -= x;
        ans = max(ans, c[left].f + c[right].f);
        if (!c[left].s)
            left++;
        if (!c[right].s)
            right--;
    }
    cout << ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
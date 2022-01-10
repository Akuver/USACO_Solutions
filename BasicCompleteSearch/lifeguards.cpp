#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MODA 998244353
#define pb push_back
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
    ll n, ans = 0;
    cin >> n;
    pair<ll, ll> guard[n];
    rep(i, 0, n) cin >> guard[i].f >> guard[i].s;
    sorta(guard, n);
    rep(i, 0, n)
    {
        ll tim[1001] = {0};
        rep(j, 0, n)
        {
            if (j == i)
                continue;
            rep(k, guard[j].f + 1, guard[j].s + 1) tim[k] = 1;
        }
        ll cnt = 0;
        rep(k, 0, 1001) cnt += tim[k];
        ans = max(ans, cnt);
    }
    cout << ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
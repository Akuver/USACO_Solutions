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
    ll n, m, r, ans = 0;
    cin >> n >> m >> r;
    ll c[n], rent[r];
    pair<ll, ll> milk[m];
    rep(i, 0, n) cin >> c[i];
    rep(i, 0, m) cin >> milk[i].s >> milk[i].f;
    rep(i, 0, r) cin >> rent[i];
    sorta(c, n);
    sorta(milk, m);
    sorta(rent, r);
    reverse(rent, rent + r);
    reverse(milk, milk + m);
    rep(i, 1, r) rent[i] += rent[i - 1];
    rep(i, 1, n) c[i] += c[i - 1];

    rep(i, 0, m)
    {
        milk[i].f = milk[i].f * milk[i].s + ((i - 1 >= 0) ? milk[i - 1].f : 0LL);
        milk[i].s += ((i - 1 >= 0) ? milk[i - 1].s : 0LL);
    }
    rep(x, 0, min(n, r) + 1)
    {
        ll rentmoney = (x - 1 >= 0) ? rent[x - 1] : 0LL;
        ll milkproduced = c[n - 1] - ((x - 1 >= 0) ? c[x - 1] : 0LL);
        ll milkmoney = 0;
        ll lo = 0, hi = m;
        while (lo < hi)
        {
            ll mid = (lo + hi) / 2;
            if (milk[mid].s <= milkproduced)
                lo = mid + 1;
            else
                hi = mid;
        }
        milkmoney += (lo - 1 >= 0) ? milk[lo - 1].f : 0LL;
        milkproduced -= (lo - 1 >= 0) ? milk[lo - 1].s : 0LL;
        if (lo < m)
            milkmoney += ((milk[lo].f - (lo - 1 >= 0 ? milk[lo - 1].f : 0LL)) / (milk[lo].s - (lo - 1 >= 0 ? milk[lo - 1].s : 0LL))) * milkproduced;
        ans = max(ans, milkmoney + rentmoney);
    }
    cout << ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
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
    ll N;
    cin >> N;
    pair<ll, ll> p[N];
    rep(i, 0, N) cin >> p[i].f >> p[i].s;
    sorta(p, N);
    rep(i, 0, N) p[i].s += p[i].f;
    ll ans = p[0].s;
    rep(i, 1, N)
    {
        if (ans > p[i].f)
        {
            ll diff = ans - p[i].f;
            p[i].f += diff, p[i].s += diff;
        }
        ans = p[i].s;
    }
    cout << ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
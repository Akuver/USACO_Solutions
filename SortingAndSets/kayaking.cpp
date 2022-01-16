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

    ll N, ans = 1e18;
    cin >> N;
    ll a[2 * N];
    rep(i, 0, 2 * N) cin >> a[i];
    sorta(a, 2 * N);
    rep(i, 0, 2 * N)
    {
        rep(j, i + 1, 2 * N)
        {
            ll res = 0;
            vector<ll> rem;
            rep(k, 0, 2 * N) if (k != i && k != j) rem.pb(a[k]);
            for (ll z = rem.size() - 1; z >= 1; z -= 2)
                res += rem[z] - rem[z - 1];
            ans = min(ans, res);
        }
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
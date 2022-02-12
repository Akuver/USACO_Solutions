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
    ll n;
    cin >> n;
    vector<ll> a(2 * n);
    rep(i, 0, 2 * n) cin >> a[i];
    sortv(a);
    ll cnt = 2 * n - 1;
    rep(i, 0, cnt)
    {
        vector<pair<ll, ll> > res;
        vector<ll> b = a;
        ll x = a[2 * n - 1] + a[i];
        while (!b.empty())
        {
            ll a1 = b[b.size() - 1];
            b.erase((--b.end()));
            auto it = lower_bound(b.begin(), b.end(), x - a1);
            if (it == b.end())
                it--;
            if (*it != x - a1)
                break;
            b.erase(it);
            res.pb({x - a1, a1});
            x = max(x - a1, a1);
        }
        if (res.size() != n)
            continue;
        cout << "YES\n";
        cout << res[0].f + res[0].s << "\n";
        for (auto i : res)
            cout << i.f << ' ' << i.s << "\n";
        return;
    }

    cout << "NO\n";
}
int main()
{
    speed;
    ll t = 1;
    cin >> t;
    rep(i, 1, t + 1)
        solve(i);
}
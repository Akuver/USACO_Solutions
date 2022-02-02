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
    vector<pair<pair<ll, ll>, ll> > p;
    vector<ll> ans(n, -2);
    rep(i, 0, n)
    {
        ll h, w;
        cin >> h >> w;
        p.pb({{w, -h}, i});
        p.pb({{h, -w}, i});
    }
    sortv(p);
    ll minheight = 1e18;
    ll res = -1;
    rep(i, 0, p.size())
    {
        ll h = -p[i].f.s, w = p[i].f.f;
        ll ind = p[i].s;
        if (h > minheight)
            ans[ind] = res;
        if (h < minheight)
            minheight = h, res = ind;
    }
    rep(i, 0, n) cout << ans[i] + 1 << ' ';
    cout << "\n";
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    cin >> t;
    rep(i, 1, t + 1)
        solve(i);
}
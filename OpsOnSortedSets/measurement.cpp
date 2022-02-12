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
    ll n, g, ans = 0;
    cin >> n >> g;
    array<ll, 3> p[n];
    vector<ll> cows;
    rep(i, 0, n)
    {
        cin >> p[i][0] >> p[i][1] >> p[i][2];
        cows.pb(p[i][1]);
    }
    uniq(cows);
    sort(p, p + n);
    map<ll, set<ll> > cnt;
    set<ll> milk;
    ll ncows = cows.size();
    ncows++; // since there are other cows not in the measurement log
    rep(i, 0, ncows) cnt[g].insert(i);
    milk.insert(g);
    ll a[ncows];
    rep(i, 0, cows.size()) a[i] = g;
    set<ll> prevset = cnt[g];
    rep(i, 0, n)
    {
        auto it = lower_bound(cows.begin(), cows.end(), p[i][1]);
        ll id = it - cows.begin();
        ll delta = p[i][2];
        cnt[a[id]].erase(cnt[a[id]].find(id));
        if (!cnt[a[id]].size())
            milk.erase(a[id]);
        a[id] += delta;
        cnt[a[id]].insert(id);
        if (cnt[a[id]].size() == 1)
            milk.insert(a[id]);
        ll maxi = *(--milk.end());
        if (prevset != cnt[maxi])
        {
            ans++;
            prevset = cnt[maxi];
        }
    }
    cout << ans << "\n";
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
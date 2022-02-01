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
vector<ll> vals;
ll compression(ll x)
{
    return lower_bound(vals.begin(), vals.end(), x) - vals.begin();
}
void solve(ll tcase)
{
    ll n;
    cin >> n;
    pair<ll, ll> c[n];
    rep(i, 0, n)
    {
        cin >> c[i].f >> c[i].s;
        vals.pb(c[i].f);
        vals.pb(c[i].s);
    }
    uniq(vals);
    ll maxi = vals.size();
    ll prefix[maxi];
    memset(prefix, 0, sizeof(prefix));
    rep(i, 0, n)
    {
        c[i].f = compression(c[i].f);
        c[i].s = compression(c[i].s);
        prefix[c[i].f]++;
        if (c[i].s + 1 < maxi)
            prefix[c[i].s + 1]--;
    }
    ll ans = prefix[0];
    rep(i, 1, maxi)
    {
        prefix[i] += prefix[i - 1];
        ans = max(ans, prefix[i]);
    }
    cout << ans;
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
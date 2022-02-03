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
const ll MAXN = 100000;
ll n;
ll x[MAXN], y[MAXN];
ll pos[MAXN], neg[MAXN];
ll cid[MAXN];
bool comp(ll a, ll b)
{
    if (neg[a] == neg[b])
        return pos[a] > pos[b];
    return neg[a] < neg[b];
}
void solve(ll tcase)
{
    cin >> n;
    rep(i, 0, n)
    {
        cin >> x[i] >> y[i];
        pos[i] = x[i] + y[i], neg[i] = x[i] - y[i];
        cid[i] = i;
    }
    sort(cid, cid + n, comp);
    ll mxpos = -1;
    ll ans = 0;
    rep(i, 0, n)
    {
        if (pos[cid[i]] > mxpos)
        {
            ans++;
            mxpos = pos[cid[i]];
        }
    }
    cout << ans << '\n';
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
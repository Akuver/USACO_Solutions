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
const ll MAXN = 5000;
ll b[MAXN], d[MAXN], n;
vector<ll> adj[MAXN];
void solve(ll tcase)
{
    cin >> n;
    rep(i, 1, n + 1) cin >> b[i];
    rep(i, 1, n + 1) cin >> d[i];
    rep(i, 1, n)
        adj[d[i]]
            .pb(d[i + 1]);
    rep(i, 3, n + 1) adj[1].pb(b[i]);
    if (n >= 2 && d[2] != b[2])
    {
        cout << -1 << "\n";
        return;
    }
    cout << 2 * n - 3 << "\n";
    rep(i, 1, n + 1)
    {
        for (auto x : adj[i])
            cout << i << ' ' << x << "\n";
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
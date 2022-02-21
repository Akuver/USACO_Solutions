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
const ll N = 205;
vector<ll> adj[N];
ll vis[N];
void dfs(ll node)
{
    vis[node] = 1;
    for (auto child : adj[node])
        if (!vis[child])
            dfs(child);
}
ll dist(ll x1, ll y1, ll x2, ll y2)
{
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}
void solve(ll tcase)
{
    ll n, maxi = 0;
    cin >> n;
    array<ll, 3> cow[n];
    rep(i, 0, n) cin >> cow[i][0] >> cow[i][1] >> cow[i][2];
    rep(i, 0, n)
        rep(j, 0, n)
    {
        if (i == j)
            continue;
        if (dist(cow[i][0], cow[i][1], cow[j][0], cow[j][1]) <= cow[i][2] * cow[i][2])
            adj[i].pb(j);
    }
    rep(i, 0, n)
    {
        dfs(i);
        ll cnt = 0;
        rep(j, 0, n)
        {
            if (vis[j])
                cnt++;
            vis[j] = 0;
        }
        maxi = max(maxi, cnt);
    }
    cout << maxi;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
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
ll X, Y, K, M, mindiff = 1e18;
struct node
{
    ll x, y, m;
    node(ll x1, ll y1, ll m1)
    {
        x = x1, y = y1, m = m1;
    }
};
map<pair<ll, ll>, ll> vis;
void bfs(node x)
{
    queue<node> q;
    q.push(x);
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        vis[{p.x, p.y}] = 1;
        mindiff = min(mindiff, abs(p.x + p.y - M));
        ll x = p.x, y = p.y;
        if (!p.m)
            continue;
        if (!vis[{X, y}])
            q.push(node(X, y, p.m - 1));
        if (!vis[{x, Y}])
            q.push(node(x, Y, p.m - 1));
        if (!vis[{x, 0}])
            q.push(node(x, 0, p.m - 1));
        if (!vis[{0, y}])
            q.push(node(0, y, p.m - 1));
        ll z = min(X - x, y);
        if (!vis[{x + z, y - z}] && z)
            q.push(node(x + z, y - z, p.m - 1));
        z = min(Y - y, x);
        if (!vis[{x - z, y + z}] && z)
            q.push(node(x - z, y + z, p.m - 1));
    }
}
void solve(ll tcase)
{
    cin >> X >> Y >> K >> M;
    bfs(node(0, 0, K));
    cout << mindiff;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
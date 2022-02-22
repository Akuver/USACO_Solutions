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
ll grid[500][500], n, m;
vector<pair<ll, ll> > dest;
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, -1, 0, 1};
bool valid(ll x, ll y)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
        return true;
    return false;
}
bool ok(ll x)
{
    ll vis[n][m];
    memset(vis, 0, sizeof(vis));
    stack<pair<ll, ll> > s;
    if (!dest.size())
        return true;
    s.push(dest[0]);
    while (!s.empty())
    {
        auto node = s.top();
        s.pop();
        vis[node.f][node.s] = 1;
        rep(k, 0, 4)
        {
            ll nx = node.f + dx[k], ny = node.s + dy[k];
            if (!valid(nx, ny))
                continue;
            if (abs(grid[nx][ny] - grid[node.f][node.s]) <= x && !vis[nx][ny])
                s.push({nx, ny});
        }
    }
    for (auto i : dest)
        if (!vis[i.f][i.s])
            return false;
    return true;
}
void solve(ll tcase)
{
    cin >> n >> m;
    rep(i, 0, n) rep(j, 0, m) cin >> grid[i][j];
    rep(i, 0, n) rep(j, 0, m)
    {
        ll x;
        cin >> x;
        if (x)
            dest.pb({i, j});
    }
    ll lo = 0, hi = 1e9 + 1;
    while (lo < hi)
    {
        ll mid = (lo + hi) / 2;
        if (ok(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << hi;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
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
const ll MAXN = 20;
ll n;
string grid[MAXN];
ll vis[MAXN][MAXN];
ll dx[4] = {0, -1, 0, 1};
ll dy[4] = {-1, 0, 1, 0};
bool valid(ll x, ll y, ll N1, ll M1, ll N2, ll M2)
{
    if (x >= N1 && x <= N2 && y >= M1 && y <= M2 && !vis[x][y])
        return true;
    return false;
}
struct PCL
{
    ll x1, y1, x2, y2; // rectangle with bottom left & top right corner
    PCL(ll x1, ll y1, ll x2, ll y2)
    {
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
    }
};
vector<PCL> rect;
bool validPCL(ll x1, ll y1, ll x2, ll y2)
{
    map<char, ll> components;
    rep(i, x1, x2 + 1) rep(j, y1, y2 + 1) vis[i][j] = 0;
    rep(i, x1, x2 + 1) rep(j, y1, y2 + 1)
    {
        if (vis[i][j])
            continue;
        components[grid[i][j]]++;
        queue<pair<ll, ll> > q;
        q.push({i, j});
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            vis[node.f][node.s] = components[grid[i][j]];
            rep(k, 0, 4)
            {
                ll nx = node.f + dx[k], ny = node.s + dy[k];
                if (!valid(nx, ny, x1, y1, x2, y2))
                    continue;
                if (grid[nx][ny] != grid[node.f][node.s])
                    continue;
                q.push({nx, ny});
            }
        }
    }
    if (components.size() != 2)
        return false;
    ll c1 = 0, c2 = 0;
    for (auto i : components)
    {
        if (i.s == 1)
            c1++;
        else
            c2++;
    }
    return c1 && c2;
}
bool subsetPCL(ll i1, ll i2)
{
    // is i1 a subset of i2?
    return (rect[i1].x1 >= rect[i2].x1 && rect[i1].x2 <= rect[i2].x2 && rect[i1].y1 >= rect[i2].y1 && rect[i1].y2 <= rect[i2].y2);
}
bool maximalPCL(ll ind)
{
    rep(i, 0, rect.size()) if (i != ind && subsetPCL(ind, i)) return false;
    return true;
}
void solve(ll tcase)
{
    ll ans = 0;
    cin >> n;
    rep(i, 0, n) cin >> grid[i];
    rep(i1, 0, n) rep(j1, 0, n) rep(i2, i1, n) rep(j2, j1, n) if (validPCL(i1, j1, i2, j2))
        rect.pb(PCL(i1, j1, i2, j2));

    rep(i, 0, rect.size()) if (maximalPCL(i))
        ans++;

    cout << ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
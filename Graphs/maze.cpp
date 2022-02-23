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
const ll MAXN = 50;
string grid[MAXN];
ll maze[MAXN][MAXN];
vector<pair<ll, ll> > p[2]; // 0-good,1-bad
ll n, m;
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, -1, 0, 1};
bool valid(ll x, ll y)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
        return true;
    return false;
}
void solve(ll tcase)
{
    cin >> n >> m;
    rep(i, 0, n) rep(j, 0, m) maze[i][j] = 0;
    p[0].clear();
    p[1].clear();
    rep(i, 0, n) cin >> grid[i];
    rep(i, 0, n) rep(j, 0, m)
    {
        if (grid[i][j] == 'G')
            p[0].pb({i, j});
        else if (grid[i][j] == 'B')
            p[1].pb({i, j});
    }
    for (auto node : p[1])
    {
        ll x = node.f, y = node.s;
        rep(k, 0, 4)
        {
            ll nx = x + dx[k], ny = y + dy[k];
            if (!valid(nx, ny))
                continue;
            if (grid[nx][ny] == '.')
                grid[nx][ny] = '#';
        }
    }
    stack<pair<ll, ll> > s;
    if (grid[n - 1][m - 1] != '#')
        s.push({n - 1, m - 1});
    while (!s.empty())
    {
        auto node = s.top();
        s.pop();
        maze[node.f][node.s] = 1;
        rep(k, 0, 4)
        {
            ll nx = node.f + dx[k], ny = node.s + dy[k];
            if (!valid(nx, ny) || grid[nx][ny] == '#' || maze[nx][ny])
                continue;
            s.push({nx, ny});
        }
    }
    for (auto i : p[1])
        if (maze[i.f][i.s])
        {
            cout << "NO\n";
            return;
        }
    for (auto i : p[0])
        if (!maze[i.f][i.s])
        {
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
}
int main()
{
    speed;
    ll t = 1;
    cin >> t;
    rep(i, 1, t + 1)
        solve(i);
}
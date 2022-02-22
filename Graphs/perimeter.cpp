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
const ll MAXN = 1000;
ll n, maxarea, minperimeter;
string grid[MAXN];
ll vis[MAXN][MAXN];
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, -1, 0, 1};
bool valid(ll x, ll y)
{
    if (x >= 0 && x < n && y >= 0 && y < n && !vis[x][y] && grid[x][y] != '.')
        return true;
    return false;
}
bool valid1(ll x, ll y)
{
    if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == '#')
        return false;
    return true;
}
void solve(ll tcase)
{
    cin >> n;
    rep(i, 0, n) cin >> grid[i];
    rep(i, 0, n)
        rep(j, 0, n)
    {
        if (valid(i, j))
        {
            vector<pair<ll, ll> > component;
            stack<pair<ll, ll> > s;
            s.push({i, j});
            while (!s.empty())
            {
                auto node = s.top();
                component.pb(node);
                s.pop();
                vis[node.f][node.s] = 1;
                rep(k, 0, 4)
                {
                    ll nx = node.f + dx[k], ny = node.s + dy[k];
                    if (!valid(nx, ny))
                        continue;
                    s.push({nx, ny});
                }
            }
            ll curarea = 0, curperimeter = 0;
            uniq(component);
            for (auto i : component)
            {
                ll x = i.f, y = i.s, cnt = 0;
                rep(k, 0, 4)
                {
                    ll nx = x + dx[k], ny = y + dy[k];
                    cnt += valid1(nx, ny);
                }
                curperimeter += cnt;
                curarea++;
            }
            if (curarea > maxarea)
                maxarea = curarea, minperimeter = curperimeter;
            else if (curarea == maxarea)
                minperimeter = min(minperimeter, curperimeter);
        }
    }

    cout << maxarea << ' ' << minperimeter;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
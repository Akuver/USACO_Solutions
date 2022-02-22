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
const ll MAXN = 100;
ll n, k, r, grid[MAXN][MAXN];
map<pair<ll, ll>, vector<pair<ll, ll> > > m;
vector<pair<ll, ll> > cows;
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, -1, 0, 1};
bool valid(ll x, ll y)
{
    if (x >= 0 && x < n && y >= 0 && y < n && !grid[x][y])
        return true;
    return false;
}
void solve(ll tcase)
{
    cin >> n >> k >> r;
    rep(i, 0, r)
    {
        ll x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        m[{x1, y1}].pb({x2, y2});
        m[{x2, y2}].pb({x1, y1});
    }
    rep(i, 0, k)
    {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        cows.pb({x, y});
    }
    ll label = 0;
    rep(i, 0, k)
    {
        ll x = cows[i].f, y = cows[i].s;
        if (grid[x][y])
            continue;
        label++;
        stack<pair<ll, ll> > s;
        s.push({x, y});
        while (!s.empty())
        {
            auto node = s.top();
            s.pop();
            grid[node.f][node.s] = label;
            rep(k, 0, 4)
            {
                ll nx = node.f + dx[k], ny = node.s + dy[k];
                ll flag = 1;
                if (!valid(nx, ny))
                    continue;
                for (auto k : m[node])
                {
                    if (k.f == nx && k.s == ny)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (!flag)
                    continue;
                s.push({nx, ny});
            }
        }
    }
    ll ans = 0;
    vector<ll> cnts(label + 1, 0);
    rep(i, 0, k) cnts[grid[cows[i].f][cows[i].s]]++;
    rep(i, 0, label + 1) rep(j, i + 1, label + 1) ans += cnts[i] * cnts[j];
    cout << ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
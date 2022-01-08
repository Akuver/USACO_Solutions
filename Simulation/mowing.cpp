#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define cd complex<double>
#define MOD 1000000007
#define MODA 998244353
#define pb push_back
#define mp make_pair
#define sortv(v) sort(v.begin(), v.end())
#define sorta(A, N) sort(A, A + N)
#define debug(x) cerr << #x << "is" << x;
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
void solve(ll tcase)
{
    ll n, x = 1e18, time = 0;
    ll grid[2500][2500];
    memset(grid, -1, sizeof(grid));
    cin >> n;
    ll curx = 1250, cury = 1250;
    rep(i, 0, n)
    {
        char c;
        ll t;
        cin >> c >> t;
        if (c == 'N')
        {
            rep(k, 1, t + 1)
            {
                if (grid[curx][cury] != -1)
                {
                    ll diff = time + k - grid[curx][cury];
                    x = min(x, diff);
                }
                grid[curx][cury--] = time + k;
            }
        }
        else if (c == 'S')
        {
            rep(k, 1, t + 1)
            {
                if (grid[curx][cury] != -1)
                {
                    ll diff = time + k - grid[curx][cury];
                    x = min(x, diff);
                }
                grid[curx][cury++] = time + k;
            }
        }
        else if (c == 'W')
        {
            rep(k, 1, t + 1)
            {
                if (grid[curx][cury] != -1)
                {
                    ll diff = time + k - grid[curx][cury];
                    x = min(x, diff);
                }
                grid[curx++][cury] = time + k;
            }
        }
        else if (c == 'E')
        {
            rep(k, 1, t + 1)
            {
                if (grid[curx][cury] != -1)
                {
                    ll diff = time + k - grid[curx][cury];
                    x = min(x, diff);
                }
                grid[curx--][cury] = time + k;
            }
        }
        time += t;
    }
    (x == 1e18) ? cout << -1 : cout << x;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
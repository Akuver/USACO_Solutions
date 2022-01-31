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
const ll MAX = 1005;
ll grid[MAX][MAX];
void solve(ll tcase)
{
    ll n, k;
    cin >> n >> k;
    rep(i, 0, n)
    {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1++, x2++, y1++, y2++;
        grid[x1][y1]++;
        grid[x2][y2]++;
        grid[x2][y1]--;
        grid[x1][y2]--;
    }
    rep(i, 1, MAX) rep(j, 1, MAX) grid[i][j] += grid[i][j - 1] + grid[i - 1][j] - grid[i - 1][j - 1];
    ll cnt = 0;
    rep(i, 0, MAX) rep(j, 0, MAX)
    {
        if (grid[i][j] == k)
            cnt++;
    }
    cout << cnt;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
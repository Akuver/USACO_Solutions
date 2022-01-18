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

void solve(ll tcase)
{
    ll n, ans = 0;
    cin >> n;
    string grid[n];
    rep(i, 0, n) cin >> grid[i];
    while (true)
    {

        ll x = -1, y = -1;
        for (ll i = n - 1; i >= 0; i--)
        {
            for (ll j = n - 1; j >= 0; j--)
            {
                if (grid[i][j] == '1')
                {
                    x = i, y = j;
                    break;
                }
            }
            if (x != -1)
                break;
        }
        rep(i, 0, x + 1) rep(j, 0, y + 1)
        {
            if (grid[i][j] == '0')
                grid[i][j] = '1';
            else
                grid[i][j] = '0';
        }
        if (x == -1)
            break;
        ans++;
    }
    cout << ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
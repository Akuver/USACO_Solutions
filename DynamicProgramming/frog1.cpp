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
    ll n;
    cin >> n;
    vector<ll> cost(n + 1, MOD), h(n + 1);
    cost[1] = 0;
    rep(i, 1, n + 1) cin >> h[i];
    rep(i, 1, n + 1)
    {
        if (i - 1 >= 0)
            cost[i] = min(cost[i], cost[i - 1] + abs(h[i] - h[i - 1]));
        if (i - 2 >= 0)
            cost[i] = min(cost[i], cost[i - 2] + abs(h[i] - h[i - 2]));
    }
    cout << cost[n];
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MODA 998244353
#define pb push_back
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
    ll n, b, ans = n;
    cin >> n >> b;
    pair<ll, ll> points[n];
    rep(i, 0, n) cin >> points[i].f >> points[i].s;
    sorta(points, n);
    rep(i, 0, n)
    {

        rep(j, 0, n)
        {
            vector<ll> q(4, 0);
            ll a = points[i].f + 1, b = points[j].s + 1;
            rep(k, 0, n)
            {
                ll x = points[k].f, y = points[k].s;
                if (x > a && y > b)
                    q[0]++;
                else if (x > a && y < b)
                    q[1]++;
                else if (x < a && y < b)
                    q[2]++;
                else if (x < a && y > b)
                    q[3]++;
            }
            ans = min(ans, *max_element(q.begin(), q.end()));
        }
    }
    cout << ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
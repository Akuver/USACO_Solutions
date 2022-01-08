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
    ll n;
    cin >> n;
    ll p[n + 1], id[n + 1], q[n + 1];
    rep(i, 1, n + 1) cin >> p[i];
    rep(i, 1, n + 1) cin >> id[i];
    rep(k, 0, 3)
    {
        ll temp[n + 1];
        rep(i, 1, n + 1)
        {
            ll came_from = -1;
            rep(j, 1, n + 1) if (p[j] == i)
            {
                came_from = j;
                break;
            }
            temp[came_from] = id[i];
        }
        rep(i, 1, n + 1) id[i] = temp[i];
    }
    rep(i, 1, n + 1) cout << id[i] << "\n";
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
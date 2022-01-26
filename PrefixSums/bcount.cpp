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
    ll N, Q;
    cin >> N >> Q;
    ll a[N];
    ll prefix[N][3];
    rep(i, 0, N) cin >> a[i];
    memset(prefix, 0, sizeof(prefix));
    rep(i, 0, N)
    {
        rep(j, 0, 3)
        {
            prefix[i][j] += (i - 1 >= 0 ? prefix[i - 1][j] : 0LL);
            if (a[i] - 1 == j)
                prefix[i][j]++;
        }
    }
    while (Q--)
    {
        ll l, r;
        cin >> l >> r;
        r--, l--;
        rep(j, 0, 3) cout << prefix[r][j] - (l - 1 >= 0 ? prefix[l - 1][j] : 0LL) << " \n"[j == 2];
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
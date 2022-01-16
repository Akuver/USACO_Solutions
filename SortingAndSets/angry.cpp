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

    ll N, ans = 0;
    cin >> N;
    ll p[N];
    rep(i, 0, N) cin >> p[i];
    sorta(p, N);
    rep(i, 0, N)
    {
        ll t = 1;
        ll j = i;
        ll c = 1;
        while (true)
        {
            ll flag = 0;
            ll k = j - 1;
            while (p[j] - p[k] <= t && k >= 0)
                k--, c++, flag = 1;
            t++;
            j = k + 1;
            if (!flag || !j)
                break;
        }
        j = i;
        t = 1;
        while (true)
        {
            ll flag = 0;
            ll k = j + 1;
            while (p[k] - p[j] <= t && k < N)
                k++, c++, flag = 1;
            t++;
            j = k - 1;
            if (!flag || j == N - 1)
                break;
        }
        ans = max(ans, c);
    }
    cout << ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
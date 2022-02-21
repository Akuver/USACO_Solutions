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
    ll n, k;
    cin >> n >> k;
    ll a[n], maxsum = 0;
    rep(i, 0, n)
    {
        cin >> a[i];
        maxsum += a[i];
    }
    ll lo = 0, hi = maxsum + 1;
    while (lo < hi)
    {
        ll mid = (lo + hi) / 2;
        ll divs = 0, sum = 0;
        rep(i, 0, n)
        {
            if (a[i] > mid)
                divs += k + 1;
            if (sum + a[i] > mid)
            {
                sum = 0;
                divs++;
            }
            sum += a[i];
        }
        if (sum)
            divs++;
        if (divs <= k)
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << hi;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
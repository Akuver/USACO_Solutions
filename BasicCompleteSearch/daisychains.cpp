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
    ll n, ans = 0;
    cin >> n;
    ll a[n];
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            ll sum = 0;
            rep(k, i, j + 1) sum += a[k];
            if (sum % (j - i + 1) == 0)
            {
                ll x = sum / (j - i + 1);
                rep(k, i, j + 1)
                {
                    if (a[k] == x)
                    {
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    cout << ans;
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
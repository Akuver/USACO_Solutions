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
    ll A[n], B[n];
    string s[n];
    rep(i, 0, n) cin >> s[i] >> A[i] >> B[i];
    ll a = -1e18, b = 1e18;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (s[i] == "none")
        {
            a = max(a, A[i]);
            b = min(b, B[i]);
        }
        if (s[i] == "on")
        {
            a -= B[i], b -= A[i];
            a = max(0LL, a);
        }
        if (s[i] == "off")
        {
            a += A[i], b += B[i];
            a = max(0LL, a);
        }
    }
    cout << a << ' ' << b << "\n";
    a = -1e18, b = 1e18;
    rep(i, 0, n)
    {
        if (s[i] == "none")
        {
            a = max(a, A[i]);
            b = min(b, B[i]);
        }
        if (s[i] == "on")
        {
            a += A[i], b += B[i];
        }
        if (s[i] == "off")
        {
            a -= B[i], b -= A[i];
            a = max(0LL, a);
        }
    }
    cout << a << ' ' << b << "\n";
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
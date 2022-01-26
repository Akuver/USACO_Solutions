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
    map<ll, ll> freq;
    ll a[n];
    freq[0] = 1;
    rep(i, 0, n)
    {
        cin >> a[i];
        a[i] += (i - 1 >= 0 ? a[i - 1] : 0LL);
        a[i] %= n;
        if (a[i] < 0)
            a[i] += n;
    }
    rep(i, 0, n)
    {
        ans += freq[a[i] % n];
        freq[a[i] % n]++;
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
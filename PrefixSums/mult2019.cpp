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
    ll ans = 0;
    string s;
    cin >> s;
    ll n = s.size(), x = 2019;
    ll powmod[n], prefix[n];
    ll res = 1, ind = 0;
    while (ind < n)
    {
        res %= x;
        if (res < 0)
            res += x;
        powmod[ind++] = res;
        res *= 10;
    }
    memset(prefix, 0, sizeof(prefix));
    map<ll, ll> freq;
    freq[0] = 1;
    for (ll i = n - 1; i >= 0; i--)
    {
        ll num = (i + 1 < n ? prefix[i + 1] : 0LL) + (s[i] - '0') * powmod[n - 1 - i];
        num %= x;
        if (num < 0)
            num += x;
        prefix[i] = num;
    }
    for (ll i = n - 1; i >= 0; i--)
    {
        ll x = freq[prefix[i]];
        ans += x;
        freq[prefix[i]]++;
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
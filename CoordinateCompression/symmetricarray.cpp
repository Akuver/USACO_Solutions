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
    ll n, flag = 1;
    cin >> n;
    vector<ll> d(2 * n);
    map<ll, ll> freq;
    rep(i, 0, 2 * n)
    {
        cin >> d[i];
        if (d[i] & 1)
            flag = 0;
        freq[d[i]]++;
    }
    for (auto i : freq)
        if (i.s % 2)
            flag = 0;
    uniq(d);
    if (d.size() != n)
    {
        flag = 0;
        cout << "NO\n";
        return;
    }
    vector<ll> diff;
    rep(i, 0, d.size())
    {
        ll x = (i + 1 < d.size()) ? d[i + 1] : 0LL;
        ll num = x - d[i], den = 2 * (i + 1);
        ll q = num / den;
        diff.pb(q);
        if (num % den)
        {
            flag = 0;
            cout << "NO\n";
            return;
        }
    }
    vector<ll> a(n);
    for (ll i = n - 1; i >= 0; i--)
    {
        ll x = (i + 1 < n) ? a[i + 1] : 0LL;
        a[i] = x - diff[i];
        if (a[i] <= 0)
        {
            flag = 0;
            cout << "NO\n";
            return;
        }
    }
    uniq(a);
    if (a.size() != n)
        flag = 0;
    (!flag)
        ? cout << "NO\n"
        : cout << "YES\n";
}
int main()
{
    speed;
    ll t = 1;
    cin >> t;
    rep(i, 1, t + 1)
        solve(i);
}
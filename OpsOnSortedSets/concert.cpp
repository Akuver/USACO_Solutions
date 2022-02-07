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
    ll n, m;
    cin >> n >> m;
    multiset<ll> s;
    rep(i, 0, n)
    {
        ll x;
        cin >> x;
        s.insert(x);
    }
    while (m--)
    {
        ll x;
        cin >> x;
        if (s.empty())
        {
            cout << -1 << "\n";
            continue;
        }
        auto it = s.lower_bound(x);
        if (it == s.end())
            it--;
        if (*it > x)
        {
            if (it == s.begin())
            {
                cout << -1 << "\n";
                continue;
            }
            it--;
        }
        cout << *it << "\n";
        s.erase(it);
    }
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
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
    ll x, n;
    cin >> x >> n;
    multiset<ll> len;
    set<ll> locs;
    len.insert(x);
    locs.insert(0);
    locs.insert(x);
    while (n--)
    {
        ll p;
        cin >> p;
        auto it1 = locs.lower_bound(p);
        if (*it1 > p)
            it1--;
        auto it2 = locs.upper_bound(p);
        len.erase(len.find(*it2 - *it1));
        len.insert(p - *it1);
        len.insert(*it2 - p);
        locs.insert(p);
        cout << *(--len.end()) << ' ';
    }
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
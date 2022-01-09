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
    string s, t, r;
    cin >> s >> t;
    rep(i, 0, s.size())
    {
        r += s[i];
        if (r.size() >= t.size() && r.substr(r.size() - t.size()) == t)
            r.resize(r.size() - t.size());
    }
    cout << r;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
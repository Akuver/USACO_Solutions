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
map<string, ll> subs;
void solve(ll tcase)
{
    ll n, ans = n + 1;
    cin >> n;
    string s;
    cin >> s;
    rep(i, 0, n)
    {
        rep(j, i, n)
        {
            string sub = s.substr(i, j - i + 1);
            subs[sub]++;
        }
    }
    vector<ll> cnt(n + 1, 0);
    for (auto i : subs)
        if (i.s == 1)
            cnt[(ll)i.f.size()]++;
    rep(i, 1, n + 1) if (cnt[i] == n - i + 1)
    {
        cout << i;
        return;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
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
bool comp(string &a, string &b)
{
    rep(i, 0, a.size() + b.size())
    {
        char s1, s2;
        if (i < a.size())
            s1 = a[i];
        else
            s1 = b[i - a.size()];
        if (i < b.size())
            s2 = b[i];
        else
            s2 = a[i - b.size()];
        if (s1 < s2)
            return true;
        if (s1 > s2)
            return false;
    }
    return false;
}
void solve(ll tcase)
{
    ll n;
    cin >> n;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];
    sort(s.begin(), s.end(), comp);
    rep(i, 0, n) cout << s[i];
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
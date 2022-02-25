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
vector<ll> component(10);
void out(const vector<ll> &x)
{
    cout << "next ";
    for (auto i : x)
        cout << i << ' ';
    cout << endl;
    return;
}
void read()
{
    ll k;
    cin >> k;
    rep(i, 0, k)
    {
        string s;
        cin >> s;
        for (auto j : s)
            component[j - '0'] = i;
    }
    return;
}
void solve(ll tcase)
{
    // 0-hare, 1-tortoise
    while (true)
    {
        out({0, 1});
        read();
        out({0});
        read();
        if (component[0] == component[1])
            break;
    }
    // {0,1}-hare, {2,3,..9}-tortoise
    while (true)
    {
        out({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
        read();
        if (component[0] == component[2])
            break;
    }
    cout << "done" << endl;
}
int main()
{
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
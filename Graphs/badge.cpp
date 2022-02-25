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
const ll N = 1000;
vector<ll> ans(N, -2);
ll n, p[N], in_cycle;
void foo(ll node)
{
    if (ans[node] != -2)
    {
        if (ans[node] == -1)
        {
            ans[node] = node;
            in_cycle = 1;
        }
        return;
    }
    ans[node] = -1;
    foo(p[node]);
    if (ans[node] != -1)
    {
        in_cycle = 0;
        return;
    }
    ans[node] = in_cycle ? node : ans[p[node]];
    return;
}
void solve(ll tcase)
{
    cin >> n;
    rep(i, 0, n)
    {
        cin >> p[i];
        p[i]--;
    }
    rep(i, 0, n) foo(i);
    rep(i, 0, n) cout << ans[i] + 1 << ' ';
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
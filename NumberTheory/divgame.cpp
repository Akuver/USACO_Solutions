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
    ll N, ans = 0;
    cin >> N;
    map<ll, ll> factor;
    for (ll i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
            while (N % i == 0)
            {
                N /= i;
                factor[i]++;
            }
    }
    if (N != 1)
        factor[N]++;
    for (auto i : factor)
    {
        ll num = i.s, cnt = 0;
        while (true)
        {
            if ((cnt + 1) * cnt <= 2 * num)
                cnt++;
            else
                break;
        }
        ans += cnt - 1;
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
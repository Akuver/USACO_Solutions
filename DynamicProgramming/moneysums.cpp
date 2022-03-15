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
const ll MAXSUM = 1e5 + 1;
const ll MAXN = 101;
ll done[MAXN][MAXSUM], x[MAXN], n;
void solve(ll tcase)
{
    cin >> n;
    rep(i, 0, n) cin >> x[i];
    set<ll> s;
    rep(i, 0, n) done[i][0] = 1;
    rep(i, 0, n)
    {
        rep(j, 0, MAXSUM)
        {

            done[i][j] += (i - 1 >= 0) ? done[i - 1][j] : 0LL;
            if (j - x[i] > 0)
                done[i][j] += (i - 1 >= 0 ? done[i - 1][j - x[i]] : 0LL);
            if (j == x[i])
                done[i][j] += (i - 1 >= 0 ? done[i - 1][j - x[i]] : 0LL) + 1;

            if (done[i][j] && j)
                s.insert(j);
        }
    }
    cout << s.size() << "\n";
    for (auto i : s)
        cout << i << ' ';
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
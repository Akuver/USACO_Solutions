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
    ll S, N;
    cin >> S >> N;
    map<ll, vector<pair<ll, ll> > > uniq_weight;
    rep(i, 0, N)
    {
        ll V, W, K;
        cin >> V >> W >> K;
        uniq_weight[W].pb({V, K});
    }
    ll maxn = uniq_weight.size() + 1, maxs = S + 1;
    ll dp[maxn][maxs];
    ll ind = 1;
    rep(i, 0, maxn) rep(j, 0, maxs) dp[i][j] = -1;
    dp[0][0] = 0;
    for (auto &[w, vec] : uniq_weight)
    {
        sort(vec.begin(), vec.end(), greater<pair<ll, ll> >());
        rep(i, 0, maxs)
        {
            dp[ind][i] = dp[ind - 1][i];
            ll used = 0, j = 0, cur_used = 0, gain = 0;
            while ((used + 1) * w <= i && j < vec.size())
            {
                used++;
                gain += vec[j].f;
                if (dp[ind - 1][i - used * w] != -1)
                    dp[ind][i] = max(dp[ind][i], dp[ind - 1][i - used * w] + gain);
                cur_used++;
                if (cur_used == vec[j].s)
                    cur_used = 0, j++;
            }
        }
        ind++;
    }
    ll maxi = 0;
    rep(i, 0, maxn) rep(j, 0, maxs) maxi = max(maxi, dp[i][j]);
    cout << maxi;
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
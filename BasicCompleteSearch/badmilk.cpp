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
    ll N, M, D, S, ans = 0;
    cin >> N >> M >> D >> S;
    vector<array<ll, 3>> A(D);
    vector<array<ll, 2>> B(S);
    rep(i, 0, D) cin >> A[i][0] >> A[i][1] >> A[i][2];
    rep(i, 0, S) cin >> B[i][0] >> B[i][1];
    rep(i, 1, M + 1)
    {
        ll flag = 1;
        rep(j, 0, S)
        {
            ll pj = B[j][0], tj = B[j][1], res = 0;
            rep(k, 0, D)
            {
                if (A[k][0] != pj || A[k][2] >= tj)
                    continue;
                if (A[k][1] == i)
                {
                    res = 1;
                    break;
                }
            }
            flag &= res;
            if (!flag)
                break;
        }
        if (flag)
        {
            set<ll> persons;
            rep(j, 0, D) if (A[j][1] == i) persons.insert(A[j][0]);
            ll res = persons.size();
            ans = max(ans, res);
        }
    }
    cout << ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
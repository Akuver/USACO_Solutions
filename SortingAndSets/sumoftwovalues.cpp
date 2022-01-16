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

    ll N, X;
    cin >> N >> X;
    vector<pair<ll, ll>> A(N);
    rep(i, 0, N)
    {
        cin >> A[i].f;
        A[i].s = i + 1;
    }
    sortv(A);
    ll left = 0, right = N - 1;
    while (left < right)
    {
        if (A[left].f + A[right].f == X)
        {
            cout << A[left].s << ' ' << A[right].s;
            return;
        }
        else if (A[left].f + A[right].f < X)
            left++;
        else
            right--;
    }
    cout << "IMPOSSIBLE";
    return;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
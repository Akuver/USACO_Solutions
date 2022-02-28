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
const ll N = 2e5;
ll n;
vector<ll> t(N), pathLen(N, 0), vis(N, 0);
queue<ll> path;
ll steps = 0;
void dfs(ll node)
{
    path.push(node);
    if (vis[node])
    {
        steps += pathLen[node];
        return;
    }
    vis[node] = 1;
    steps++;
    dfs(t[node]);
}

void solve(ll tcase)
{
    cin >> n;
    rep(i, 0, n)
    {
        cin >> t[i];
        t[i]--;
    }
    rep(i, 0, n)
    {
        if (!vis[i])
        {
            steps = 0;
            dfs(i);
            ll decrement = 1;
            while (!path.empty())
            {
                if (path.front() == path.back())
                    decrement = 0;
                pathLen[path.front()] = steps;
                steps -= decrement;
                path.pop();
            }
        }
    }
    rep(i, 0, n) cout << pathLen[i] << ' ';
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
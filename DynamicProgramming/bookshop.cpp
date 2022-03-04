#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define sortv(v) sort(v.begin(), v.end())
#define sorta(A, N) sort(A, A + N)
#define rep(i, a, N) for (ll i = a; i < N; i++)
#define test(T) \
    ll T;       \
    cin >> T;   \
    while (T--)
#define speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

void solve()
{
    ll N, X;
    cin >> N >> X;
    vector<int> price(N), pages(N);
    for (int &v : price)
        cin >> v;
    for (int &v : pages)
        cin >> v;
    vector<vector<int> > dp(N + 1, vector<int>(X + 1, 0));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= X; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - 1 >= 0)
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            int left = j - price[i - 1];
            if (left >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][left] + pages[i - 1]);
            }
        }
    }
    cout << dp[N][X];
}
int main()
{
    speed;
    solve();
}
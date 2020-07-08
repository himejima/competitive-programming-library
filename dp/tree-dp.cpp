
// 木DP
// - 行きがけ (潜る時)
// - 戻りがけ
// で行う処理を考える
//
// verified
// [P - Independent Set](https://atcoder.jp/contests/dp/tasks/dp_p)
//
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;
const ll mod = 1e9 + 7;

ll N;
vector<ll> g[100100];

ll dp[100100][2];

// 木DP?
// color: 0: w
// color: 1: b
void dfs(int cur, int par = -1) {
    // 遷移
    dp[cur][0] = dp[cur][1] = 1;

    // 潜っていく
    for (int i = 0; i < g[cur].size(); i++) {
        int to = g[cur][i];
        if (to == par) continue;

        dfs(to, cur);
        dp[cur][0] *= (dp[to][0] + dp[to][1]);
        dp[cur][0] %= mod;

        dp[cur][1] *= dp[to][0];
        dp[cur][1] %= mod;
    }
}

int main() {
    cin >> N;

    rep(i, N - 1) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0);

    ll ans = dp[0][0] + dp[0][1];
    ans %= mod;
    cout << ans << endl;
}

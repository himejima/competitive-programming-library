//
// 桁DP
//
// verified
// [E - Almost Everywhere Zero](https://atcoder.jp/contests/abc154/tasks/abc154_e)
//
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

// i: 何桁目
// j: N 未満か
// k: 0でない数字が表れた回数
ll dp[110][2][100];

string S;
ll K;
int main() {
    cin >> S >> K;
    int N = S.size();

    dp[0][0][0] = 1;

    for (int i = 0; i < N; i++) {
        int D = S[i] - '0';
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k <= K; k++) {
                int target = 9;
                if (j == 0) target = D;
                for (int d = 0; d <= target; d++) {
                    int cnt = 0;
                    if (d != 0) cnt++;
                    dp[i + 1][j || (d < D)][k + cnt] += dp[i][j][k];
                }
            }
        }
    }

    ll ans = 0;
    ans += dp[N][0][K];
    ans += dp[N][1][K];
    cout << ans << endl;
}
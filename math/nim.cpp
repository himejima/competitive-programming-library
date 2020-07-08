//
// Nim
//
// XOR を利用して勝ち負けを判定することができます
// xor が not 0 -> 先攻の勝ち
// xor が 0 -> 後攻の勝ち
// verified
// [No.524 コインゲーム - yukicoder](https://yukicoder.me/problems/no/524)
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N;

int main() {
    cin >> N;
    N++;

    // xor の問題となった
    ll ans = 0;

    for (int i = 0; i < 50; i++) {
        // 周期を求める
        ll interval = 1LL << (i + 1);
        ll tmp = N / interval;
        ll cnt = tmp * (interval / 2);

        // はみ出た分
        if (N % interval != 0) {
            cnt += max(0LL, N % interval - interval / 2);
        }

        // 奇数なら足しこむ
        if (cnt % 2 == 1) {
            ans += 1LL << i;
        }
        // cout << "i: " << i << " ans: " << ans << " cnt: " << cnt << endl;
    }

    if (ans == 0) {
        cout << "X" << endl;
    } else {
        cout << "O" << endl;
    }
}

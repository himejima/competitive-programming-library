//
// XOR を使う問題
// - 桁ごとにみる
// - xor は、足し算、引き算は結果が変わらない
// 
// verified
// [D - XOR World](https://atcoder.jp/contests/abc121/tasks/abc121_d)
// 
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll f(ll A) {
    A++;

    ll res = 0;

    // 50 桁
    for (ll i = 0; i < 41; i++) {
        // 周期
        // 2, 4, 8... 前半0 後半1
        ll loop_cnt = 1LL << (i + 1);
        // cout << "loop_cnt: " << loop_cnt << endl;

        ll one = 0;
        // 何セットあるか
        ll cnt = (A / loop_cnt);
        one += (cnt * loop_cnt) / 2;
        // cout << "one_init: " << one << endl;

        // はみ出た分
        if (A % loop_cnt != 0) {
            one += max(0LL, A % loop_cnt - loop_cnt / 2);
        }
        // cout << "one_second: " << one << endl;

        // 奇数ならフラグがたつ
        if (one % 2 == 1) {
            res += (1LL << i);
        }
        // cout << "i: " << i << " one: " << one << " res: " << res << endl;
        // cout << endl;
    }

    // cout << "result: " << res << endl; 
    return res;
}

ll A, B;
int main() {
    // f(5);
    // return 0;
    cin >> A >> B;
    ll ans = f(B) ^ f(A - 1);
    cout << ans << endl;
}
//
// 二次元累積和 
//
// verified
// [D - AtCoder Express 2](https://atcoder.jp/contests/abc106/tasks/abc106_d)
//
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N, M, Q;
ll c[510][510];
ll sum[510][510];
int main() {
    cin >> N >> M >> Q;
    rep(i, M) {
        ll l, r;
        cin >> l >> r;
        // l--; r--;
        sum[l][r]++;
    }

    rep(i, N)rep(j, N) {
        sum[i + 1][j + 1] += sum[i][j + 1] + sum[i + 1][j] - sum[i][j];  
        // cout << sum[i][j + 1] << " " << sum[i + 1][j] << " " << sum[i][j] << " " << c[i][j] << endl;
    }
    // rep(i, N + 1) {
    //     rep(j, N + 1) {
    //         cout << sum[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    rep(i, Q) {
        ll p, q;
        cin >> p >> q;

        cout << sum[q][q] - sum[q][p - 1] - sum[p - 1][q] + sum[p - 1][p - 1] << endl;
    }
}

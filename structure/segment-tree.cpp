// TODO: 全然わかってないので、学び直します。。。
//
// セグメントツリー
//
// verified
// 1点に対する更新、区間に対する選択
// [DSL_2_A < Problems | Aizu Online Judge](https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A)
//
// 参考: 蟻本p155
//
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;

typedef long long ll;
const ll INF = 1LL << 60;
const int MAX_N = 1 << 18;
typedef pair<ll, ll> P;

ll n, q;

// vector<ll> dat;
int dat[MAX_N * 2 - 1];

// 初期化
void init(int n_) {
    n = 1;
    while (n < n_) n *= 2;
    for (int i = 0; i < 2 * n - 1; i++) dat[i] = INT_MAX;
}

// k番目の値(0-indexed)をaに変更
void update(int k, int a) {
    k += n - 1;
    dat[k] = a;
    while (k > 0) {
        k = (k - 1) / 2;
        dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
}

// [a, b) の最小値を求める
// 後ろの方の引数は、計算の簡単のための引数
// kは節点の番号、l、rはその節点が[l, r)に対応づいていることを表す。
// 外からはquery(a,  b, 0, 0, n) として呼ぶ
int query(int a, int b, int k, int l, int r) {
    // [a, b) と [l, r)が交差しなければ INT_MAX
    if (r <= a || b <= l) return INT_MAX;

    // [a, b) が [l, r)を完全に含んでいれば、この節点の値
    if (a <= l && r <= b) return dat[k];
    else {
      // そうでなければ、2つの子の最小値
        int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
}

int main() {
    cin >> n >> q;
    init(n);

    rep(i, q) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            // update
            update(x, y);
        } else {
            // find
            cout << query(x, y + 1, 0, 0, n) << endl;
        }
    }
}

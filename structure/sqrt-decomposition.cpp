// TODO: 全然わかってないので、学び直します。。。
//
// 平方分割
//
// verified
// 1点に対する更新、区間に対する選択
// [DSL_2_B < Problems | Aizu Online Judge](https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B)
//
// 参考
// [セグメント木をあきらめた人のための平方分割 - くじらにっき++](https://kujira16.hateblo.jp/entry/2016/12/15/000000#Range-Update-Query)
//
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

const int sqrtN = 512;
struct SqrtDecomposition {
    int N, K;
    vector<int> data;
    vector<int> bucketSum;

    SqrtDecomposition(int n) : N(n) {
        // バケット数 (切り上げ)
        K = (N + sqrtN - 1) / sqrtN;

        data.assign(K * sqrtN, 0);
        bucketSum.assign(K, 0);
    }

    void add(int x, int y) {
        // 何個めのbucketか
        int k = x / sqrtN;
        data[x] += y;

        int sum = 0;
        // 全バケットに対し加算 (計算し直し)
        for (int i = k * sqrtN; i < (k + 1) * sqrtN; i++) {
            sum += data[i];
        }

        bucketSum[k] = sum;
    }

    // [x, y]
    int getSum(int x, int y) {
        int sum = 0;

        // バケット数だけ走査
        for (int k = 0; k < K; k++) {
            int l = k * sqrtN, r = (k + 1) * sqrtN - 1;
            if (r < x || y < l) {
                continue;
            }
            if (x <= l && r <= y) {
                sum += bucketSum[k];
            } else {
                // はみ出た分
                for (int i = max(x, l); i <= min(y, r); i++) {
                    sum += data[i];
                }
            }
        }

        return sum;
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    SqrtDecomposition sd = SqrtDecomposition(n);

    rep(i, q) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            // add
            sd.add(x, y);
        } else {
            // query
            // cout << sd.getSum(x, y + 1) << endl;
            cout << sd.getSum(x, y) << endl;
        }
    }
}

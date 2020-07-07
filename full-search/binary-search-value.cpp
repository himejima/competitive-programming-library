//
// 二分探索 
// 最大値の最小化
// 
// verified
// [E - Gluttony](https://atcoder.jp/contests/abc144/tasks/abc144_e)
//
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
 
const ll INF = 1LL << 60;
 
ll N, K;
vector<ll> A, F;
 
int main() {
    cin >> N >> K;
    A.resize(N);
    F.resize(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> F[i];
 
    sort(A.begin(), A.end());
    sort(F.rbegin(), F.rend());
 
    ll left = -1, right = INF;
    while (right - left > 1) {
        ll middle = (left + right) / 2;
 
        bool ok = [&] {
            // K 回の修行で条件を満たせるか
            ll cnt = 0;
            for (int i = 0; i < N; i++) {
                cnt += max(0LL, A[i] - middle / F[i]);
            }
            // cout << cnt << endl;
 
            return cnt <= K;
        }();
 
        if (ok) {
            right = middle;
        } else {
            left = middle;
        }
    }
 
    cout << right << endl;
}
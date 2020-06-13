//
// 二分探索 
//
// verified
// [C - Snuke Festival](https://atcoder.jp/contests/abc077/tasks/arc084_a)
//
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
    vector<ll> A(N), B(N), C(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    rep(i, N) cin >> C[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    ll ans = 0;
    rep(i, N) {
        ll b = B[i];
        ll a_idx = upper_bound(A.begin(), A.end(), b - 1) - A.begin();
        ll c_idx = lower_bound(C.begin(), C.end(), b + 1) - C.begin();

        // cout << a_idx << " " << (N - c_idx) << endl;
        ll tmp = a_idx * (N - c_idx);
        ans += tmp;
        // cout << c << " " << b << endl;
    }
    cout << ans << endl;
}
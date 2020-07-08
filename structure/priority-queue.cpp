// Priority Queue
//
// verified
// [D - Summer Vacation](https://atcoder.jp/contests/abc137/tasks/abc137_d)
//
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll INF = 1LL << 60;

ll N, M;

int main() {
    cin >> N >> M;

    vector<ll> v[M];
    rep(i, N) {
        ll A, B;
        cin >> A >> B;
        if (A > M) continue;

        // 何日めまでにやらないといけないか
        v[M - A].push_back(B);
    }

    priority_queue<ll> que;

    ll ans = 0;

    // 何日めか
    for (int i = M - 1; i >= 0; i--) {
        for (auto b : v[i]) {
            que.push(b);
        }

        if (!que.empty()) {
            ll s = que.top();
            que.pop();

            ans += s;
        }
    }


    cout << ans << endl;
}

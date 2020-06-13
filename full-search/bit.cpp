//
// ビット全探索 
//
// verified
// [C - Switches](https://atcoder.jp/contests/abc128/tasks/abc128_c)
//
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;
ll N, M;

int main() {
    cin >> N >> M;
    
    vector<ll> s[M];
    rep(i, M) {
        ll k;
        cin >> k;
        rep(j, k) {
            ll tmp;
            cin >> tmp;
            tmp--;
            s[i].push_back(tmp);
        }
    }

    vector<ll> p(M);
    rep(i, M) cin >> p[i];

    // solve
    ll ans = 0;
    for (int i = 0; i < 1 << N; i++) {
        map<ll, ll> on;
        for (int j = 0; j < N; j++) {
            if (i >> j & 1) {
                on[j]++;
            }
        }

        ll tmp = true;
        for (int j = 0; j < M; j++) {
            ll on_cnt = 0;
            for (int k = 0; k < s[j].size(); k++) {
                if (on.count(s[j][k])) {
                    on_cnt++;
                }
            }

            if (on_cnt % 2 != p[j]) {
                tmp = false;
                break;
            }
        }
        if (tmp) {
            ans++;
        }
    }

    cout << ans << endl;
}
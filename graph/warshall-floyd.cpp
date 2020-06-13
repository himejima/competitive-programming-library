//
// ワーシャルフロイド  
//
// 計算量: O(|V|^3) 
// 
// verified
// [D - バスと避けられない運命](https://atcoder.jp/contests/abc012/tasks/abc012_4)

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll dist[310][310];

int main() {
    ll N, M;
    cin >> N >> M;
    rep(i, N)rep(j, N) {
        if (i == j) {
            dist[i][j] = 0;
        } else {
            dist[i][j] = INF;
        }
    }

    rep(i, M) {
        ll a, b, t;
        cin >> a >> b >> t;
        a--; b--;
        dist[a][b] = t;
        dist[b][a] = t;
    }

    rep(k, N)rep(i, N)rep(j, N) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }

    ll ans = INF;
    rep(i, N) {
        ll tmp = 0;
        rep(j, N) {
            tmp = max(tmp, dist[i][j]);
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}
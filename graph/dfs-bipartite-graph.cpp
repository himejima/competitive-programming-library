//
// dfs 2部グラフの頂点彩色
//
// verified
// [C - 嘘つきな天使たち](https://atcoder.jp/contests/maximum-cup-2018/tasks/maximum_cup_2018_c)
//
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N;
vector<ll> A;
vector<ll> G[100100];
int color[(int)1e5 + 5];

bool dfs(int v, int c) {
    color[v] = c;
    for (int i = 0; i < G[v].size(); i++) {
        // 隣接している頂点が同じ色
        if (color[G[v][i]] == c) return false;
 
        // 隣接している頂点がまだ塗られていない
        if (color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false;
    }
 
    return true;
}

int main() {
    cin >> N;
    A.resize(N);
    rep(i, N) cin >> A[i];

    rep(i, N) {
        A[i]--;
        G[i].push_back(A[i]);
    }

    // 二部グラフかどうかの判定フラグ
    bool nibu = true;
    for (int i = 0; i < N; i++) {
        if (color[i] == 0) {
            if (!dfs(i, 1)) {
                nibu = false;
                break;
            }
        }
    }

    if (nibu) {
        ll a = 0, b = 0;

        rep(i, N) {
            if (color[i] == 1) {
                a++;
            } else {
                b++;
            }
        }
        cout << max(a, b) << endl;
    } else {
        cout << -1 << endl;
    }
}
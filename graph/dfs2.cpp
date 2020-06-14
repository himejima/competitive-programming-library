//
// DFS: 連結成分の数を求める 
//
// verified
// [1160 < Problems | Aizu Online Judge](https://onlinejudge.u-aizu.ac.jp/problems/1160)
//

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

// 8 近傍
const int dx8[8] = {1, 0, -1, 0, 1, -1, 1, -1};
const int dy8[8] = {0, 1, 0, -1, 1, -1, -1, 1};

int maze[55][55];
int W, H;
void dfs(int h, int w) {
    maze[h][w] = 0;

    for (int i = 0; i < 8; i++) {
        int nh = h + dx8[i], nw = w + dy8[i];
        if (0 <= nh && nh < H && 0 <= nw && nw < W && maze[nh][nw] == 1) {
            dfs(nh, nw);
        }
    }
}


int main() {

    while (true) {
        cin >> W >> H;
        if (W == 0 && H == 0) break;

        rep(i, H)rep(j, W) {
            cin >> maze[i][j]; 
        }

        int ans = 0;
        rep(i, H)rep(j, W) {
            if (maze[i][j] == 0) continue;
            dfs(i, j);
            ans++;
        }
        cout << ans << endl;
    }
}
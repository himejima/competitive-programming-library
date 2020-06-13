//
// 幅優先探索 
//
// verified
// [C - 幅優先探索](https://atcoder.jp/contests/abc007/tasks/abc007_3)
//
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll R, C;
ll sy, sx, gy, gx;
char c[55][55];
ll dist[55][55];

void bfs() {
    dist[sy][sx] = 0;

    queue<P> q;
    q.push(P(sy, sx));

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while (!q.empty()) {
        P p = q.front(); q.pop();
        if (p.first == gy && p.second == gx) break;
        for (int i = 0; i < 4; i++) {
            ll nx = p.second + dx[i], ny = p.first + dy[i];
            if (0 <= ny && ny < R && 0 <= nx && nx < C && c[ny][nx] != '#' && 
                dist[ny][nx] == INF) {
                    // cout << ny << " " << nx << endl;
                    q.push(P(ny, nx));
                    dist[ny][nx] = dist[p.first][p.second] + 1;
            }
        }
    }
}

int main() {
    cin >> R >> C;
    cin >> sy >> sx >> gy >> gx;
    sy--;
    sx--;
    gy--;
    gx--;
    // cout << sy << " " << sx << endl;
    
    rep(i, R)rep(j, C) cin >> c[i][j];
    rep(i, R)rep(j, C) dist[i][j] = INF;

    bfs();

    cout << dist[gy][gx] << endl;
}
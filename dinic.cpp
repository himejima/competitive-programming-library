//
// max-flow (Dinic's algorithm)
// 蟻本 Dinic法 p194 
//
// 計算量: O(EV^2)
// 
// verified
// [C - 2D Plane 2N Points](https://atcoder.jp/contests/abc091/tasks/arc092_a)

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;

typedef long long ll;
const int INF = 1e8;
// const ll INF = 1LL << 60;
typedef pair<int, int> P;

// to: 行き先
// cap: 容量
// rev: 逆辺
struct edge { int to, cap, rev; };
vector<edge> G[20000]; // グラフの隣接リスト
int level[20000]; // sからの距離
int iter[20000]; // どこまで調べ終わったか

// G[e.to][e.rev] で逆辺の構造体にアクセスできる
void add_edge(int from, int to, int cap) {
    G[from].push_back((edge){to, cap, (int)G[to].size()});
    G[to].push_back((edge){from, 0, (int)G[from].size() - 1});
}

// sからの距離
void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
        int v = que.front(); que.pop();
        for (int i = 0; i < G[v].size(); i++) {
            edge &e = G[v][i];
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

// 増加パスをDFSで返す
int dfs(int v, int t, int f) {
    if (v == t) return f;
    for (int &i = iter[v]; i < G[v].size(); i++) {
        edge &e = G[v][i];
        if (e.cap > 0 && level[v] < level[e.to]) { 
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

// s から t への最大流を求める
int max_flow(int s, int t) {
    int flow = 0;
    for (;;) {
        bfs(s);
        if (level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while ((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
}

int main() {
    ll N;
    cin >> N;
    vector<P> red, blue; 
    red.resize(N);
    blue.resize(N);

    // red: 0 ~ N - 1;
    // blue: N ~ N + N  - 1
    int s = N + N - 1 + 1, t = s + 1;

    // red
    rep(i, N) {
        ll a, b;
        cin >> a >> b;
        red[i] = P(a, b);
        add_edge(s, i, 1);
    }

    // blue
    rep(i, N) {
        ll c, d;
        cin >> c >> d;
        blue[i] = P(c, d);
        add_edge(i + N, t, 1);
    }

    sort(red.begin(), red.end());
    sort(blue.begin(), blue.end());

    rep(i, N) {
        rep(j, N) {
            // can
            // cout << red[i].first << " " << red[i].second << endl;
            // cout << blue[j].first << " " << blue[j].second << endl;
            // cout << endl;
            if (red[i].first < blue[j].first && red[i].second < blue[j].second) {
                // cout << i << " " << j << endl;
                add_edge(i, N + j, 1);
            }
        }
    }

    cout << max_flow(s, t) << endl;
}
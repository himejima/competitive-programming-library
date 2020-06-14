//
// 最小費用流を求める 
// 
// 参考: 蟻本 p200
//
// verified
// [GRL_6_B < Problems | Aizu Online Judge](https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B)
//
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
// cost: コスト
// rev: 逆辺
struct edge { int to, cap, cost, rev; };
int V; // 頂点数
int E, F; // E: 辺の数, F: 流したい流量
vector<edge> G[1000]; // グラフの隣接リスト
int dist[1000]; // 最短距離
int prevv[1000], preve[1000]; // 直前の原点と辺

// fron から  
void add_edge(int from, int to, int cap, int cost) {
    G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
    G[to].push_back((edge){ from, 0, -cost, (int)G[from].size() - 1});
}

// sからtへの流量fの最小費用流を求める
// 流せない場合は-1を返す
int min_cost_flow(int s, int t, int f) {
    int res = 0;
    while (f > 0) {
        // ベルマンフォード で s-t間の最短路を求める
        fill(dist, dist + V, INF);
        dist[s] = 0;
        bool update = true;
        while (update) {
            update = false;
            for (int v = 0; v < V; v++) {
                if (dist[v] == INF) continue;
                for (int i = 0; i < G[v].size(); i++) {
                    edge &e = G[v][i];
                    if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
                        dist[e.to] = dist[v] + e.cost;
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        update = true;
                    }
                }
            }
        }

        if (dist[t] == INF) {
            // これ以上流せない
            return -1;
        }

        // s-t間最短路に沿って目一杯流す
        int d = f;
        for (int v = t; v != s; v = prevv[v]) {
            d = min(d, G[prevv[v]][preve[v]].cap);
        }
        f -= d;
        res += d * dist[t];
        for(int v = t; v != s; v = prevv[v]) {
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }

    return res;
}

/*
9 7 5
0 1 10 2
1 3 6 2
3 4 8 6
0 2 2 4
2 4 5 2
1 2 6 6
3 2 3 3
*/
int main() {
    cin >> V >> E >> F;
    rep(i, E) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        add_edge(a, b, c, d);
    }

    cout << min_cost_flow(0, V - 1, F) << endl;
}
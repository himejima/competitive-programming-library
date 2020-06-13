//
// Dijkstra algorithm
//
// verified
// [D - .. (Double Dots)](https://atcoder.jp/contests/abc168/tasks/abc168_d)

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

const string YES = "Yes";

struct edge { ll cost, to; };
vector<edge> g[200100];
ll dist[100100];
vector<ll> prever;
ll N;

void dijkstra(ll s) {
    dist[s] = 0;
    prever = vector<ll>(N, -1);

    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, s));
 
    while (!que.empty()) {
        P p = que.top(); que.pop();
        ll v = p.second;
 
        if (p.first > dist[v]) continue;
        // 次の頂点へ潜る
        for (int i = 0; i < g[v].size(); i++) {
            edge e = g[v][i];
            if (e.cost + dist[v] < dist[e.to]) {
                dist[e.to] = e.cost + dist[v];
                prever[e.to] = v;
                que.push(P(dist[e.to], e.to));
            }
        }
    }
}

int main() {
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);

    vector<ll> tmp_graph[N];

    rep(i, N) dist[i] = INF;
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back((edge){1, b});
        g[b].push_back((edge){1, a});

        tmp_graph[a].push_back(b);
        tmp_graph[b].push_back(a);
    }

    dijkstra(0);

    // cout << "Yes" << endl;
    vector<P> v;
    for (int i = 1; i < N; i++) {
        v.push_back(P(dist[i], i));
        // cout << dist[i] << endl;
    }
    sort(v.begin(), v.end());


    cout << "Yes" << endl;
    for (int i = 1; i < N; i++) {
        cout << prever[i] + 1 << endl;
    }
}
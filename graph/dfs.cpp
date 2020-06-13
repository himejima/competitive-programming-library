//
// dfs 
//
// verified
// [C - Many Requirements](https://atcoder.jp/contests/abc165/tasks/abc165_c)
//
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll INF = 1LL << 60;
long long N;
long long M;
long long Q;
vector<ll> a, b, c, d;
ll ans = 0;

// i: 何回めか
// v: 配列
void dfs(int cnt, int i, vector<int> v) {
    if (cnt >= N) {
        // 操作
        // rep(k, v.size()) {
        //     cout << v[k] << " ";
        // }
        // cout << endl;
        ll tmp = 0;
        rep(k, Q) {
            ll diff = v[b[k]] - v[a[k]];
            if (diff == c[k]) {
                tmp += d[k];
            }
        }
        ans = max(ans, tmp);
        return;
    }
    v.push_back(i);
    for (int m = i; m <= M; m++) {
        dfs(cnt + 1, m, v);
    }
}

int main() {
    scanf("%lld",&N);
    scanf("%lld",&M);
    scanf("%lld",&Q);
    a.resize(Q);
    b.resize(Q);
    c.resize(Q);
    d.resize(Q);

    for(int i = 0 ; i < Q ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
        scanf("%lld",&c[i]);
        scanf("%lld",&d[i]);
        a[i]--;
        b[i]--;
    }

    // vector<int> tmp;
    // dfs(0, 1, tmp);
    // return 0;

    for (int i = 1; i <= M; i++) {
        vector<int> tmp;
        dfs(0, i, tmp);
    }

    cout << ans << endl;
    return 0;
}
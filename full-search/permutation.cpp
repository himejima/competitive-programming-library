//
// 順列全探索 
//
// verified
// [C - Average Length](https://atcoder.jp/contests/abc145/tasks/abc145_c)
//
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll N;
vector<ll> x, y;
int main() {
    cin >> N;
    x.resize(N);
    y.resize(N);
    rep(i, N) {
        cin >> x[i] >> y[i]; 
    }

    vector<ll> v;
    rep(i, N) {
        v.push_back(i);
    }

    double sum = 0;
    double total = 0;

    do {
        double dist = 0;
        total++;

        for (int i = 0; i < v.size() - 1; i++) {
            double tmp_x = x[v[i]] - x[v[i + 1]];
            double tmp_y = y[v[i]] - y[v[i + 1]];
            dist += sqrt(tmp_x * tmp_x + tmp_y * tmp_y);
            // cout << sqrt(tmp_x * tmp_x + tmp_y * tmp_y) << endl;
        }
        sum += dist;
    } while (next_permutation(v.begin(), v.end()));
    double ans = sum / total;
    printf("%.10f\n", ans);
}
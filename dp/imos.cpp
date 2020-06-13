//
// imos法 
//
// verified
// [C - AtColor](https://atcoder.jp/contests/abc014/tasks/abc014_3)
//
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

#define MAX_V 1e6 + 5 

ll n;
vector<ll> a, b, table;
int main() {
    cin >> n;
    a.resize(n);
    b.resize(n);
    rep(i, n) cin >> a[i] >> b[i];


    table.resize(MAX_V);
    rep(i, n) {
        table[a[i]]++;
        table[b[i]+1]--;
    }
    // rep(i, 10) {
    //     cout << i << " " << table[i] << endl;
    // }
    rep(i, MAX_V) {
        if (0 < i) table[i] += table[i - 1];
    }

    ll M = 0;
    rep(i, MAX_V) {
        if (M < table[i]) M = table[i];
    }
    cout << M << endl;
}
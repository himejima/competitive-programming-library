//
// 尺取り法の例
//
// verified
// [D - Handstand](https://atcoder.jp/contests/abc124/tasks/abc124_d)
//
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N, K;
string S;

int main() {
    cin >> N >> K;
    cin >> S;

    // 1 0 1 0 1 という配列を作る
    vector<ll> nums;
    int current = 1;
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        // cout << (char)(current - '0') << endl;
        if (S[i] - '0' == current) {
            cnt++;
        } else {
            nums.push_back(cnt);

            // 0 と 1の切り替え
            current = 1 - current;
            // cout << current << " " << (char)current << endl;
            cnt = 1;
        }
        // cout << cnt << endl;
    }
    if (cnt != 0) nums.push_back(cnt);

    // 1 で終わらない場合は 足してあげる
    if (nums.size() % 2 == 0) nums.push_back(0);

    // rep(i, nums.size()) {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;


    // しゃくとりでやる
    // 先頭を固定

    ll left = 0, right = 0;
    ll add = 2 * K + 1;

    ll ans = 0;
    ll tmp = 0;

    // 左端の移動
    for (ll i = 0; i < nums.size(); i += 2) {
        ll next_left = i;
        ll next_right = min(i + add, (ll)nums.size());

        while (next_left > left) {
            tmp -= nums[left];
            left++;
        }

        while (next_right > right) {
            tmp += nums[right];
            right++;
        }
        // cout << "l: " << next_left << " r: " << next_right << " " << tmp << endl;
        ans = max(ans, tmp);
    }

    cout << ans << endl;
}
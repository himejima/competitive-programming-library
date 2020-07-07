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
    cin >> N >> K >> S;

    // 1 0 1 0 1 と連続している数の配列を作る
    vector<int> nums;

    int num = 1;
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] == (char)(num + '0')) {
            cnt++;
        } else {
            // 切り替え
            // 1 -> 0
            // 0 - > 1
            nums.push_back(cnt);
            num = 1 - num; 
            cnt = 1;
        }
    }

    if (cnt != 0) {
        nums.push_back(cnt);
    }

    // 1 の数 0をたす
    if (nums.size() % 2 == 0) nums.push_back(0);

    // rep(i, nums.size()) {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;

    int add = 2 * K + 1;
    int ans = 0;

    // 1. for ループの外側にleft, right を持つ
    int left = 0;
    int right = 0;
    int tmp = 0; // [left, right) の sum

    for (int i = 0; i < nums.size(); i += 2) {
        // 2. 次の left, right を決める
        int next_left = i;
        int next_right = min((int)nums.size(), i + add);

        // 3. 計算する
        while (next_left > left) {
            tmp -= nums[left];
            left++;
        }

        while (next_right > right) {
            tmp += nums[right];
            right++;
        }

        // cout << i << " " << right << endl;
        // for (int j = i; j < right; j++) {
        //     tmp += nums[j];
        // }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}
//
// Z-algorithm
//   res[i] := S[i:] と S[0: ] との最長共通部分列の長さ
//
// verified
// [E - Who Says a Pun?](https://atcoder.jp/contests/abc141/tasks/abc141_e)
//
// 参考 (借りてます)
// [algorithm/z_algorithm.cpp at master · drken1215/algorithm](https://github.com/drken1215/algorithm/blob/master/String/z_algorithm.cpp)
//
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N;
string S;

// こっち使った
vector<int> Zalgo(const string &S) {
    int N = (int)S.size();
    vector<int> res(N);
    res[0] = N;
    int i = 1, j = 0;
    while (i < N) {
        while (i+j < N && S[j] == S[i+j]) ++j;
        res[i] = j;
        if (j == 0) {++i; continue;}
        int k = 1;
        while (i+k < N && k+res[k] < j) res[i+k] = res[k], ++k;
        i += k, j -= k;
    }
    return res;
}

vector<int> Z_algorithm(string S) {
	int c = 0, n = S.size();
	//接頭辞の長さを保存する配列を返す。
	//i = 1からやるとする。
	//Z[1]には赤下線が存在しないので、「溢れるor共通部分がない」のところにまずいく。
	//実装上、上のような挙動をしてもらうため、Z[0]=n;は[1, n - 1]まで計算が終わった後に入れる。
	//cは、赤下線の左端の位置。
	vector<int> Z(n, 0);
	for (int i = 1; i < n; i++) {
		int l = i - c;
		//今着目してる部分が赤下線の左端から何個分離れているかをlに入れる。
		if (i + Z[l] < c + Z[c]) {
			//この条件を満たすのは、「青下線が赤下線に収まる」。
			//この時、すでに計算されてるなのでそれを流用する。
			Z[i] = Z[l];
		}
		else {
			//この条件を満たすのは、「赤下線から青下線が溢れる」or「赤下線と青下線の共通部分がない」。
			int j = max(0, c + Z[c] - i);
			//c + Z[c] - i > 0の時、これは「溢れる」が該当する。
			//溢れてるのなら、収まる分は計算せずに、溢れた分(j番目から)だけ愚直に突き合わせればよい。
			//そもそも共通部分がないならば、全部突き合わせる。この時、式からj = 0;となるとわかる。

			//愚直に突き合せてる部分
			while (i + j < n && S[j] == S[i + j])j++;

			Z[i] = j;
			//今の見てるiで、赤下線に完全に含まれなくなったので、今のiを赤下線の左端として、次のiをまた計算する。
			c = i;
		}
	}

	//最後にこれを忘れずに
	Z[0] = n;
	return Z;
}

int main() {
    cin >> N >> S;

    // zアルゴリズム解
    int ans = 0;
    vector<int> tmp = Zalgo(S);
    for (int i = 0; i < N; i++) {
        string T = S.substr(i);
        vector<int> p = Zalgo(T);
        for (int j = 0; j < T.size(); j++) {
            int a = min(p[j], j);
            ans = max(ans, a);
        }
    }
    cout << ans << endl;
}

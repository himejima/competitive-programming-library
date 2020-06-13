class UnionFind {
    int par[MAX_N];  // 親
    int my_rank[MAX_N]; // 木の深さ

public:
    void init(int n) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
            my_rank[i] = 0;
        }
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (my_rank[x] < my_rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (my_rank[x] == my_rank[y]) my_rank[x]++;
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    cin >> N >> K >> L;
    UnionFind uf, train;
    uf.init(N);
    train.init(N);
}
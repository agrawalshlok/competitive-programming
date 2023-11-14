// jiangly 
template <typename T>
struct Fenwick {  // 1-based
    const int n;
    std::vector<T> a;
    Fenwick(int m) : n(m), a(m) {}
    void add (int x, T v) { // add v to index x + 1
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    T sum (int x) {  // sum till index x (1...x)
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }

    T rangeSum (int l, int r) {
        return sum(r) - sum(l);
    }
};

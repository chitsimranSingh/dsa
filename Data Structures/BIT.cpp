class BIT {
private:
    int *bit, n;
public:
    BIT(int N) {
        n = N;
        bit = new int[n+1];
        for (int i = 0; i <= n; i++)
            bit[i] = 0;
    };
    void add(int ind, int val) {
        ind += 1;
        while (ind <= n) {
            bit[ind] += val;
            ind = ind + (ind & -ind);
        }
    }
    int sum(int ind) {
        ind += 1;
        int res = 0;
        while (ind > 0) {
            res += bit[ind];
            ind = ind - (ind & -ind);
        }
        return res;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};
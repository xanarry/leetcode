class Solution1 {
public:
    unordered_map<int, int> m = {
            {0, 0},
            {1, 1},
            {2, 5},
            {3, -1},
            {4, -1},
            {5, 2},
            {6, 9},
            {7, -1},
            {8, 8},
            {9, 6}
    };

    bool  isGood(int n) {
        int bak = n, num = 0, base = 1;
        while (n != 0) {
            int t = n % 10;
            if (m[t] == -1)
                return false;
            num = m[t] * base + num;
            base *= 10;
            n /= 10;
        }
        return bak != num;
    }

    int rotatedDigits(int N) {
        int ans = 0;
        for (int i = 0; i <= N; i++)
            ans += isGood(i);
        return ans;
    }
};
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0) && x != 0)
            return false;
        int sum = 0, backup = x;
        while (x != 0) {
            int t = x % 10;
            sum = sum * 10 + t;
            x /= 10;
        }
        return sum == backup;
    }
};
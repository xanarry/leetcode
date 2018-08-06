class Solution {
public:
    bool check(string s, int cnt) {
        if (cnt > 1)
            return false;
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] == s[j]) {
                i++; j--; //如果两端相同则忽略
            } else {
                //两端不同则分别对左右两边丢一个字符做进一步判断
                bool res1 = check(s.substr(i + 1, j - i), cnt + 1);
                bool res2 = check(s.substr(i,     j - i), cnt + 1);
                return res1 || res2;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        return check(s, 0);
    }
};

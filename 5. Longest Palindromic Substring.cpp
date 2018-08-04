class Solution {
public:
        bool palindromic(string &s, int i, int j) {
        for (; i < j; i++, j--) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        string longstr;
        for (int i = 0; i < s.length(); i++) {
            int j = s.length();
            do {
                j = (int) s.find_last_of(s[i], j);
                if (palindromic(s, i, j) && (j - i + 1) > longstr.length()) {
                    longstr = s.substr(i, j - i + 1);
                    break;
                }
                j--;
            } while (j > i);
        }
        return longstr;
    }
};
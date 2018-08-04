class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;
            cout << s[i] << "-" << s[j] << endl;
            if ((s[i] | 32) != (s[j] | 32))
                return false;
            i++;
            j--;
        }
        return true;
    }
};
class Solution {
public:
    string toLowerCase(string str) {
        string ans;
        for (char c : str)
            ans += (char) (c | 32);
        return ans;
    }
};
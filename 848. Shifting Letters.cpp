class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        vector<char> charArray = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        string ans;
        for (int i = (int) shifts.size() - 1; i >= 0; i--) {
            if (i + 1 < shifts.size())
                shifts[i] = (shifts[i] % 26 + shifts[i + 1] % 26) % 26;
            else
                shifts[i] = shifts[i] % 26;
        }

        for (int i = 0; i < shifts.size(); i++)
            ans += charArray[((S[i] - 'a') + shifts[i]) % 26];
        return ans;
    }
};
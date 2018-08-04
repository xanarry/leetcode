class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> m = {
                {"I",  1   },
                {"IV", 4   },
                {"V",  5   },
                {"IX", 9   },
                {"X",  10  },
                {"XL", 40  },
                {"L",  50  },
                {"XC", 90  },
                {"C",  100 },
                {"CD", 400 },
                {"D",  500 },
                {"CM", 900 },
                {"M",  1000}
        };
        int i = 0, ans = 0;
        while (i < s.length()) {
            string twoChars;
            string oneChar;
            if (m[twoChars = s.substr(i, 2)] > 0) {
                ans += m[twoChars];
                i += 2;
            } else if (m[oneChar  = s.substr(i, 1)] > 0) {
                ans += m[oneChar];
                i++;
            }
        }
        return ans;
    }
};
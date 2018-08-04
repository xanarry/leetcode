class Solution {
public:
    string intToRoman(int num) {
        map<int, string> m = {
                {1,    "I"},
                {4,    "IV"},
                {5,    "V"},
                {9,    "IX"},
                {10,   "X"},
                {40,   "XL"},
                {50,   "L"},
                {90,   "XC"},
                {100,  "C"},
                {400,  "CD"},
                {500,  "D"},
                {900,  "CM"},
                {1000, "M"},
                {5000, "Q"}
        };

        vector<int> bases = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000, 5000};

        string ans;
        while (num > 0) {
            int i = 0, j = 0;
            //查找与目标数字最近的一个且大于目标数字的一个特征数字
            while (i < bases.size() && num > bases[i])
                i++;
            //如果正好相等
            if (num == bases[i]) {
                ans += m[bases[i]];
                num -= bases[i];
            } else {
                //否则计算使用一个
                ans += m[bases[i - 1]];
                num -= bases[i - 1];
            }
        }
        return ans;
    }
};
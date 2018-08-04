class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        int baseVal = (numRows - 1) * 2;
        if (baseVal == 0) //要考虑行数为一的特殊情况
            baseVal = 1;
        int slen = (int) s.length();

        for (int i = 0; i < numRows; i++) {
            int col = 0, index;
            while (true) {
                index = i + baseVal * (col++);
                if (index < slen)
                    res += s[index];
                else
                    break;
                //中间行有额外的字符要填充
                if (i != 0 && i != numRows - 1) {
                    if ((index + (numRows - i - 1) * 2) < slen)
                        res += s[index + (numRows - i - 1) * 2];
                    else
                        break;
                }
            }
        }
        return res;
    }
};
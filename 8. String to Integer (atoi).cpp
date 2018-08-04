class Solution {
public:
    int myAtoi(string str) {
        long long res = 0; //使用long long来防治溢出
        int i = 0, gt = 1;
        //过滤掉字符串前面的空格
        while (str[i] == ' ')
            i++;
        //判读字符串的开头是不是正负号,并记录负号
        if (str[i] == '-' || str[i] == '+') {
            if (i < str.length() && isdigit(str[i + 1])) {
                if (str[i] == '-')
                    gt = -1;
            } else
                return 0;
            i++;
        } else if (!isdigit(str[i]))
            return 0;

        //正真的转换部分
        for (; i < str.length() && isdigit(str[i]); i++) {
            int val = str[i] - '0';
            res = res * 10 + val;
            //判读是否溢出
            if ((res * gt) > INT32_MAX)
                return INT32_MAX;
            if ((res * gt) < INT32_MIN)
                return INT32_MIN;
        }
        return (int) res * gt;
    }
};
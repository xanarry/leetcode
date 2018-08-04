class Solution {
public:
    bool isInteger(string s) {
        if (0 == s.length())
            return false;
        int i = 0;
        //移除前导0
        while (s[i] == ' ') i++;
        //移除前导正负号
        while (s[i] == '+' || s[i] == '-') i++;

        if (i == s.length())
            return false;

        bool meetSpace = 0;
        while (isdigit(s[i]) || s[i] == ' ') {
            if (s[i] == ' ') {
                if (meetSpace == 0)
                    meetSpace = true;
                else
                    return false;
            }
            i++;
        }
        return i == s.length();
    }

    bool isNumber(string s) {
        if (s.length() == 0)
            return false;

        int i = 0;
        while (s[i] == ' ') i++; //前导空格不影响, 移除
        while (s[i] == '+' || s[i] == '-') i++; //移除符号

        if (i == s.length()) return false; //如果全是空格就不是数字

        bool hasMeetPoint = false; //是否遇到小数点
        bool hasMeetExp   = false; //是否遇到E
        bool hasMeetDigit = false; //是否遇到数字
        bool hasMeetSpace = false; //是否遇到空格

        //从此开始只能有数字,点,e
        while (i < s.length()) {
            if (!isdigit(s[i]) && s[i] != 'e' && s[i] != '.' && s[i] != ' ')
                return false;

            if (s[i] == ' ') {
                if (!hasMeetSpace)
                    hasMeetSpace = true;
                else if (s[i] != ' ')
                    return false;
            }

            if (isdigit(s[i])) {
                if (!hasMeetDigit)
                    hasMeetDigit = true;
                if (hasMeetSpace)
                    return false;
            }

            //如果检查到小数部分
            if (hasMeetPoint) {
                if (s[i] == '.') //小数点只能出现一次
                    return false;
            }

            if (s[i] == '.') {
                if (hasMeetSpace)
                    return false;

                //判断"  . "或者"."的情况
                if (!hasMeetDigit && (i + 1 == s.length() || (i + 1 < s.length() && !isdigit(s[i + 1]))))
                    return false;

                if (!hasMeetPoint)
                    hasMeetPoint = true ;//标记小数部分已经开始
                else
                    return false;
            }

            if (s[i] == 'e') {//遇到指数
                //"  e10" is not ok
                if (!hasMeetDigit)
                    return false;
                else if (!hasMeetSpace) //"4 e" is not ok, "23.e12" is ok
                    return isInteger(s.substr((unsigned long) i + 1));
                else
                    return false;
            }
            i++;
        }
        return hasMeetDigit;
    }
};
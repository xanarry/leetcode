class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mymap[128];//使用数组做map,速度更快,字符做键,字符下标做值
        memset(mymap, -1, sizeof(int) * 128); //将数组字
        int len = 0, maxLen = 0, lastStartPos = -1;
        for (int i = 0; i < s.size(); i++) {
            //如果当前遍历遇到的字符串不在最近无重复字符的字符串中,那么标记并更新长度
            if (mymap[s[i]] == -1 || mymap[s[i]] < lastStartPos) {
                mymap[s[i]] = i;
                len++;
                if (len > maxLen) //更新长度
                    maxLen = len;
            } else  {
                if (mymap[s[i]] > lastStartPos) {
                    lastStartPos = mymap[s[i]];//标记新的不重复字符串的起点
                    mymap[s[i]] = i;//更新重复字符位置为最靠后的位置
                }
                len = i - lastStartPos;
            }
        }
        return maxLen;
    }
};
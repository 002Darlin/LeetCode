//字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成（比如，waterbottle是erbottlewat旋转后的字符串）。 
//
// 示例1: 
//
//  输入：s1 = "waterbottle", s2 = "erbottlewat"
// 输出：True
// 
//
// 示例2: 
//
//  输入：s1 = "aa", s2 = "aba"
// 输出：False
// 
//
// 
// 
//
// 提示： 
//
// 
// 字符串长度在[0, 100000]范围内。 
// 
//
// 说明: 
//
// 
// 你能只调用一次检查子串的方法吗？ 
// 
//
// Related Topics 字符串 字符串匹配 👍 208 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isFlipedString0(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (m != n) {
            return false;
        }
        if (n == 0) {
            return true;
        }
        for (int i = 0; i < n; i++) {
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (s1[(i + j) % n] != s2[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return true;
            }
        }
        return false;
    }

    bool isFlipedString1(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (m != n) return false;
        if (m == 0) return true;
        for (int i = 0; i < m; i++) {
            if (s1[i] == s2[0]) {
                if (s1.substr(0, i) == s2.substr(m - i) && s1.substr(i) == s2.substr(0, m - i))
                    return true;
            }
        }
        return false;
    }

    bool isFlipedString(string s1, string s2) {
        return s1.size()==s2.size()&&(s1 + s1).find(s2) != -1;
    }
    /*1、首先判断s1 和 s2的长度是否相等
    2、如果相等，那儿将s2和s2进行拼接，此时如果s2是由s1轮转得到，那么合并后的子串必定包含s1。*/
};

//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s;
    string s1 = "aa", s2 = "aba";
    cout << boolalpha << s.isFlipedString(s1, s2) << endl;
    s1 = "waterbottle", s2 = "erbottlewat";
    cout << boolalpha << s.isFlipedString(s1, s2) << endl;
}
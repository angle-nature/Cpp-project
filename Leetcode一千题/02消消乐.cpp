#include<iostream>
using namespace std;
#include<string>

class Solution {
public:
    // 笨比方法
    string removeDuplicates(string S) {
        bool flag = true;
        while (flag) {
            flag = false;
            for (int i = 0; i < S.length(); i++) {
                if (S[i] == S[i + 1]) {
                    string temp;
                    temp.assign(S, 0, i);
                    temp.append(S, i + 2, S.length() - i);
                    S = temp;
                    flag = true;
                }
            }
        }
        return S;
    }
    // 栈 方法
    string removeDuplicates1(string S) {
        string res;
        for (char ch : S) {
            if (!res.empty() && res.back() == ch) {
                res.pop_back();
            }
            else {
                res.push_back(ch);
            }
        }
        return res;
    }
};

int main() {
    Solution sl;
    string s = "abbaca";
    cout << sl.removeDuplicates(s) << endl;
    cout << sl.removeDuplicates1(s) << endl;
    return 0;
}
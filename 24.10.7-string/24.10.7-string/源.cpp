//#include <iostream>
//#include<string>
//using namespace std;
//
//int main() {
//    string s1;
//    int cout = 0;
//    getline(cin, s1);
//    char* a = NULL;
//    for (int i = 0; i < s1.size(); i++) {
//        if (s1[i] == ' ')
//            a = &s1[i]; // 注意 while 处理多个 case
//
//    }
//    if (a == NULL)
//        return s1.size();
//    while (*a != '\0')
//    {
//        a++;
//        cout++;
//    }
//    return cout - 1;
//}
#include<iostream>
#include<string>
using namespace std;
//class Solution {
//public:
//    bool isLetterofNumber(char ch)
//    {
//        if (ch <= 'z' && ch >= 'a' || ch <= '9' && ch >= '0')
//            return true;
//        else
//            return false;
//
//    }
//    bool isPalindrome(string s) {
//        for (auto& e : s)
//        {
//            if (e <= 'Z' && e >= 'A')
//                e = e + 32;
//        }
//        int left = 0;
//        int right = s.size() - 1;
//        while (left < right)
//        {
//            while (left < right && !isLetterofNumber(s[left]))
//                left++;
//            while (left < right && !isLetterofNumber(s[right]))
//                right--;
//            if (left < right)
//            {
//                if (s[right] == s[left])
//                {
//                    right--;
//                    left++;
//                }
//                else
//                    return false;
//            }
//            else
//                return true;
//        }
//        return true;
//
//    }
//};
//class Solution {
//public:
//    string addStrings(string num1, string num2) {
//        int end1 = num1.size() - 1;
//        int end2 = num2.size() - 1;
//        int tmp = 0;//进制
//        int s1 = 0;
//        int s2 = 0;
//        int s = 0;
//        string nums;
//        string nums2;
//        while (end1 >= 0 || end2 >= 0)
//        {
//            s1 = end1 >= 0 ? num1[end1] - '0' : 0;
//            s2 = end2 >= 0 ? num2[end2] - '0' : 0;
//            s = (s1 + s2 + tmp) % 10;
//            tmp = (s1 + s2 + tmp) / 10;
//            nums += (s + '0');
//            end1--;
//            end2--;
//
//        }
//        if (tmp != 0)
//            nums += ('1');
//        string::reverse_iterator rit = nums.rbegin();
//        while (rit != nums.rend())
//        {
//            nums2 += (*rit);
//            rit++;
//            
//        }
//        return nums2;
//    }
//};
//int main()
//{
//  /*  string s1("156");
//    string s3("54");
//    Solution s2;
//    s2.addStrings(s1,s3);*/
//
//}
int main() {
    string s1;
    getline(cin, s1);
    int a[256] = { 0 };
    string::iterator it = s1.begin();
    while (it != s1.end())
    {
        ++a[*it];
        ++it;
    }
    for (auto& e : s1)
    {
        if (a[e] == 1)
        {
            cout << e << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return -1;
}
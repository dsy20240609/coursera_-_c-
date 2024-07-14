#include <iostream>
#include <string>
#include <vector>

// 定义 MyString 类，继承自 std::string
class MyString : public std::string {
public:
    // 继承 std::string 的所有构造函数
    using std::string::string;

    // 添加一个分割字符串的函数
    std::vector<MyString> split(char delimiter) const {
        std::vector<MyString> tokens;
        size_t start = 0;
        size_t end = find(delimiter);
        while (end != std::string::npos) {
            tokens.push_back(substr(start, end - start));
            start = end + 1;
            end = find(delimiter, start);
        }
        tokens.push_back(substr(start));
        return tokens;
    }

    // 重载 + 运算符，用于字符串连接
    MyString operator+(const MyString& other) const {
        return MyString(static_cast<const std::string&>(*this) + static_cast<const std::string&>(other));
    }

    // 重载 == 运算符，用于字符串比较
    bool operator==(const MyString& other) const {
        return static_cast<const std::string&>(*this) == static_cast<const std::string&>(other);
    }

    // 重载 << 运算符，用于输出
    friend std::ostream& operator<<(std::ostream& os, const MyString& str) {
        os << static_cast<const std::string&>(str);
        return os;
    }

    // 重载 >> 运算符，用于输入
    friend std::istream& operator>>(std::istream& is, MyString& str) {
        std::string temp;
        is >> temp;
        str = temp;
        return is;
    }
};

int main() {
    MyString s1 = "abcd-efgh-abcd-";
    MyString s2 = "ijkl-mnop";
    MyString s3 = "qrst-abcd-";
    MyString s4 = "uvw xyz";

    // 操作符重载测试
    std::cout << "1. " << s1 << std::endl;

    MyString s5 = s1.substr(0, 5);
    std::cout << "2. " << s5 << std::endl;

    MyString s6 = s1.substr(0, 0);
    std::cout << "3. " << s6 << std::endl;

    MyString s7 = s1.substr(0, 10);
    std::cout << "4. " << s7 << std::endl;

    MyString s8 = s1.substr(5, 5);
    std::cout << "5. " << s8 << std::endl;

    MyString s9 = s1.substr(2, 1);
    std::cout << "6. " << s9 << std::endl;

    MyString s10 = s1.substr(0, 5);
    std::cout << "7. " << s10 << std::endl;

    MyString s11 = s2.substr(0, 5);
    std::cout << "8. " << s11 << std::endl;

    MyString s12 = s2.substr(0, 9);
    std::cout << "9. " << s12 << std::endl;

    MyString s13 = s3.substr(0, 10);
    std::cout << "10. " << s13 << std::endl;

    MyString s14 = s3.substr(5, 10);
    std::cout << "11. " << s14 << std::endl;

    std::vector<MyString> words = s4.split(' ');
    for (const auto& word : words) {
        std::cout << word << std::endl;
    }

    // 测试 + 和 == 运算符
    MyString s15 = s1 + s2;
    std::cout << "Concatenated string: " << s15 << std::endl;

    bool isEqual = (s1 == s3);
    std::cout << "Are s1 and s3 equal? " << (isEqual ? "Yes" : "No") << std::endl;

    // 测试输入输出运算符
    MyString s16;
    std::cout << "Enter a string: ";
    std::cin >> s16;
    std::cout << "You entered: " << s16 << std::endl;

    return 0;
}


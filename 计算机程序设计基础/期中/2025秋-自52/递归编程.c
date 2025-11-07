#include <stdio.h>
#include <string.h>

const int MAX_LENGTH = 100;

void Eliminate(char str[]) {
    char newStr[MAX_LENGTH + 1]; // 用于存储消除后的新字符串
    int len = strlen(str), count = 0, newIndex = 0; // 获取字符串长度，计数器和新字符串索引
    char lastChar = '\0'; // 记录当前字符
    for (int i = len - 1; i >= 0; --i) { // 自右至左扫描字符串
        if (str[i] == lastChar) {
            count++; // 计数连续相同字符
        } else { // 遇到不同字符
            if (count < 3) { // 如果连续字符少于 3 次，保留
                for (int j = 0; j < count; ++j) {
                    newStr[newIndex++] = lastChar; // 将字符复制到新字符串
                }
            }
            lastChar = str[i]; // 更新当前字符
            count = 1; // 重置计数器
        }
    }
    if (count < 3) { // 处理最后一组字符
        for (int j = 0; j < count; ++j) {
            newStr[newIndex++] = lastChar;
        }
    }
    // 将新字符串反转并放回
    for (int i = 0; i < newIndex; ++i) {
        str[i] = newStr[newIndex - 1 - i];
    }
    str[newIndex] = '\0'; // 添加字符串终止符
    // 递归调用
    if (newIndex < len) { // 如果有字符被消除，继续递归
        Eliminate(str);
    }
}

int main() {
    char str[MAX_LENGTH + 1]; // 定义字符串数组
    printf("请输入字符串：");
    scanf("%s", str); // 从键盘输入字符串
    Eliminate(str); // 调用递归函数进行消除
    printf("消除后的字符串：%s\n", str); // 输出处理后的字符串
    return 0;
}

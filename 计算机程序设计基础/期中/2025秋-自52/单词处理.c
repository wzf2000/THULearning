#include <ctype.h> // 包含 isalpha 函数的头文件
#include <stdio.h>

const int MAX_LENGTH = 200; // 实际上题目里的示例就超过了 100

void MyReplace(char str[]) {
    for (int i = 0; str[i] != '\0'; ++i) { // 遍历字符串直到遇到终止符
        if (!isalpha(str[i])) { // 判断是否为字母
        // 也可以使用 (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
            str[i] = ' '; // 替换为空格字符
        }
    } // 由于 str 是数组参数，修改会直接影响原字符串
}

int LongestWord(char str[]) {
    int maxLen = 0, currentLen = 0; // 用于记录最大和当前单词长度
    for (int i = 0; str[i] != '\0'; ++i) { // 遍历字符串直到遇到终止符
        if (str[i] != ' ') currentLen++; // 如果不是空格，表示在单词中，增加当前单词长度
        else { // 遇到空格，表示单词结束
            if (currentLen > maxLen) maxLen = currentLen; // 更新最大长度
            currentLen = 0; // 重置当前单词长度
        }
    }
    // 特别注意：最后还需要检查一次，以防字符串以非空格结尾
    if (currentLen > maxLen) maxLen = currentLen;
    return maxLen; // 返回最长单词长度
}

int main() {
    char str[MAX_LENGTH + 1]; // 定义字符串数组，长度为 100 + 1（包括终止符）
    puts("Please input str:");
    fgets(str, MAX_LENGTH + 1, stdin); // 从键盘读入字符串
    MyReplace(str); // 调用替换函数
    puts("The replaced str is:");
    puts(str); // 输出替换后的字符串
    int len = LongestWord(str); // 调用计算最长单词长度函数
    // 输出最长单词长度
    printf("The length of the longest word in the line is: %d.\n", len);
    return 0;
}

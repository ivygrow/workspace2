// ConsoleApplication10.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
//函数在一个字符串中进行搜索，查找所有在一个给定字符集合中出现的字符
//函数原型：char *find_char( char const *source, char const *chars);
#include<stdio.h>
#include<string.h>
char* find_char(char const* source, char const* chars)
{
    const char* p;
    if (source == NULL || chars == NULL)
        return NULL;
    else
    {
        while (*(source++) != '\0')
            for (p = chars; *p != '\0'; p++)
                if (*source == *p)
                    return (char*)source;
    }
    return NULL;
}

int main()
{
    char* p = "ABC";
    char* q = "XRCQEF";
    char* result;
    result = find_char(p, q);
    printf("result:%s\n", result);
    getchar();
    return 0;
}

#include <cstddef>
int del_substr(char* str, char const* substr)
{
    int flag = 0;   //判断是否相等
    char* stringStr = str;
    char* stringResult = NULL;
    char const* stringSubstr = substr;

    while (*stringStr != '\0')
    {
        if (*stringStr == *stringSubstr)
        {
            flag++;
            stringResult = stringStr;
            *stringStr++;
            *stringSubstr++;
        }
        else
        {
            stringStr++;
            stringSubstr = substr;
        }

        if (*(stringSubstr) == '\0')
        {
            while (*stringResult)
            {

                *(stringResult - flag) = *(++stringResult);
            }
            return 1;
        }
    }
    return 0;
}
//我进行了一次更改//
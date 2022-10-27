#include <iostream>
#include <windows.h>
using namespace std;

const char* USERNAME = "ThreatBooker";
const char PASSWORD[] = { 18,3,21,18,57,19,21,3,20,24,71,38,69 };

int compare_password(char* passWord);

// int main()
int main(int argc, char* argv[])
{
    LPCWSTR Prompt1 = TEXT("UserName Error! please try again!");
    LPCWSTR Prompt2 = TEXT("Password Error! please try again!");
    LPCWSTR Prompt3 = TEXT("Congratulations,you Success!");
    char userName[MAX_PATH] = { 0 };
    char passWord[MAX_PATH] = { 0 };
    while (1)
    {
        printf("请输入你的用户名：\n");
        gets_s(userName);
        printf("请输入你的密码：\n");
        gets_s(passWord);

        if (strlen(userName) < 0xC || strcmp(userName, USERNAME))
        {
            MessageBox(NULL, Prompt1, TEXT("ThreatBook"), MB_OK);
        }
        else if (strlen(passWord) < 0xD || !compare_password(passWord))
        {
            MessageBox(NULL, Prompt2, TEXT("ThreatBook"), MB_OK);
        }
        else if(compare_password(passWord))
        {
            MessageBox(NULL, Prompt3, TEXT("ThreatBook"), MB_OK);
            system("pause");
            return 0;
        }
    }

}

int compare_password(char* passWord)
{
    char a[MAX_PATH] = { 0 };
    for (size_t i = 0; i < strlen(passWord); i++)
    {
        a[i] = passWord[i] ^ 0x66;
    }
    if (!memcmp(a, PASSWORD, 13))
    {
        return 1;
    }
    return 0;
}

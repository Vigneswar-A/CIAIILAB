#include <iostream>

using namespace std;

void naive_string_matching(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i < n - m + 1; i++)
    {
        int flag = true;
        for (int j = 0; (j < m && flag); j++)
            if (text[i + j] != pattern[j])
                flag = false;
        if (flag)
            cout << "pattern found at index " << i << endl;
    }
}

int main(void)
{
    naive_string_matching("abcabcababac", "babac");
    return 0;
}
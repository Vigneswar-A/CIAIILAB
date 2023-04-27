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

void rabin_karp(string text, string pattern, int q)
{
    int d = 26;
    int m = text.length(), n = pattern.length();
    int h = 1;
    int pattern_hash = 0;
    int text_hash = 0;

    for (int i = 0; i < n - 1; i++)
        h = (h * d) % q;

    for (int i = 0; i < n; i++)
    {
        pattern_hash = (pattern_hash * d + pattern[i]) % q;
        text_hash = (text_hash * d + text[i]) % q;
    }

    for (int i = 0; i < m - n + 1; i++)
    {
        if (text_hash == pattern_hash)
        {
            bool flag = true;
            for (int j = 0; j < n && flag; j++)
                if (pattern[j] != text[i + j])
                    flag = false;
            if (flag)
                cout << "pattern matched at " << i << endl;
        }
        if (i < m - n)
        {
            text_hash = ((text_hash - (h * text[i])) * d + text[i + n]) % q;
            if (text_hash < 0)
                text_hash += q;
        }
    }
}

int main(void)
{
    // naive_string_matching("abcabcababac", "babac");
    rabin_karp("abdabcabacdbabac", "aba", 17);
    return 0;
}
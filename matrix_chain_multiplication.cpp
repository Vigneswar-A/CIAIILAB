#include <iostream>

using namespace std;

int top_down(int i, int j, int P[])
{
    if (i == j)
        return 0;

    int ans = 1000000;
    for (int k = i; k < j; k++)
        ans = min(ans, top_down(i, k, P) + top_down(k + 1, j, P) + P[i - 1] * P[j] * P[k]);
    return ans;
}

int bottom_up(int P[], int size)
{
    int memo[size][size];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            memo[i][j] = (i == j) ? 0 : 1000000;

    for (int l = 2; l < size; l++)
    {
        for (int i = 0; i < size - l + 1; i++)
        {
            int j = i + l - 1;
            for (int k = i; k < j; k++)
                memo[i][j] = min(memo[i][j], memo[i][k] + memo[k + 1][j] + P[i - 1] * P[j] * P[k]);
        }
    }
    return memo[1][size - 1];
}

int main(void)
{
    int P[] = {5, 4, 6, 2, 7};
    cout << bottom_up(P, 5);
    return 0;
}
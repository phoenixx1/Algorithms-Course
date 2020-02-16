#include <stdio.h>

int subArraySum(int arr[], int n, int sum)
{
    int curr_sum, i, j;

    for (i = 0; i < n; i++)
    {
        curr_sum = arr[i];

        for (j = i + 1; j <= n; j++)
        {
            if (curr_sum == sum)
            {
                printf("Combination Found = 1");
                return 1;
            }
            if (curr_sum > sum || j == n)
                break;
            curr_sum = curr_sum + arr[j];
        }
    }

    printf("Combination Found = 0");
    return 0;
}

void sortA(int number[], int count)
{
    int temp, i, j, k;
    for (j = 0; j < count; ++j)
    {
        for (k = j + 1; k < count; ++k)
        {
            if (number[j] > number[k])
            {
                temp = number[j];
                number[j] = number[k];
                number[k] = temp;
            }
        }
    }
}

int main()
{
    int n, sum, i;
    scanf("%d", &n);
    int value[n];
    for (i = 0; i < n; i++)
        scanf("%d", &value[i]);
    sortA(value, n);
    scanf("%d", &sum);
    subArraySum(value, n, sum);
    return 0;
}
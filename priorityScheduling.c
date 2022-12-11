#include <stdio.h>
int main()
{
    int bt[30], tat[30], wt[30], n, p[30], pr[30];
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter process numbers: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("Enter burst time of processes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    printf("Enter priority of respective processes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pr[i]);
    }

    // sorting according to process priority;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (pr[j] < pr[j + 1])
            {
                int temp = pr[j];
                pr[j] = pr[j + 1];
                pr[j + 1] = temp;

                int temp2 = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp2;

                int temp3 = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp3;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d--", pr[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d-->", p[i]);
    }
    printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");

    wt[0] = 0;
    for (int i = 0; i < n; i++)
    {
        wt[i + 1] = wt[i] + bt[i];
        tat[i] = wt[i] + bt[i];
        atat += tat[i];
        awt += wt[i];
        printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", p[i], bt[i], tat[i], wt[i]);
    }
    printf("Average waiting time = %f\n", awt / n);
    printf("Average turn around time = %f\n", atat / n);

    return 0;
}
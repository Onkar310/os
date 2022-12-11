#include <stdio.h>
#define max 30
int main()
{
    int p[max], bt[max], wt[max], tat[max], n;
    float awt = 0, atat = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter process number: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("Enter burst time: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (bt[j] > bt[j + 1])
            {
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                int temp2 = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp2;
            }
        }
    }
    printf("Process\t Burst time\t waiting time\t Turn around time\t \n");
    wt[0] = 0;
    for (int i = 0; i < n; i++)
    {
        wt[i + 1] = wt[i] + bt[i];
        tat[i] = wt[i] + bt[i];
        atat += tat[i];
        awt += wt[i];
        printf("%d\t %d\t\t %d\t\t %d\n", p[i], bt[i], wt[i], tat[i]);
    }
    awt = awt / n;
    atat = atat / n;
    printf("Average wating time = %f \n", awt);
    printf("Average turn around time = %f ", atat);
    return 0;
}
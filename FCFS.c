#include <stdio.h>
#define MAX 30

int main()
{

    int n, wt[MAX], tat[MAX], bt[MAX];
    float atat = 0, awt = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter burst time of processes: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    wt[0] = 0;
    printf("\tProcess \tBurst time \tWating time \tTurn around time\n");
    for (int i = 0; i < n; i++)
    {
        wt[i + 1] = wt[i] + bt[i];
        tat[i] = wt[i] + bt[i];
        atat += tat[i];
        awt += wt[i];
        printf("\t%d \t\t%d \t\t%d \t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    awt = awt / n;
    atat = atat / n;
    printf("Average waiting time is %f\n", awt);
    printf("Average turn around time is %f", atat);

    return 0;
}
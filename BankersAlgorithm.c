#include <stdio.h>

struct processInfo
{
    int max[30];
    int allocated[30];
    int need[30];
};

int n;

int safetyCheck(struct processInfo process[], int available[])
{
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    int work[3];
    for (int i = 0; i < 3; i++)
    {
        work[i] = available[i];
    }

    int proceed = 1;
    while (proceed)
    {
        proceed = 0;
        for (int i = 0; i < n; i++)
        {
            int flag = 1;
            if (visited[i] == 0)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (process[i].need[j] <= work[j])
                    {
                        continue;
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 0)
                {
                    continue;
                }
                for (int j = 0; j < 3; j++)
                {
                    work[j] += process[i].allocated[j];
                }
                visited[i] = 1;
                proceed = 1;
            }
        }
    }

    int i;
    for (i = 0; i < n && visited[i] == 1; i++)
    {
        continue;
    }
    if (i == n)
        return 1;
    else
        return 0;
}

int main()
{
    int available[3];
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct processInfo process[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter max allocation for P%d ", i + 1);
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &process[i].max[j]);
        }
        printf("Enter allocation for P%d ", i + 1);

        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &process[i].allocated[j]);
            process[i].need[j] = process[i].max[j] - process[i].allocated[j];
        }
    }

    printf("Enter available : ");
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &available[i]);
    }

    printf("\nPID\tMaximum\t\tAllocated\tNeed\n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d]\t", i);
        for (int j = 0; j < 3; j++)
            printf("%d ", process[i].max[j]);
        printf("\t\t");
        for (int j = 0; j < 3; j++)
            printf("%d ", process[i].allocated[j]);
        printf("\t\t");

        for (int j = 0; j < 3; j++)
            printf("%d ", process[i].need[j]);
        printf("\n");
    }
    int ans = safetyCheck(process, available);
    if (ans)
    {
        printf("No Deadlock occur ");
        printf("It is safe");
    }
    else
    {
        printf("It is not safe");
    }

    return 0;
}

// 7 5 3 0 1 0 3 2 2 2 0 0 9 0 2 3 0 2 2 2 2 2 1 1 4 3 3 0 0 2 3 3 2
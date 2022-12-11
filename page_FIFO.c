#include <stdio.h>
int main()
{
    int n, fr, pageFault = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of frames: ");
    scanf("%d", &fr);
    int p[n];
    printf("Enter page stream: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    int temp[fr];
    for (int i = 0; i < fr; i++)
    {
        temp[i] = -1;
    }

    printf("Incoming \t\t Frame 1 \t\t Frame 2 \t\t Frame 3");
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < fr; j++)
        {
            if (p[i] == temp[j])
            {
                flag = 1;
                pageFault--;
            }
        }
        pageFault++;
        if ((pageFault <= fr) && flag == 0)
        {
            temp[i] = p[i];
        }
        else if (flag == 0)
        {
            temp[(pageFault - 1) % fr] = p[i];
        }

        printf("\n");
        printf("%d\t\t\t", p[i]);
        for (int k = 0; k < fr; k++)
        {
            if (temp[k] != -1)
                printf(" %d\t\t\t", temp[k]);
            else
                printf(" - \t\t\t");
        }
    }
    printf("\n\nTotal Page Faults:\t%d\n", pageFault);

    return 0;
}

// https://prepinsta.com/operating-systems/page-replacement-algorithms/fifo/fifo-in-c/#:~:text=The%20operating%20system%20uses%20the,when%20new%20pages%20are%20demanded.
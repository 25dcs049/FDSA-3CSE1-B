#include <stdio.h>
#define MAX 100
int main()
{
    int q[MAX], n = 0;
    int ch, x, pos, op;

    printf("Enter number of operations: ");
    scanf("%d", &op);
    while(op--)
    {
        printf("\n1.Front  2.End  3.Position\n");
        scanf("%d", &ch);
        printf("Enter patient priority: ");
        scanf("%d", &x);

        if(ch==1)               
        {
            for(int i=n; i>0; i--)
                q[i] = q[i-1];

            q[0] = x;
            n++;
        }
        else if(ch==2)           
        {
            q[n++] = x;
        }
        else if(ch==3)          
        {
            printf("Enter position: ");
            scanf("%d", &pos);

            if(pos < 1 || pos > n+1)
                printf("Invalid position\n");
            else
            {
                for(int i=n; i>=pos; i--)
                    q[i]=q[i-1];

                q[pos-1]=x;
                n++;
            }
        }
        printf("Queue: ");
        for(int i=0; i<n; i++)
            printf("%d ", q[i]);
        printf("\n");
    }
    return 0;
}
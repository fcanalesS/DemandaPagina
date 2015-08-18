#include<stdio.h>

void fifo();
void lru();

int main()
{

    fifo();
    lru();

    return 0;
}

void lru() {
    int q[10],p[10],c=0,c1,d,f,i,j,k=0,n,r,t,b[10],c2[10];
    printf("Ingrese número de paginas:");
    scanf("%d",&n);
    printf("Ingrese las paginas:\n");
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);
    printf("Ingrese el numero de bloques:");
    scanf("%d",&f);
    q[k]=p[k];
    printf("\n\t%d\n",q[k]);
    c++;
    k++;
    //====== LRU ======//
    for(i=1;i<n;i++)
    {
        c1=0;
        for(j=0;j<f;j++)
        {
            if(p[i]!=q[j])
                c1++;
        }
        if(c1==f)
        {
            c++;
            if(k<f)
            {
                q[k]=p[i];
                k++;
                for(j=0;j<k;j++)
                    printf("\t%d",q[j]);
                printf("\n");
            }
            else
            {
                for(r=0;r<f;r++)
                {
                    c2[r]=0;
                    for(j=i-1;j<n;j--)
                    {
                        if(q[r]!=p[j])
                            c2[r]++;
                        else
                            break;
                    }
                }
                for(r=0;r<f;r++)
                    b[r]=c2[r];
                for(r=0;r<f;r++)
                {
                    for(j=r;j<f;j++)
                    {
                        if(b[r]<b[j])
                        {
                            t=b[r];
                            b[r]=b[j];
                            b[j]=t;
                        }
                    }
                }
                for(r=0;r<f;r++)
                {
                    if(c2[r]==b[0])
                        q[r]=p[i];
                    printf("\t%d",q[r]);
                }
                printf("\n");
            }
        }
    }
    //====== LRU ======//
    printf("\n");
    for (int l = 0; l < n; ++l) {
        printf("%d", p[l]);
        printf(" ");
    }
    printf("\nExisten %d fallos de pagina",c);
}


void fifo() {
    int i,j,n,a[10],frame[10],no,k,avail,count=0;

    printf("\n Ingrese el numero de paginas:\n");
    scanf("%d",&n);

    printf("\n Ingrese la pagina :\n");
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);

    printf("\n Ingrese el numero de bloques :");
    scanf("%d",&no);

    for(i=0;i<no;i++)
        frame[i]= -1;//Inicializa el contenido de los marcos con -1
    j=0;

    // ========== FIFO ========== //
    for(i=1;i<=n;i++)
    {
        printf("%d\t\t",a[i]);
        avail=0;
        for(k=0;k<no;k++)
            if(frame[k]==a[i])
                avail=1;
        if (avail==0)
        {
            frame[j]=a[i];
            j=(j+1)%no;
            count++;
            for(k=0;k<no;k++)
                printf("%d\t",frame[k]);
        }
        printf("\n");
    }
    printf("Existen %d fallos de pagina",count);
    // ========== FIFO ========== //
}

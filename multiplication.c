  #include<stdio.h>
int main()
{
   
    int i,j;
    int a[3][3];
    int b[3][3];
    int c[3][3];
    int d[3][3];
   
    int *p,*q;
    p=&a[0][0];
    q=&b[0][0];
   
    //  read matrix a :
    printf("Enter array elements of matrix a (rowise) : \n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);  //scanf automatically takes nxt element on next line
        }
        printf("\n");
    }
   
     //  read matrix b :
    printf("Enter array elements of matrix b (rowise) : \n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&b[i][j]);  //scanf automatically takes nxt element on next line
        }
        printf("\n");
    }

    // addition using pointer :
    printf("\nAddition:\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
           c[i][j]= (*p+(i*3)+j) + (*(q+(i*3)+j)) ;
        }
    }
   
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
           printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
    // multiplication using pointer
    printf("\nMultiplication:\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            d[i][j]=0;
            for(int k=0;k<3;k++)
            {
                d[i][j] = d[i][j] + ((*p+(i*3)+k)*(*q+(k*3)+j)) ;
            }
        }
    }
   
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
           printf("%d\t",d[i][j]);
        }
        printf("\n");
    }
    
  return 0;
}
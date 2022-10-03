 #include <stdio.h>
int main()
{
    int a[3][3];
    int b[3][3];
    int c[3][3];
    
    int i,j;
    
    int *p,*q;
    p=&a[0][0];
    q=&b[0][0];
    
    printf("Enter elements of first matrix\n");
    for(i=0; i<3; i++)
    {
        printf("Row: %d\n",i);
        for(j=0; j<3; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\n");

printf("Enter elements of second matrix\n");
printf("Row: %d\n",i);
for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
             scanf("%d",&b[i][j]);
        }
    }
//for addition using pointers
for(i=0; i<3; i++)
{
    for(j=0; j<3; j++)
    {
     c[i][j]= *(p+((i*3)+j)) + *(q+((i*3)+j));
    }
}
 printf("\nOutput");
 for(i=0; i<3; i++)
{
    for(j=0; j<3; j++)
    {
      printf("%d\t",c[i][j]);
    }
}
printf("\n");
 

}

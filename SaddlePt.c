#include <stdio.h>
int max_elementcolumn(int a[3][3],int );
int min_elementrow(int a[3][3],int );
int max_elementcolumn(int a[3][3],int j){
    int i,k;
    k=a[0][j];
        for(int i=0;i<3;i++){
            if(a[i][j]>k){
                k=a[i][j];
            }
    }
   
    return k;
}
int min_elementrow(int a[3][3],int i){
    int k,j;
    k=a[i][0];
        for(int j=0;j<3;j++){
            if(a[i][j]<k){
                k=a[i][j];
            }
    }
    return k;

}


void main(){
    int a[3][3],b[3][3],c[3][3],d[3][3]={0},ch,i,j,k,sum=0,min,max,flag=0;
    int n,m;
    int *p,*q;
    p=&a[0][0];
    q=&b[0][0];
    printf("enter A array elements:\n");
    for( i=0;i<3;i++){
        for( j=0;j<3;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter B array elements:\n");
    for( i=0;i<3;i++){
        for( j=0;j<3;j++){
            scanf("%d",&b[i][j]);
        }
    }
    printf("1:for additon\n2:for multiplication\n3:for saddle point\n4:for saddle point using ptr\n");
    scanf("%d\n",&ch);
    switch(ch){
        case 1: //addition
        for( i=0;i<3;i++){
            for( j=0;j<3;j++){
                c[i][j]=*(p+i*3+j)+*(q+i*3+j);
            }
        }
        printf("additon of matrix A and B is :\n");
        for( i=0;i<3;i++){
            for( j=0;j<3;j++){
                printf("%d \t",c[i][j]);
            }printf("\n");
       
        }
        break;
        case 2: //multiplication
        for( i=0;i<3;i++){
            for( j=0;j<3;j++){
                for(k=0;k<3;k++){
                    sum+=(*(p+i*3+k))*(*(q+k*3+j));
                }d[i][j]=sum;
                sum=0;
            }
        }
         printf("multiplication of matrix A and B is :\n");
        for( i=0;i<3;i++){
            for( j=0;j<3;j++){
                printf("%d \t",d[i][j]);
            }printf("\n");
        }
        break;
        case 3: //saddle point
        for( i=0;i<3;i++)
        {
            min=min_elementrow(a,i);
                for( j=0;j<3;j++)
                {
                if(min==max_elementcolumn(a,j))
                   {
                    printf("saddle point is:\n");
                    printf("%d",min);
                    flag=1;
                   }
           
                }
        }  
        if(flag==0){
            printf("no saddle point\n");
        }
        break;
       
        case 4: //saddle point using ptr

 
  printf("Enter the dimensions of your matrix : ");
  scanf("%d%d",&n,&m);

  int mat[n][m];
  int *p=&mat[0][0];

   for(int i=0;i<n;i++)
   {
          for(int j=0;j<m;j++)
          {
            printf("mat[%d][%d] : ",i+1,j+1);
            scanf("%d",&mat[i][j]);
          }
        }
   
  int min,max;
  int sol=0;
  int s[2][2];

   for(int i=0;i<n;i++)
   {
          min=mat[i][0];
          for(int j=0;j<m;j++)
     {
            if(min>=*p+(i*3)+j)
       {
              min=*p+(i*3)+j;
              s[0][0]=i;
              s[0][1]=j;
            }else continue;

    }

int j=s[0][1];
    max=mat[0][j];

for(int k=0;k<n;k++)
{
      if(max<=*p+(k*3)+j)
 {
     max=*p+(k*3)+j;
          s[1][0]=k;
          s[1][1]=j;

 }
 else continue;

}



if(min==max)
{
       if(s[0][0]==s[1][0]&&s[0][1]==s[1][1])
  {
         printf("saddle point : %d",mat[i][j]);
       }
       else printf("ERROR\n");
     }

}
}
}
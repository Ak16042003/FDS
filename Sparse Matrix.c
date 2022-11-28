#include<stdio.h>
void main(){
    int row,col,i,j,k=0,count=0;
    int c,d;
    printf("enter no. of rows and columns:\n");
    scanf("%d%d\n",&row,&col);
    int a[row][col];
    for(  i=0;i<row;i++){
        for( j=0;j<col;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]!=0){
                k++;
            }
        }
    }
    int s[k][3],p=0;
    printf("the matrix is:\n");
    for(  i=0;i<row;i++){
        for( j=0;j<col;j++){
            printf("%d \t",a[i][j]);
        }
        printf("\n");
    }
    for(  i=0;i<row;i++){
        for( j=0;j<col;j++){
            if(a[i][j]==0){
                count++;
            }
        }
    }
    if(count>((row+col)/2)){
        printf("|This is a Sparse Matrix|\n");
    }
    else{
        printf("|Not a sparse matrix|");
    }
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(a[i][j]!=0){
                s[p][0]=i;
                s[p][1]=j;
                s[p][2]=a[i][j];
                p++;
            }
        }
    }
    printf("Triplet representation of the Sparse Matrix is :\n");
    for(i=0;i<k;i++){
        for(j=0;j<3;j++){
            printf("%d \t",s[i][j]);
        } printf("\n");
    }
    printf("0 is Station A\n1 is Station B\n2 is Station C\n3 is Station D\n");
    do{printf("enter two Station numbers you want to find number of trains running on that path:\n");
    scanf("%d%d",&c,&d);
    if(c>3&&d>3){
        printf("WRONG ENTRIES\n");
        printf("NO DETAILS \n");
    }
    else{
        printf("%d\n",a[c][d]);
    }
    printf("Do yoou want to find more details \nPress 1 to continue and 0 for exit\n");
    scanf("%d",&i);
    }while(i!=0);
}
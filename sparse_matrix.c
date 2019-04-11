#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void add(int[][3] ,int[][3]);
void transpose(int[][3],int [][3]);
void multiply(int[][3] ,int[][3]);
int main()
{
    int n,m,rows=0;
    printf("Enter the size of matrix 1\n");
    scanf("%d %d",&n,&m);
    int s_m1[n][m];
    printf("Enter matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&s_m1[i][j]);
        }
    }
    printf("Sparse matrix 1 is -\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s_m1[i][j]!=0)rows++;
            printf("%2d ",s_m1[i][j]);
        }
        printf("\n");
    }
    int c_m1[rows+1][3];
    c_m1[0][0]=n;c_m1[0][1]=m;c_m1[0][2]=rows;
    int k=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s_m1[i][j]!=0){
                c_m1[k][0]=i;c_m1[k][1]=j;c_m1[k++][2]=s_m1[i][j];
            }
        }
    }
    printf("Compact matrix 1 is-\n");
    for(int i=0;i<=rows;i++){
        printf("%2d   %2d   %2d\n",c_m1[i][0],c_m1[i][1],c_m1[i][2]);
    }
    printf("Enter the size of matrix 2\n");
    scanf("%d %d",&n,&m);
    int s_m2[n][m];
    rows=0;
    printf("Enter matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&s_m2[i][j]);
        }
    }
    printf("Sparse matrix 2 is -\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s_m2[i][j]!=0)rows++;
            printf("%2d ",s_m2[i][j]);
        }
        printf("\n");
    }
    int c_m2[rows+1][3];
    c_m2[0][0]=n;c_m2[0][1]=m;c_m2[0][2]=rows;
    int k1=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s_m2[i][j]!=0){
                c_m2[k1][0]=i;c_m2[k1][1]=j;c_m2[k1++][2]=s_m2[i][j];
            }
        }
    }
    printf("Compact matrix 2 is-\n");
    for(int i=0;i<=rows;i++){
        printf("%2d   %2d   %2d\n",c_m2[i][0],c_m2[i][1],c_m2[i][2]);
    }
    printf("Multiplication\n");
    multiply(c_m1,c_m2);
    //printf("Addition of s_m1 and s_m2-\n");
    //printf("Transpose: \n");
    //int trans[c_m1[0][2]+1][3];
    //transpose(c_m1,trans);
    //add(c_m1,c_m2);
    return 0;
}
/////////////***********************************Functions****************************/////////////////////////////////////////
void add(int c_m1[][3],int c_m2[][3])
{
    int s1=(c_m1[0][2]);
    int s2=(c_m2[0][2]);
    int c_m[s1+s2+1][3];
    if((c_m1[0][0])!=(c_m2[0][0]) || (c_m1[0][1]) != (c_m2[0][1])){
        printf("Matrices have different dimensions, can't be added\n");
        exit(0);
    }
    else{
        c_m[0][0]=c_m1[0][0];c_m[0][1]=c_m1[0][1];
        int i=1,j=1,k=1;
        while(i<=s1 && j<=s2){
            if(c_m1[i][0] < c_m2[j][0]){
                c_m[k][0]=c_m1[i][0];
                c_m[k][1]=c_m1[i][1];
                c_m[k][2]=c_m1[i][2];
                i++;k++;
            }
            else if(c_m1[i][0] > c_m2[j][0]){
                c_m[k][0]=c_m2[j][0];
                c_m[k][1]=c_m2[j][1];
                c_m[k][2]=c_m2[j][2];
                k++;j++;
            }
            else if(c_m1[i][1] < c_m2[i][1]){
                c_m[k][0]=c_m1[i][0];
                c_m[k][1]=c_m1[i][1];
                c_m[k][2]=c_m1[i][2];
                i++;k++;
            }
            else if(c_m1[i][1]>c_m2[i][1]){
                c_m[k][0]=c_m2[j][0];
                c_m[k][1]=c_m2[j][1];
                c_m[k][2]=c_m2[j][2];
                k++;j++;
            }
            else{
                c_m[k][0]=c_m1[i][0];c_m[k][1]=c_m1[i][1];
                c_m[k][2]=c_m1[i][2] + c_m2[j][2];
                k++;i++;j++;
            }
        }
        while(i<=s1){
                c_m[k][0]=c_m1[i][0];
                c_m[k][1]=c_m1[i][1];
                c_m[k][2]=c_m1[i][2];
                i++;k++;
        }
        while(j<=s2){
                c_m[k][0]=c_m2[j][0];
                c_m[k][1]=c_m2[j][1];
                c_m[k][2]=c_m2[j][2];
                k++;j++;
        }
        c_m[0][2]=k-1;
        int z=c_m[0][2];
        for(int i=0;i<=z;i++){
            printf("%10d   %10d   %10d\n",(c_m[i][0]),(c_m[i][1]),(c_m[i][2]));
        }
    }
}
void transpose(int a[][3],int trans[][3])
{
    int size=a[0][2],k=1;
    //int trans[size+1][3];
    trans[0][0]=a[0][1];trans[0][1]=a[0][0];trans[0][2]=a[0][2];
    for(int i=0;i<a[0][1];i++){
        for(int j=1;j<=size;j++){
            if(a[j][1]==i){
                trans[k][0]=a[j][1];
                trans[k][1]=a[j][0];
                trans[k][2]=a[j][2];
                k++;
            }
        }
    }
    /*for(int i=0;i<=size;i++){
        for(int j=0;j<3;j++){
            printf("%4d ",trans[i][j]);
        }
        printf("\n");
    }*/
}
void multiply(int c1[][3] ,int c2[][3])
{
    if(c1[0][1] != c2[0][0]){
        printf("Matrices can't be multiplied!!\n");
        return;
    }
    int m[c1[0][2]+c2[0][2]+1][3];
    int c2_t[c2[0][2]+1][3];
    transpose(c2,c2_t);
    int rows1=c1[0][2];
    int rows2=c2[0][2];
    int i=1,i1,j,k=1,c1rn,c2cn,s=0;
    while(i<=rows1){
        i1=i;j=1;
        while(j<=rows2){
            c1rn=c1[i][0];
            c2cn=c2_t[j][0];
            s=0;
            while(i<=rows1 && j<=rows2 && c1rn==c1[i][0] && c2cn==c2_t[j][0]){
                if(c1[i][1]==c2_t[j][1]){
                    s+=c1[i][2]*c2_t[j][2];
                    i++;j++;
                }
                else if(c1[i][1]<c2_t[j][1])i++;
                else j++;
            }
            if(s!=0){
                m[k][0]=c1rn;
                m[k][1]=c2cn;
                m[k][2]=s;
                k++;
            }
            if(j<=rows2)i=i1;
            while(c2cn==c2_t[j][0] && j<=rows2)j++;
        }
        while(c1rn==c1[i][0] && i<=rows1)i++;
    }
    m[0][0]=c1[0][0];m[0][1]=c2_t[0][0];
    m[0][2]=k-1;
    for(int z=0;z<k;z++){
        for(int y=0;y<3;y++){
            printf("%2d  ",m[z][y]);
        }
        printf("\n");
    }
}

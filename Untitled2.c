#include<stdio.h>
#include<math.h>
float abslarg(float x1[],int n)
{
    int i;
    float largest=fabs(x1[0]);
    for(i=0; i<n; i++)
    {

        if(fabs(x1[i])>largest)
        {

            largest=fabs(x1[i]);

        }
    }
        return largest;

    }
    float error(float e[],int n)
    {

        float large=e[0];
        int i;
        for(i=0;i<n;i++)
{

    if(e[i]>large)
    {

        large=e[i];
    }

}
return large;
    }

int main()
{
    float emax,lamda;
    float a[10][10],tol,x0[10],x1[10],e[10];

        int n,i,j;


        printf("enter the order of matrix");
        scanf("%d",&n);

        printf("enter the elements of A");
        for(i=0;i<n;i++)
        {

            for(j=0; j<n;j++)
            {

             scanf("%f",&a[i][j]);


            }
        }
        printf("enter the intial eigen vector ");
    for(i=0;i<n;i++)
    {
        printf("X%d=",i);
        scanf("\n %f",&x0[i]);

    }
    printf("enter the tolerable error");
  scanf("%d",&tol);
  do{
printf("the value after calculations");
for(i=0;i<n;i++)
{ x1[i]=0;
    for(j=0;j<n;j++)
    {
x1[i]+=(a[i][j]*x0[j]);

    }

    printf("\n x[%d]=%f",i,x1[i]);


}

lamda=abslarg(x1,n);

printf("\n lamda=%f",lamda);
for(i=0;i<n;i++)
{

    x1[i]=x1[i]/lamda;
    e[i]=fabs(x1[i]-x0[i]);
    x0[i]=x1[i];

}

emax=error(e,n);
  }while(emax>tol);
printf("\n lamda =%f",lamda);
for(i=0;i<n; i++)
{

    printf("\nx[%d]=%f",i,x1[i]);

}

return 0;
}

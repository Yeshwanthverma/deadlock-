#include<stdio.h>
#include<conio.h>
int main()
{
int p[10],q[10],n,k,i,d=4;
int a[10],b[10],c[10],ra[10],rb[10],rc[10],needa[10],needb[10],needc[10];
int availa,availb,availc;
k=0;
printf("enter no of process\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter resource a allocation for process %d:",i+1);
scanf("%d",&a[i]);
printf("enter resource b allocation for process %d:",i+1);
scanf("%d",&b[i]);
printf("enter resource c allocation for process %d:",i+1);
scanf("%d",&c[i]);
p[i]=i;
}
for(i=0;i<n;i++)
{
printf("enter resource a request for process %d:",i+1);
scanf("%d",&ra[i]);
printf("enter resource b request for process %d:",i+1);
scanf("%d",&rb[i]);
printf("enter resource c request for process %d:",i+1);
scanf("%d",&rc[i]);
}
for(i=0;i<n;i++)
{
needa[i]=ra[i]-a[i];
needb[i]=rb[i]-b[i];
needc[i]=rc[i]-c[i];
}
printf("eneter resource a available\n");
scanf("%d",&availa);
printf("eneter resource a available\n");
scanf("%d",&availb);
printf("eneter resource a available\n");
scanf("%d",&availc);
printf("\n\nprocess\t\tallocation\t request\t\t  need table\n\n");
for(i=0;i<n;i++)
{
printf("%d\t\t%d %d %d\t\t   %d %d %d\t\t   %d %d %d\n",i,a[i],b[i],c[i],ra[i],rb[i],rc[i],needa[i],needb[i],needc[i]);
}
printf("\nworking table\n\n");
while(k<n && d>0)
{
for(i=0;i<n;i++)
{
 if(availa>=needa[i] && availb>=needb[i] && availc>=needc[i] && p[i]!=99)
 {
 q[k]=p[i];
 availa=availa+a[i];
 availb=availb+b[i];
 availc=availc+c[i];
 printf("%d  %d  %d\n",availa,availb,availc);
 k++;
 p[i]=99;
 }
 }
 d=d-1;;
 }
 if(k>0)
 {
 printf("\n\nsafe sequence\n");
 for(i=0;i<k;i++)
 printf("p%d-->",q[i]);
 }
 if(k==0 || k!=n)
 printf("deadlock\n");
getch();
}

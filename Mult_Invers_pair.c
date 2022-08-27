#include<stdio.h>
#include<math.h>
#define mod 17
int gcd(int a,int b);
int inverse(int n);
int main()
{
	int n;
for(n=1;n<mod;n++){
	if(gcd(n,mod)==1){
	  printf("\nInverse exist for %d.\t",n);
	  inverse(n);
    }
	else 
	  printf("\nInverse doesn't exist for %d.\t",n);}  	
}
int gcd(int a, int b)
{
   if(a==0)
      return b;
   else if(b==0)
      return a;
   else
      return gcd(b,a%b);   
}
int inverse(int n)
{   int i,q,r1=mod,r2=n,r,t1=0,t2=1,t;
    while(r2 != 0)
	{
	q=r1/r2;
	r=r1%r2;	
	t=t1-q*t2;
	
    r1=r2;
	r2=r; 
	t1=t2;
	t2=t;
    }    
if(t1>0){
     i=t1 % mod;
    printf("The inverve  of %d mod %d is : %d. So, (%d,%d) is a pair of Z%d.",n,mod,i,n,i,mod);
 }
else{ 
    while(t1<0)
    { int mulF=1;
      t1=t1 + mulF*mod;
      mulF++;
	}
	i=t1 % mod;
	printf("The inverve of %d mod %d is : %d. So, (%d,%d) is a pair of Z%d.",n,mod,i,n,i,mod);
   }
    			
}

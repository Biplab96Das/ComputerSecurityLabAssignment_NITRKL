#include<stdio.h>
int a=10,b=2,n=15,a1,b1,d,i,k;
int gcd(int a, int b)
{
   if(a==0)
      return b;
   else if(b==0)
      return a;
   else
      return gcd(b,a%b);   
}
int inverse(int a1)
{   int q,r1=n,r2=a1,r,s,s1,s2,t1=0,t2=1,t;
    while(r2 != 0)
	{
	q=r1/r2;
	r=r1%r2;	
	t=t1-q*t2;
	s=s1-q*s2;
	
    r1=r2;
	r2=r; 
	t1=t2;
	t2=t;
	s1=s2;
	s2=s;
	
	
    }
if(t1>0){
     i=t1 % n;
    printf(" The inverve of %d mod %d is : %d",a1,n,i);
 }
else{ 
    while(t1<0)
    { int mulF=1;
      t1=t1 + mulF*n;
      mulF++;
	}
	i=t1 % n;
	printf(" The inverve of %d mod %d is : %d\n",a1,n,i);
   }
    			
}
int main()
{   
d=gcd(a,n);
if(b%d!=0)
 printf("No solutions Exists");
else if(b%d==0)
{
	a1=a/d;b1=b/d;
	if(gcd(a1,n)==1){
	  printf("Inverse exist.");
	  inverse(a1);
	  printf("Particular Solution:-->X0=%d\n",(b1*i)%n);
	  printf("General Solution:-->X=%d",(b1*i)%n+(n/d));
    }
	else 
	  printf("Inverse doesn't exist."); 
 } 
return 0;
}

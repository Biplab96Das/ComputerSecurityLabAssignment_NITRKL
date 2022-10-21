#include<stdio.h>
#include<math.h>
int a=21,b=14,a1=0,b1=0,c=35,s,d,t,k;
int Extended_euclidean(int a1,int b1)
{   
  int r1,r2,r,q,s1,s2,t1,t2;
  r1=a1;r2=b1;
  s1=1;s2=0;
  t1=0;t2=1;
      while(r2 != 0)
	{
	q=r1/r2;
	
	r=r1-q*r2;
	r1=r2;
	r2=r;
		
	s=s1-q*s2;
	s1=s2;
	s2=s;
	
	t=t1-q*t2;
	t1=t2;
	t2=t;
	
	
    }
    s=s1,t=t1;
//printf("r1=%d,r2=%d,t1=%d,t2=%d,s1=%d,s2=%d\n",r1,r2,t1,t2,s1,s2);
return 0;
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
int particular_sol()
{   
	return 0;
}

int main()
{
   d=gcd(a,b);
   printf("d=%d\n",d);	
   if(c%d!=0)
      printf("No Solution Exists.\n");
   else if(c%d==0)
    {
      a1=a/d;b1=b/d;
      printf("a1=%d,b1=%d\n",a1,b1);
      Extended_euclidean(a1,b1);
	printf("Particular Solutions:--> X0=%d,Y0=%d\n",(c/d)*s,(c/d)*t);
	for(k=1;k<5;k++){

	  printf("General Solutions:-->for k=%d, X=%d,Y=%d\n",k,(c/d)*s+k*(b/d),(c/d)*t-k*(a/d));
}  
	}   
}

// 大小端判断

#include <stdio.h>
#include <iostream>
using namespace std;

int checkCPU()
{
  union w
   {
    int a;
    char b;
   }c;

   c.a = 1;
   
  return (c.b == 1);
}

int main(int argc,char *argv[])
{
  checkCPU()?printf("little-endian\n"):printf("Big-endian\n");
  
  char a = -4;
  number=abs(number);    //取绝对值
  int i=7;
  while(number!=0) //求出其绝对值原码
  {
      arr[i]=number%2;
      i--;
      number/=2;
  }
  for(i=7;i>=0;i--)
  {
      if(arr[i]==1)
      {
          int j;
          for(j=0;j<i;j++)    //取反 
            if(arr[j]==1)
                arr[j]=0;
            else
                rr[j]=1;
        break;
         }
    }
     for(i=0;i<=7;i++)
         printf("%d",arr[i]);    
     printf("\n");
    memset(arr,0,sizeof(arr));    //重置数组

}
#include<stdio.h>
int rect(int x,int y)
{
  int result;
  result=x*y;
  return result;
}
void main()
{
  int x=8,y=4;
  int a;
  a=rect(x,y);
  printf("8*4的面積是%d",a);
}
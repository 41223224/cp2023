#include<stdio.h>
float circle(int r);
void main()
{
  float answer;
  answer=circle(8);
  printf("圓周長度是%f",answer);
}
float circle(int r)
{
  float result;
  result=3.14159*2*r;
  return (result);
}
#include<stdio.h>
int main()
{
    int this_is_a_number1,this_is_a_number2,total;
    printf("Please enter an integer number:\n");
        scanf("%d",&this_is_a_number1);
        printf("You entered %d\n",this_is_a_number1);
        printf("Please enter another number:\n");
        scanf("%d",&this_is_a_number2);
        printf("You entered %d\n",this_is_a_number2);
        total=this_is_a_number1+this_is_a_number2;
        printf("total is %d\n",total);
        return 0;

}

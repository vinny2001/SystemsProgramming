#include<stdio.h>


int main()
{
    int input;
    printf("\nPlease input a numeric grade: ");

    if(scanf("%d",&input))
    {
        if(input >= 0 && input <=100)
        {
            if(input <=100 && input >=90)
            {
                printf("\nYour grade is an A\n");
            }else if(input <90 && input >=80)
            {
                printf("\nYour grade is a B\n");
            }else if(input <80 && input >=70)
            {
                printf("\nYour grade is a C\n");
            }else if(input <70 && input >=60)
            {
                printf("\nYour grade is a D\n");
            }else if(input <60 && input >=0)
                printf("\nYour grade is a F\n");
        }else
        {
            printf("\nYou entered an invalid value.\n");
        }

    }else{
        printf("\nYour input could not be interpreted as an integer value.\n");
    }
    return 0;
}
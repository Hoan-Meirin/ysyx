#include <stdio.h>

void printf_int_b(int x,char* s)				//正数二进制转换
{
	long long tmp = 1;
	s[32] = '\0';
	s[0] = '0';
	for(int i = 0; i < 32; i++)
	{
		if(tmp & x)
		s[31-i] = '1';
		else
		s[31-i] = '0';

		tmp = tmp << 1;
	}
}



int main(int argc, char *argv[])
{
    int distance = 100;
    float power = 2.345f;
    double super_power = 56789.4532;
    char initial = 'A';
    char first_name[] = "Zed";
    char last_name[] = "Shaw";
	char binary[33];
	printf_int_b(1,binary);

    printf("You are %d miles away.\n", distance);
    printf("You have %f levels of power.\n", power);
    printf("You have %f awesome super powers.\n", super_power);
    printf("I have an initial %c.\n", initial);
    printf("I have a first name %s.\n", first_name);
    printf("I have a last name %s.\n", last_name);
    printf("My whole name is %s %c. %s.\n",
            first_name, initial, last_name);
	printf("binary 1 in 32-bits: %s\n",binary);
	printf("lower case 11: %x\n",11);
	printf("upper case 11: %X\n",11);
	printf("%c",binary[31]);
    return 0;
}
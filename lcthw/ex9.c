#include <stdio.h>

int main(int argc, char *argv[])
{
    int numbers[4] = {0};
    char name[4] = {'a'};

    // first, print them out raw
    printf("numbers: %d %d %d %d\n",
            numbers[0], numbers[1],
            numbers[2], numbers[3]);

    printf("name each: %c %c %c %c\n",
            name[0], name[1],
            name[2], name[3]);

    printf("name: %s\n", name);

    // setup the numbers
    numbers[0] = 'a';
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;

    // setup the name
    name[0] = (char)90;
    name[1] = 'e';
    name[2] = 'd';
    name[3] = '\0';

    // then print them out initialized
    printf("numbers: %d %d %d %d\n",
            numbers[0], numbers[1],
            numbers[2], numbers[3]);

    printf("name each: %c %c %c %c\n",
            name[0], name[1],
            name[2], name[3]);

    // print the name like a string
    printf("name: %s\n", name);

    // another way to use name
    char *another = "Zed";

    printf("another: %s\n", another);

    printf("another each: %c %c %c %c\n",
            another[0], another[1],
            another[2], another[3]);

	printf("像数组一样使用name（name : 0,0,0,2)：\n");					//类似16进制转10进制
	char *p = name;
	name[3] = 2;
	name[2] = '\0';
	name[1] = '\0';
	name[0] = '\0';
	int a[2] = {0,0},index = 0;
	while(index != 5)
	{
		switch (index%4)
		{
		case 0: a[index/4] = a[index/4] + *p << 24;
			break;
		case 1: a[index/4] = a[index/4] + *p << 16;
			break;
		case 2: a[index/4] = a[index/4] + *p << 8;
			break;
		case 3: a[index/4] = a[index/4] + *p;
			break;
		default:
			break;
		}

		index++;
		p++;
	}
	printf("a[0] = %d\n",a[0]);
    return 0;
}

//诶卧槽Zed怎么这么坏
//居然让当时刚学几天的我改字符串常量
#include <stdio.h>

void p_1(int *p,char **q,int count);

int main(int argc, char *argv[])
{
    // create two arrays we care about
    int ages[] = {23, 43, 12, 89, 2};
    char *names[] = {
        "Alan", "Frank",
        "Mary", "John", "Lisa"
    };

    // safely get the size of ages
    int count = sizeof(ages) / sizeof(int);
    int i = 0;

    // first way using indexing
	int *p = ages;
	char **q = names;
    // for(i = 0; i < count; i++) {
    //     printf("%s has %d years alive.\n",
    //             *q++, *p++);
    // }
	p_1(p,q,count);

    printf("1 ---\n");

    // setup the pointers to the start of the arrays
    int *cur_age = ages;
    char **cur_name = names;

    // second way using pointers
    for(i = 0; i < count; i++) {
        printf("%s is %d years old.\n",
                *(cur_name+i), *(cur_age+i));
    }

    printf("---\n");

    // third way, pointers are just arrays
    for(i = 0; i < count; i++) {
        printf("%s is %d years old again.\n",
                cur_name[i], cur_age[i]);
    }

    printf("---\n");

    // fourth way with pointers in a stupid complex way
	cur_name = names, cur_age = ages;
    while((cur_age - ages) < count)
    {
        printf("%s lived %d years so far.\n",
                cur_name[0], cur_age[0]);
				cur_name++, cur_age++;
    }
printf("---\n");

	p = ages;
	q = names;
	for(i = 0; i < count; i++)
	{
		printf("%s is %d years old again.\nand the address is %p and %p\n",*q++,*p++,q-1,p-1);
	}
    return 0;
}

void p_1(int *p,char **q,int count)
{
	for(int i = 0; i < count; i++) {
        printf("%s has %d years alive.\n",
                *q++, *p++);
    }	
}

// 重复操作懒得写了
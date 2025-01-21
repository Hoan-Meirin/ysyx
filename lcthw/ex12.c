#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    if(argc == 2) {
        printf("You only have one argument. You suck.\n");
    } else if(argc > 2 && argc < 5) {
        printf("Here's your arguments:\n");

        for(i = 1; i < argc; i++) {
            printf("%s ", argv[i]);
			if (i == argc-1)
			{
				printf("\nIt will be finished immediately,but I break it first.");
			}
			
        }
        printf("\n");
    } else {
        printf("You have too many arguments. You suck.\n");
    }

    return 0;
}
//回去再来一遍还要git commit，就不回去了（
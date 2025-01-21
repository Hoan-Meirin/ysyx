#include <stdio.h>

int main(int argc, char *argv[])
{
	if(argc != 2) {
        printf("ERROR: You need one argument.\n");
        // this is how you abort a program
        return 1;
    }

    int i = 0;
    for(i = 0; argv[1][i] != '\0'; i++) {
        char letter = argv[1][i];

        switch(letter) {
            case 'a':
            case 'a'+32:
                printf("%d: 'A'\n", i);
                break;

            case 'e':
            case 'e'+32:
                printf("%d: 'E'\n", i);
                break;

            case 'i':
            case 'i'+32:
                printf("%d: 'I'\n", i);
                break;

            case 'o':
            case 'o'+32:
                printf("%d: 'O'\n", i);
                break;

            case 'u':
            case 'u'+32:
                printf("%d: 'U'\n", i);
                break;

            case 'y':
            case 'y'+32:
                if(i > 2) {
                    // it's only sometimes Y
                    printf("%d: 'Y'\n", i);
                }
                break;

            default:
                printf("%d: %c is not a vowel\n", i, letter);
        }
    }

    return 0;
}
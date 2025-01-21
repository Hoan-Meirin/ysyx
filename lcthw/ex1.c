#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    puts("Hello world.");
	fputs("Bad world\n",stdout);
	printf("bad word\n");
	fprintf(stdout,"bad world\n");
	dprintf(1,"bad apple\n");

    return 0;
}
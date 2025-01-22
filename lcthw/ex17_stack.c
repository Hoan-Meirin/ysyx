#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int push(int *sp, int** fp, int data)
{
	if(*fp - sp < 100*sizeof(int))
	{
		**fp = data;
		(*fp)++;
		return 0;
	}
	else
	{
		fprintf(stderr,"Stack overflow\n");
		return -1;
	}
	
}

int pop(int *sp, int **fp)
{
	if(*fp - sp > 0)
	{
		(*fp)--;
		return 0;
	}
	else
	{
		fprintf(stderr,"Stack underflow\n");
		return -1;
	}
}

int peek(int *sp, int *fp)
{
	if(fp - sp > 0)
	{
		return *(fp - 1);
	}
	else
	{
		fprintf(stderr,"Stack underflow\n");
		return -1;
	}
}

void close(int *stack)
{
	free(stack);
}
int main(int argc, char *argv[])
{
	int *stack;
	if(argc != 2)
	{
		fprintf(stderr,"Usage: %s <stack size>\n", argv[0]);
		return -1;
	}
	int n = atoi(argv[1]);
	stack = (int*)malloc(n*sizeof(int));
	int *sp = stack; // 栈指针
	int *fp = stack; // 帧指针

	char input;
	char input2[100];
	int data;
	int reg;
	printf("Enter 'p' <data> to push, 'o' to pop, 'e' to peek, other to quit: ");
	while ((input = fgetc(stdin)) != EOF)
	{
		if (input == '\n')
		{
			continue;
		}
		
		switch (input)
		{
		case 'p':
			if(fgets(input2,100,stdin) != NULL)
			{
				data = atoi(input2);
				if(push(sp, &fp, data)==-1)
				{
					break;
				}
				printf("Pushed %d\n", *(fp-1));
			}
			else
			{
				fprintf(stderr,"Invalid data\n");
				break;
			}

			break;
		case 'o':
			if(pop(sp, &fp)==-1)
			{
				break;
			}
			else
			{
				printf("Popped %d\n", *(fp));
				break;
			}
			
		case 'e':
			reg = peek(sp, fp);
			if(reg != -1)
			{
				printf("Peeked %d\n", reg);
			break;
			}
			else
			break;

		default:
		printf("you quit\n");
			close(stack);
			return 0;
		}
	}
	fprintf(stdout,"You quit\n");
	close(stack);
}
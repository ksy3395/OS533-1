#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
unsigned char* stack_pointer;
void* initial_argument;
void (*initial_function) (void*);
} thread;

long power (int,int);
void fun_with_threads();

void thread_start(struct thread * old, struct thread * new)
{
	printf("hello");
}

static const int STACK_SIZE = 1024*1024;
thread* current_thread -> stack_pointer = malloc (STACK_SIZE) + STACK_SIZE; 

int main(){
printf("hp");


int *p = malloc(sizeof(int));
*p = 5;

current_thread -> initial_argument = p;
printf("hello");
current_thread -> initial_function = fun_with_threads;
current_thread -> initial_function (current_thread->initial_argument);

free (p);
free (stack_pointer);
return 0;
}

long power (int num, int pow)
{
	if (pow)
	{
		return (num * power(num, pow-1));
	}
	return 1;
}

void fun_with_threads(void* arg){
long n = *(long*) arg;
printf("pow(%ld) = %ld\n", n, power(n,10));
}



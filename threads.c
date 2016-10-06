#include <stdio.h>
#include <string.h>
#include <stdlib.h>

public struct thread{
unsigned char* stack_pointer;
void* initial_argument;
void (*initial_function) (void*);
public thread() {

int *p = malloc(sizeof(int));
*p = 5;
	
this -> initial_argument = p;
this -> stack_pointer = malloc (STACK_SIZE) + STACK_SIZE;
printf("hello");
this -> initial_function = fun_with_threads;
this -> initial_function (current_thread->initial_argument);
}
}

long power (int,int);
void fun_with_threads();

void thread_switch(struct thread * old, struct thread * new)
{
	printf("hello");
}

static const int STACK_SIZE = 1024*1024;
thread* current_thread = new thread (); 

int main(){
printf("hp");


//free (p);
//free (stack_pointer);
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



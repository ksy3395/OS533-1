#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct thread{
unsigned char* stack_pointer;
void* initial_argument;
void (*initial_function) (void*);
};

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
printf("pow(%ld,10) = %ld\n", n, power(n,10));
}



void thread_start (struct thread * old, struct thread * new);
void thread_switch (struct thread * old, struct thread * new);

static const int STACK_SIZE = 1024*1024;
struct thread* current_thread;
struct thread* inactive_thread;

void yield() {
	printf("yield entered\n");
	struct thread * temp = current_thread;
	current_thread = inactive_thread;
        inactive_thread = temp;
	printf ("Calling thread_switch now\n");
	thread_switch (inactive_thread, current_thread);
}

void thread_wrap() {
	printf("thread_wrap entered\n");
	current_thread->initial_function(current_thread->initial_argument);
	yield();
}


int main(){
printf("Entered main\n");

int *p = malloc(sizeof(int));
*p = 5;

current_thread = (struct thread*) malloc(sizeof(struct thread));
inactive_thread = (struct thread*) malloc(sizeof(struct thread));

current_thread -> initial_argument = p;
current_thread -> stack_pointer = malloc (STACK_SIZE) + STACK_SIZE;
current_thread -> initial_function = fun_with_threads;
printf("current_thread initialized\n");
//current_thread -> initial_function (current_thread->initial_argument);

printf("Calling thread_start now...\n");
thread_start (inactive_thread, current_thread);
printf("Freeing memory...\n");
free (p);
free (inactive_thread);
free (current_thread);


return 0;
}

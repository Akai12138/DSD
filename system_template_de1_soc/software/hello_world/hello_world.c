/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */

#include <stdlib.h>
#include <sys/alt_stdio.h>
#include <sys/alt_alarm.h>
#include <sys/times.h>
#include <alt_types.h>
#include <system.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

// Test case 1
//#define step 5
//#define N 52

// Test case 2
 #define step 1/8.0
 #define N 2041

//Test case 3
//#define step 1/1024.0
//#define N 261121

// Generates the vector x and stores it in the memory
void generateVector(float x[N])
{
	int i;
	x[0] = 0;
	for (i=1;i<N;i++)
		x[i] = x[i-1] + step;

}

float sumVector(float x[], int M)
{
	float sum = 0.0;
	int i;
	for (i=0; i<=M; i++) {
		sum += x[i] + x[i] * x[i];
	}
	return sum;
}

int main()
{
	 printf("Task 2!\n");

	 // Define input vector
	 float x[N];

	 // Returned result
	 float y;
	 generateVector(x);

	 // The following is used for timing
//	 char buf[50];
//
//	 long total_ticks = 0;
//
//	 clock_t exec_t1, exec_t2;
//
//	 for (int i=0; i<10; i++){
//	 exec_t1 = times(NULL); // get system time before starting the process
	 char buf[40];
	 clock_t exec_t1, exec_t2;
	 exec_t1 = times(NULL); // get system time before starting the process

	 // The code that you want to time goes here
	 y = sumVector(x, N);
	 // till here
//	 exec_t2 = times(NULL); // get system time after finishing the process
//
//	 long duration = exec_t2 - exec_t1; // duration for this iteration
//
//	 total_ticks += duration; // add to total
//	 gcvt((exec_t2 - exec_t1), 10, buf);
//	 alt_putstr(" proc time = "); alt_putstr(buf); alt_putstr(" ticks \n");
//	 }
//
//	 long average_ticks = total_ticks / 10;
//	 gcvt(average_ticks, 10, buf);
//	 alt_putstr("Average proc time = "); alt_putstr(buf); alt_putstr(" ticks\n");
//
	 exec_t2 = times(NULL); // get system time after finishing the process
	 gcvt((exec_t2 - exec_t1), 10, buf);
	 alt_putstr(" proc time = "); alt_putstr(buf); alt_putstr(" ticks \n");

	 int i;
	 for (i=0; i<10; i++){
		 y = y/2.0;
	 }

	 printf("Result: %d \n",(int) y);

	 return 0;
}

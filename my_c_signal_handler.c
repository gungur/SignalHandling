////////////////////////////////////////////////////////////////////////////////
// Main File:        N/A
// This File:        my_c_signal_handler.c
// Other Files:      send_signal.c, my_div0_handler.c
// Semester:         CS 354 Lecture 002 Fall 2023
// Grade Group:      gg14
// Instructor:       deppeler
// 
// Author:           Sai Gungurthi
// Email:            sgungurthi@wisc.edu
// CS Login:         gungurthi
//
/////////////////////////// OTHER SOURCES OF HELP ////////////////////////////// 
// Persons:          Identify persons by name, relationship to you, and email.
//                   Describe in detail the the ideas and help they provided.
//                   N/A
//
// Online sources:   avoid web searches to solve your problems, but if you do
//                   search, be sure to include Web URLs and description of 
//                   of any information you find.
//                   N/A
// 
// AI chats:         save a transcript and submit with project.
//                   N/A
//////////////////////////// 80 columns wide ///////////////////////////////////


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int seconds = 5;

void handler_SIGALRM() {
	
	time_t curtime;
	time(&curtime);
	
	printf("PID: %i CURRENT TIME: %s", getpid(), ctime(&curtime));
	alarm(seconds);
}

int main() {

	printf("PID and time print every 5 seconds.\n");
	printf("Type Ctrl-C to end the program.\n");

	alarm(seconds);

	struct sigaction sa; // declare only once

	// reuse below block for each signal to handle
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = handler_SIGALRM;
	if (sigaction(SIGALRM, &sa, NULL) != 0) {
		printf("Error binding SIGALRM handler\n");
		exit(1);
	}

	while (1) {
		// infinite loop
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"

int main(int argc, char **argv) {
	// Load data from file and store in linked list
	Node * list = Load_From_File(argv[1]);

	// Sort the data
	list = Shell_Sort(list);	

	// Write the data from linked list to file
	int nels_w = Save_To_File(argv[2], list);
	printf("nels_w = %d\n", nels_w);

	// Deallocate list
	Node *temp;
	while (list != NULL) {
		temp = list;
		list = list -> next;
		free(temp);
	}

	return 0;
}

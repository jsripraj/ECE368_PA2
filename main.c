#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"

int main(int argc, char **argv) {
	// Load data from file and store in linked list
	Node * list = Load_From_File(argv[1]);

	Node * cur = list -> next;
	printf("\n\nInput Array:\n");
	while (cur != NULL) {
		printf("%ld\n", cur -> value);
		cur = cur -> next;
	}
	// DELETE
	// Print_Seq(list);

	// Sort the data
	list = Shell_Sort(list);	

	// Write the data from linked list to file
	int nels_w = Save_To_File(argv[2], list);

	printf("Elements written= %d\n", nels_w);
	cur = list -> next;
	printf("\n\nOutput Array:\n");
	while (cur != NULL) {
		printf("%ld\n", cur -> value);
		cur = cur -> next;
	}

	return 0;
}

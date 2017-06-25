#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"

int main(int argc, char **argv) {
	// Load long ints from file and store in linked list
	Node * head = Load_From_File(argv[1]);
	Node * cur = head;
	printf("\n\nInput Array:\n");
	while (cur != NULL) {
		printf("%ld\n", cur -> value);
		cur = cur -> next;
	}

	// Write long ints from linked list to file
	int nels_w = Save_To_File(argv[2], head);
	printf("Elements written= %d\n", nels_w);
	return 0;
}

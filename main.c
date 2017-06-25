#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"

int main(int argc, char **argv) {
	Node * head = Load_From_File(argv[1]);
	Node * cur = head;
	printf("\n\nInput Array:\n");
	while (cur != NULL) {
		printf("%ld\n", cur -> value);
		cur = cur -> next;
	}
	return 0;
}

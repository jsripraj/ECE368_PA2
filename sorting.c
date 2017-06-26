#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

// Helper function
// Returns pointer to linked list of backwards sequence
static Node *Get_Seq(Node *list, long *nels_list);

Node *Load_From_File(char *Filename) {
	FILE *fp = fopen(Filename, "r");
	// Determine how many longs are in file
	fseek(fp, 0, SEEK_END);
	int len = ftell(fp);
	int nels = len / sizeof(long);
	fseek(fp, 0, SEEK_SET);
	// Load elements into linked list
	// Create an auxiliary head node to make other functions work
	// ex. list -> auxiliary head node -> data node -> data node ->...
	Node *list = malloc(sizeof(Node));
	list -> next = malloc(sizeof(Node));
	Node *cur = list -> next;
	fread(&(cur -> value), sizeof(long), 1, fp);
	for (int i = 1; i < nels; i++) {
		cur -> next = malloc(sizeof(Node));
		cur = cur -> next;
		fread(&(cur -> value), sizeof(long), 1, fp);
		cur -> next = NULL;
	}
	fclose(fp);
	return list;
}

int Save_To_File(char *Filename, Node *list) {
	FILE *fp = fopen(Filename, "w");
	Node *cur = list -> next;
	int nels_written = 0;
	while (cur != NULL) {
		fwrite(&(cur -> value), sizeof(long), 1, fp);
		cur = cur -> next;
		nels_written++;
	}
	fclose(fp);
	return nels_written;
}

static Node *Get_Seq(Node *list, long *nels_list) {
	// Find number of elements in data list
	Node *cur = list -> next;
	while (cur != NULL) {
		cur = cur -> next;
		(*nels_list)++;
	}
	// Sequence is in reverse
	// Create an auxiliary head node
	// ex. seq -> auxiliary head node -> last value node ->...
	Node *seq = malloc(sizeof(Node));
	seq -> next = NULL;
	Node *new;
	int q = 0, row = 0, i = 0;
	long t1 = 1, t2 = 1;
	while (t1 * t2 < (*nels_list)) {
		// Assign number in sequence
		seq -> value = t1 * t2;
		// Create new node to "left" of previous (remember, it's in reverse)
		new = malloc(sizeof(Node));	
		new -> next = seq;
		seq = new;
		// Calculate the next number in the sequence
		q++; t1 /= 2; t2 *= 3;
		if (q > row || t1 * t2 >= (*nels_list)) {
			row++; q = 0; t1 = 1; t2 = 1;
			for (i = 0; i < row; i++) { t1 *= 2; }
		}
	}
	return seq;
}

void Print_Seq(Node *list) {
	long nels_list = 0;
	Node *seq = Get_Seq(list, &nels_list);
	Node *cur = seq -> next;
	printf("\n\nSequence\n");
	while (cur != NULL) {
		printf("%ld\n", cur -> value);
		cur = cur -> next;
	}
}
/*
Node *Shell_Sort(Node *list);
*/

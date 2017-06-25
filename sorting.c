#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

// Helper function
// 
// Returns

Node *Load_From_File(char *Filename) {
	FILE *fp = fopen(Filename, "r");
	// Determine how many longs are in file
	fseek(fp, 0, SEEK_END);
	int len = ftell(fp);
	int nels = len / sizeof(long);
	fseek(fp, 0, SEEK_SET);
	// Load elements into linked list
	Node *head = malloc(sizeof(Node));
	fread(&(head -> value), sizeof(long), 1, fp);
	Node *cur = head;
	for (int i = 1; i < nels; i++) {
		cur -> next = malloc(sizeof(Node));
		cur = cur -> next;
		fread(&(cur -> value), sizeof(long), 1, fp);
		cur -> next = NULL;
	}
	fclose(fp);
	return head;
}

int Save_To_File(char *Filename, Node *list) {
	FILE *fp = fopen(Filename, "w");
	Node *cur = list;
	int nels_written = 0;
	while (cur != NULL) {
		fwrite(&(cur -> value), sizeof(long), 1, fp);
		cur = cur -> next;
		nels_written++;
	}
	return nels_written;
}
/*
Node *Shell_Sort(Node *list);
*/

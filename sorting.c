#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

// Helper function
// Returns pointer to linked list of backwards sequence
// static Node *Get_Seq(Node *list);

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
/*
static Node *Get_Seq(Node *list) {
	
}

Node *Shell_Sort(Node *list);
*/

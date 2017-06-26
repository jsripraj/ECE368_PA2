// Used to implement linked list of long integers
typedef struct Node {
	long value;
	struct Node *next;
} Node;

// Can be used to hold lists of lists
typedef struct List {
	Node *node;
	struct List *next;
} List;

// Reads all longs from a file and stores in linked list
// Returns pointer to first node
Node *Load_From_File(char *Filename);

// Writes all longs in a linked list to a file
// Returns number of ints successfully written
int Save_To_File(char *Filename, Node *list);

// Takes in a linked list of longs and sorts them by manipulating next pointers
// Returns pointer to first node in sorted list
Node *Shell_Sort(Node *list);

// DELETE DELETE DELETE //
// Debugging function, prints out sequence
void Print_Seq(Node *list);

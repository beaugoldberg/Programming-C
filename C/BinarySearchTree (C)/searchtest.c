#include "node.h"
#include "binarytree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, int argv1) {
	binary_tree bt;
	initialize(&bt);

	if (argv1 == 0) {
		insert(&bt,35);
		checkinsert(&bt,35);
	}
	else if (argv1 == 1) {
		insert(&bt,35);
		if (search(&bt,35) == true) {
			return 0;
		}
		else {
			return -1;
		}
	}	
}

// dynmem.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h" built with VS 

#include <stdio.h>
#include <stdlib.h>


int main()
{
	printf("Hello, World! %d\n", sizeof(int)); 
	int entriesSize = 1;
	int *entries = (int *) malloc(sizeof(int) * entriesSize);
	int count = 0;
	for (count = 0;; count++) {
		if (count == entriesSize) {
			int newEntrySize = entriesSize + 1;
			int *newEntries = (int *) malloc(sizeof(int) * newEntrySize);
			for (int i = 0; i < entriesSize; i++) {
				newEntries[i] = entries[i];
			}
			free(entries);
			entries = newEntries;
			entriesSize = newEntrySize;
		}

		printf("Enter a number: ");
		int num;
		scanf_s("%d", &num);
		if (num == 0) {
			break;
		}
		entries[count] = num;
	}

	printf("The Input in the string is:\n");

	for (int i = 0; i < count; i++ ) {
		printf("memaddress %p\n", &entries[i]);
		printf("%d, ", entries[i]);
	}

	free(entries);

	getchar(); getchar();
    return 0;
}


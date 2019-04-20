#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dictionary.h"

void print_list(VNode *head){
        VNode *cur = head;
        while(cur){
                printf("%s ", cur->value);
                cur = cur->next;
        }
        printf("\n");
}

int compare(const void * a, const void * b){
	char x = *(const char *) a;
	char y = *(const char *) b;
	return x - y;
}

int main(int argc, char** argv){
	static DNode* dictionary [DEFAULT_HASH_SIZE];
	
	//read file, copy strings, sort, add sorted (sorted = key, non sorted = value)
	
	FILE* f = fopen("words.txt", "r");
	char word[100];
	char word_sorted[100];
	while(fscanf(f, "%s", word) != EOF){
		strcpy(word_sorted, word);
		qsort(word_sorted, strlen(word_sorted), 1, compare);
		set(dictionary, DEFAULT_HASH_SIZE, word_sorted, word);
	}
	fclose(f);
	//printf("here\n");
	int total = 0;
	
	//print dictionary
	for(int i = 0; i < DEFAULT_HASH_SIZE; i++){
		DNode * head = dictionary[i];
		DNode * curr = head;
		while(curr){
			if(curr->values->next == NULL) {
				curr = curr->next;
			}
			else{
				total++;
				print_list(curr->values);
				curr = curr->next;
			}
		}
	}
	
	//print total number of anagrams
	printf("TOTAL NUMBER OF ANAGRAMS: %d\n", total);

/*        set(dictionary, DEFAULT_HASH_SIZE, "pore", "repo");
        set(dictionary, DEFAULT_HASH_SIZE, "pore", "rope");


        result = get (dictionary, DEFAULT_HASH_SIZE, "pore");
        if (result != NULL) {
                printf("Anagrams for 'pore':\n");
                print_list (result->values);
        }
        else
                printf ("'pore' not found\n");

        set(dictionary, DEFAULT_HASH_SIZE, "bore", "robe");
        result = get (dictionary, DEFAULT_HASH_SIZE, "bore");
        if (result != NULL) {
                printf("Anagrams for 'bore':\n");
                print_list (result->values);
        }
        else
                printf ("'bore' not found\n");*/

        free_dictionary(dictionary, DEFAULT_HASH_SIZE);


        return 0;
}

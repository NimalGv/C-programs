#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

struct node{
	int data;
	struct node *nxt;
};
typedef struct node node;

struct seqlist{
	node* point;
};
typedef struct seqlist seqlist;

node* create(int value){
	node* newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=value;
	newnode->nxt=NULL;
	return newnode;
}

int* dynamicArray(int n, int rows, int columns, int** queries, int* result_count) {
    node *temp, *prev;
    int ans=0, pos, size=0, k;
	seqlist seq[n];
	for(int i=0; i<rows; i++){
		if(queries[i][0]==2)
			size++;
	}
	int* result=(int*)malloc(size*sizeof(int));
	*result_count=size;
	int r=0;
	for(int i=0; i<n; seq[i].point=NULL, i++);
	
	for(int i=0; i<rows; i++){
		pos=(queries[i][1]^ans)%n;
		if(queries[i][0]==1){
			if(seq[pos].point==NULL){
				seq[pos].point=create(queries[i][2]);
			}else{
				for(temp=seq[pos].point; temp!=NULL; prev=temp, temp=temp->nxt);
				prev->nxt=create(queries[i][2]);
			}
		}else{
			for(temp=seq[pos].point, k=0; k<=queries[i][2]; prev=temp, temp=temp->nxt, k++);
				result[r++]=prev->data;
				ans=prev->data;
		}
		
	}
	
	/*printf("%d ", prev->data);
	for(int i=0; i<n;printf("\n"), i++)
	for(temp=seq[i].point; temp!=NULL; printf("%d ", temp->data), temp=temp->nxt);*/
	return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** nq = split_string(rtrim(readline()));

    char* n_endptr;
    char* n_str = nq[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* q_endptr;
    char* q_str = nq[1];
    int q = strtol(q_str, &q_endptr, 10);

    if (q_endptr == q_str || *q_endptr != '\0') { exit(EXIT_FAILURE); }

    int** queries = malloc(q * sizeof(int*));

    for (int i = 0; i < q; i++) {
        *(queries + i) = malloc(3 * (sizeof(int)));

        char** queries_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < 3; j++) {
            char* queries_item_endptr;
            char* queries_item_str = *(queries_item_temp + j);
            int queries_item = strtol(queries_item_str, &queries_item_endptr, 10);

            if (queries_item_endptr == queries_item_str || *queries_item_endptr != '\0') { exit(EXIT_FAILURE); }

            *(*(queries + i) + j) = queries_item;
        }
    }

    int queries_rows = q;
    int queries_columns = 3;

    int result_count;
    int* result = dynamicArray(n, queries_rows, queries_columns, queries, &result_count);

    for (int i = 0; i < 2; i++) {
        printf("%d\n", result[i]);
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}


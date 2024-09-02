#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 50
#define MAX 1000

char* get_text () {
	int line;
	char lines[MAX_LINE][MAX];
	char doc[MAX_LINE * MAX] = "";
	printf("Enter No.of Lines : ");
	scanf("%d",&line);
	getchar();
	printf("Enter the lines of strings: ");
	for (int i = 0; i < line; i++) {
		//scanf(" %[^\n]%*c", lines[i]);
		fgets(lines[i], MAX, stdin);
		if (i == line-1) {
		     int len = strlen(lines[i]);
		     printf("len : %d\n",len);
		     lines[i][len-1] = '\0';
		}
		strcat(doc,lines[i]);
	}

	char* text = (char*) malloc((strlen(doc)+1) * sizeof(char));
	strcpy(text,doc);

	return text;
}
int main () {
	char *text = get_text();
	printf("%s\n",text);


	return 0;
}

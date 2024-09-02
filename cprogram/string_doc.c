#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k-1];
}

char**** get_document(char* text) {
    // Allocate memory for paragraphs
    char**** document = malloc(MAX_PARAGRAPHS * sizeof(char***));
    int paragraph_index = 0;

    char* paragraph = strtok(text, "\n");
    while (paragraph != NULL) {
        // Allocate memory for sentences in the paragraph
        document[paragraph_index] = malloc(MAX_CHARACTERS * sizeof(char**));
        int sentence_index = 0;

        char* sentence = strtok(paragraph, ".");
        while (sentence != NULL) {
            // Allocate memory for words in the sentence
            document[paragraph_index][sentence_index] = malloc(MAX_CHARACTERS * sizeof(char*));
            int word_index = 0;

            char* word = strtok(sentence, " ");
            while (word != NULL) {
                // Allocate memory for the word and copy it
                document[paragraph_index][sentence_index][word_index] = malloc((strlen(word) + 1) * sizeof(char));
                strcpy(document[paragraph_index][sentence_index][word_index], word);
                word_index++;
                word = strtok(NULL, " ");
            }
            // Null terminate the words array
            document[paragraph_index][sentence_index][word_index] = NULL;
            sentence_index++;
            sentence = strtok(NULL, ".");
        }
        // Null terminate the sentences array
        document[paragraph_index][sentence_index] = NULL;
        paragraph_index++;
        paragraph = strtok(NULL, "\n");
    }
    // Null terminate the paragraphs array
    document[paragraph_index] = NULL;
    return document;
}

char* get_input_text() {    
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen(doc) + 1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count = 0;
    while (sentence[word_count] != NULL) {
        word_count++;
    }
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if (i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count = 0;
    while (paragraph[sentence_count] != NULL) {
        sentence_count++;
    }
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(paragraph[i]);
        printf(".");
    }
}

int main() {
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3) {
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        } else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        } else {
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }
    return 0;
}


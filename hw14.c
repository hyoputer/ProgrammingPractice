#include<stdio.h>
#include<stdlib.h>

typedef struct word {
	char abc[26];
	char word[50];
} word;

/*void input(word *p, FILE *fp) {
	word *tmp = (word*)malloc(sizeof(word));
	int i = 0;
	char apb;
	if(fscanf(fp, "%s", tmp -> word) == EOF)
		return;
	else
		tmp -> abc = {};
		tmp -> next = NULL;
		p -> next = tmp;
		while((abp = tmp -> word[i]) != '\0')
			tmp -> abc[abp - 'a'] += 1;
		input(p -> next, fp)
}

void compare(word *p1, word *p2) {
	int i, f = 0;
	for(i = 0; i < 26; i++) {
		if((p1 -> next) -> abc[i] != ((p2 -> next) -> abc[i]) {
			f = 0;
			break;
		}
		f = 1;
	}
	if(f == 0 && ((p2 -> next) -> next != NULL))
		compare(p1, p2 -> next);
	else if(f == 0 &&((p2 -> next) -> next == NULL))
		printf("\"%s\" is not an anagram of words in file\n", (p1 -> next) -> word);
		
	else if(f == 1)*/

int input(word *wrd, FILE *fp) {
	int i = 0, j = 0;
	while((fscanf(fp, "%s", wrd[i].word)) != EOF) {
		while(wrd[i].word[j] >= 'a' && wrd[i].word[j] <= 'z')
			wrd[i].abc[wrd[i].word[j++] - 'a'] += 1;
		i++;
		j = 0;
	}
	return i;
}

int compare(word ipt, word cmp) {
	int i;
	for(i = 0; i < 26; i++) {
		if(ipt.abc[i] != cmp.abc[i])
			return -1;
	}
	return 0;
}

int main() {
	FILE *ifp, *ofp, *cfp;
	ifp = fopen("input.txt", "r");
	ofp = fopen("output.txt", "w");
	cfp = fopen("words.txt", "r");
	word ipt[50] = {}, cmp[50] = {};
	int n1, n2, i, j, f;

	n1 = input(ipt, ifp);
	n2 = input(cmp, cfp);
	
	for(i = 0; i < n1; i++) {
		f = 0;
		for(j = 0; j < n2; j++) {
			f = compare(ipt[i], cmp[j]);
			if(f == 0) {
				fprintf(ofp, "\"%s\" is an anagram of \"%s\"\n", ipt[i].word, cmp[j].word);
				break;
			}
		}
		if(f == -1)
			fprintf(ofp, "\"%s\" is not an anagram of words in file\n", ipt[i].word);
	}
	
	fclose(ifp);
	fclose(ofp);
	fclose(cfp);
	
	return 0;
}

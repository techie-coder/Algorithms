#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **x, char **y){
    char *temp = *y;
    *y = *x;
    *x = temp;
}

void permute(char **s, int start, int end){
    if(start == end){
        for(int i=0;i<=end;i++){
            printf("%s ",s[i]);
        }
        printf("\n");
    }
    else{
        for(int i=start;i<=end;i++){
            swap(&s[start],&s[i]);
            permute(s,start+1,end);
            swap(&s[start],&s[i]);
        }
    }
}

int main(){
    char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
    permute(s,0,n-1);

    for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
    return 0;


}
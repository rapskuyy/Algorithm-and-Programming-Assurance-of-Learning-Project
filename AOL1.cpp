#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	
	char string[101];
	int length;
	
	printf("Input your string: ");
	scanf("%s", string); getchar();
	
	length = strlen(string);
	
	printf("Your string in reverse: ");
	for(int i = length - 1; i >= 0; i--){
		printf("%c", string[i]);
	}
	printf("\n");
	
	printf("Your string in inverse: ");
	for(int i = length - 1; i >= 0; i--){
		if(isupper(string[i]) != 0){
			printf("%c", tolower(string[i]));
		}
		else if(islower(string[i]) != 0){
			printf("%c", toupper(string[i]));
		}
	}
	printf("\n");
		
	return 0;
}

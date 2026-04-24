#include <stdio.h>
#include <string.h>

int main(){
	int tc;
	scanf("%d", &tc); getchar();
	
	for(int j = 0; j < tc; j++){
		char str[10000];
		scanf("%s", str); getchar();
		
		int len = strlen(str);
		int flag = 1;
		
		for(int i = 0; i < len;i++){
			if(str[i] == 'a' || str[i] == 'i' || str[i] == 'u' || str[i] == 'e' || str[i] == 'o'){
				if(i+2 < len && str[i+1] == 'g' && str[i+2] == str[i]){
					i+=2;
				}
				else {
					flag = 0;
					break;
				}
			}
		}
		
		if(flag) printf("Begenagar\n");
		else printf("Sagalagah\n");
	}
	
	
	return 0;
}

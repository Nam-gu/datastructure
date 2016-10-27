/**
	트리 
*/

#include <stdio.h> 

#define MAX 15
#define HEIGHT 5

int arrayTree[MAX];
int lastNode = 0;

void insertTree(int *arr, int data){
	if(lastNode == MAX){
		printf("tree is already full\n");
		return;
	} else{
		if(search(arr, data) == 1){
			printf("%c is arleady exist\n", data);
		}else{
			if(arr[lastNode] == 0) arr[lastNode++] = data;
			printf("insert %c\n", data);
		}
	}
	
}

int search(int *arr, int data){
	int i;
	for(i=0;i<=lastNode;i++){
		if(arr[i]==data) return 1;
	}
	return 0;
}

void deleteTree(int *arr, int data){
	if(lastNode == 0){
		printf("tree is empty!!\n");
		return;
	}
	int i, pos, flag = 0;
	for(i =0;i<=lastNode;i++){
		if(arr[i] == data){
			flag = 1;
			printf("%c is deleted", data);
		}
		if(flag == 1 && i+1 < MAX){
			arr[i] = arr[i+1];
		}
	}
}

void show(int *arr){
	int i=0, j=2, k, h = 0;;
	for(i = 0 ; i <= lastNode;i++){
		if(i == j/2-1){ //앞부분 공백 
			for(k=0;k<HEIGHT-h;k++) {
				printf("  ");
			}
		}
		printf(" %c ", arr[i]); //아이템 출력 
		h++; 
		if(i==j-2) { // 맨뒤에서는 줄바꿈 
			printf("\n\n", j);
			j *=2;	
		}
	}	
}

int height(int *arr){
	int square = 1;
	int height = 1;
	while(lastNode > square){
		height++;
		square *= 2;
	}
	return height;
}

int count(int *arr){
	return lastNode+1;
}


int main(){
	char input1, input2; //입력 
	int i;
	for(i=0; i<MAX;i++) arrayTree[i] = 0; // 스택배열 초기화 
	
	printf("***********Command***********\n");
  	printf("+<c> : insert <c>, -<c> : delete <c>\n");
   	printf("?<c> : search <c>, H : show tree height, C: count tree nodes, Q: Quit\n");
   	printf("*****************************\n");
	
	while (1) {
      printf("\nCommand> ");
      input1 = getchar();
      input1 = toupper(input1);
  		 switch (input1) {
     		case '+':
      		   	input2 = getchar();
     		    insertTree(arrayTree, input2);
    		    break;
    		    
 		    case '-':
 		    	input2 = getchar();
 		      	deleteTree(arrayTree, input2);
  		       	break;
  		       	
 		    case '?':
  		        input2 = getchar();
  		        search(arrayTree, input2);
  		       break; 
				  	
			case 'C':
				printf("The tree has %d items!!\n", count(arrayTree));
			  	break;  
				  		     	
			case 'H':
				printf("tree's height is %d", height(arrayTree));
				break;
		
			case 'S':
				show(arrayTree);
				break;
				
  		    case 'Q':
  		        printf("\n");
  		        exit(1);
  		        break;
  		     default: 
			   printf("올바른 명령어가 아닙니다.");
			   break;
    		  }
   		   while(input1 != EOF && input1 !='\n'){
    		     input1 = getchar();
  		 }
	}	 
	return 0;
}

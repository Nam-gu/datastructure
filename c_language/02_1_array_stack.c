#include <stdio.h>
#include <stdlib.h>

#define Data char //데이터 만들기 
#define MAX 100 //배열의 크기를 선언
#define START 1 // 인덱스를 정의한다  

char arrayStack[MAX]; //배열스택 전역변수로 선언 
int rear = 0; //초기 스택의 마지막은 0이라고 초기화
//알아보기 쉽도록 arrayStack[0] 인덱스는 비워두고 [1]인덱스부터 채울 것이다. 

//push : 데이터 입력 
void push(Data data){
	if(rear == MAX-1){ //MAX가 100인데 배열의 끝은 [99] 인덱스이므로 
		printf("stack is already full!!\n");
		return;
	}
	//-1부터 시작하므로 ++ 연산을 먼저하고 데이터를 넣는다. 
	arrayStack[++rear] = data; // 가장 마지막을 가리키는 rear의 위치에 데이터 입력 
	printf("push %c\n", data);
	printf("rear = %d\n", rear);
} 

//pop : 데이터 출력 
void pop(){
	if(rear == 0){
		printf("stack is empty!!\n");
		return;
	}
	printf("pop stack : %c\n", arrayStack[rear--]); //데이터 출력하고 끝을 앞으로 당김
	printf("rear = %d\n", rear);
}

//search : 데이터 검색(스택의 몇번째에 있는지 검색) 
void search(Data data){
	int i, j = 0;
	
	for(i = START;i<=rear;i++){
		if(arrayStack[i] == data) {
			printf("%c is in %d\n", arrayStack[i], i);	
			j = 1;
		}
	}
	if(j != 1) { //다 돌았는데 못찾는 경우 
		printf("%c doesn't exist\n", data);
	} 
}

//show : 스택에 차있는 데이터를 순서대로 출력
void show(){
	int i;
	for(i=START;i<=rear;i++){
		printf("%c  ", arrayStack[i]);
	}
	printf("\n");
} 

//count : 데이터 갯수 출력
void count(){
	printf("the number of stack is %d\n", rear);
} 

void main() {
	char input1, input2; //입력 
	int i;
	for(i=0; i<MAX;i++) arrayStack[i] = 0; // 스택배열 초기화 
	
	printf("***********Command***********\n");
  	printf("+<c> : push <c>, P : pop, S : show all stack\n");
   	printf("?<c> : search <c>, C : count stack, Q: Quit\n");
   	printf("*****************************\n");
	
	while (1) {
      printf("\nCommand> ");
      input1 = getchar();
      input1 = toupper(input1);
  		 switch (input1) {
     		case '+':
      		   	input2 = getchar();
     		    push(input2);
    		    break;
    		    
 		    case 'P':
 		      	pop();
  		       	break;
  		       	
 		    case '?':
  		        input2 = getchar();
  		        search(input2);
  		       break;
  		     	
  		    case 'S':
  		    	show();
			  	break;  
				  	
			case 'C':
  		    	count();
			  	break;  
				  		     	
  		    case 'Q':
  		        printf("\n");
  		        exit(1);
  		        break;
  		     default: break;
    		  }
   		   while(input1 != EOF && input1 !='\n'){
    		     input1 = getchar();
  		 }
	}
	
}

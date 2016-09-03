#include <stdio.h>
#include <stdlib.h>


#define Data char //데이터 만들기 
#define MAX 10 //배열의 크기를 선언
#define START 1 // 인덱스를 정의한다  

 
char arrayQueue[MAX]; //배열스택 전역변수로 선언 
int rear = 0; //큐의 뒤  
int front = 0; //큐의 앞  
//원형 큐는 순환해야하므로 모든 배열을 다 채워서 사용한다. 

//push : 데이터 입력 
//데이터가 들어오면,  rear 증가 
void push(Data data){
	if(rear%MAX == (front%MAX)-1){ // 꽉차있으면 front-1 = rear 
		printf("Queue is already full!!\n"); 
			
	} else{ // 꽉차있지 않으면,  
		arrayQueue[rear%MAX] = data; // 가장 마지막을 가리키는 rear의 위치에 데이터 입력 
		rear++; // rear 증가 
		printf("push %c\n", data);
	}
	printPoint();
} 

//pop : 데이터 출력 front 증가 
void pop(){
	if(front%MAX == rear%MAX) {
		printf("Stack is empty!!\n");
		return; // 비어있으면 종료 
	}	
	
	//데이터를 출력하고 front 증가 
	printf("pop : %c\n", arrayQueue[front++]); 
	arrayQueue[front-1] = '.'; // 값 초기화 
	printPoint();
}


//search : 데이터 검색(스택의 몇번째에 있는지 검색) 
void search(Data data){
	int i, j = 0;
	
	for(i = front;i<=rear;i++){
		if(arrayQueue[i] == data) {
			printf("%c is in %d\n", arrayQueue[i], i);	
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
	for(i=front;i<=rear;i++){
		printf("%c  ", arrayQueue[i%MAX]);
	}
	printf("\n");
	printPoint();
} 

//count : 데이터 갯수 출력
void count(){
	printf("the number of Queue is %d\n", rear-front+1);
} 


void printPoint(){
	printf("front = %d\n", front%MAX);
	printf("rear = %d\n", rear%MAX);
}

void main() {
	char input1, input2; //입력 
	int i;
	for(i=0; i<MAX;i++) arrayQueue[i] = 0; // 스택배열 초기화 
	
	printf("***********Command***********\n");
  	printf("+<c> : push <c>, P : pop, S : show all queue\n");
   	printf("?<c> : search <c>, C : count queue, Q: Quit\n");
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

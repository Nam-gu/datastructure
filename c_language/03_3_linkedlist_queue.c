#include <stdio.h>
#include <stdlib.h>

//나만의 약속 선언  
#define Data char

//구조체 
typedef struct Node{
	Data data; //Data 는 char 데이터형 
	struct Node *L_link;
	struct Node *R_link;
}Node;

//맨 마지막 노드 검색
Node* finalNode(Node *s){
	while(s->R_link != NULL){
		s = s->R_link;
	}
	return s;
}

//맨끝에 노드 생성 
Node* createNode(Node *s/*맨끝 노드*/, Data e/*데이터*/){
	Node *p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->L_link = s;
	p->R_link = NULL;
	s->R_link = p;
	printf("push %c\n", e);
	return p;
}

//push : 데이터 입력 
void push(Node *s, Data e){
	Node *p = finalNode(s); // 맨마지막 노드 검색 
	p = createNode(p, e); //노드생성 
}

//pop : 데이터 추출, 가장 앞에 있는 노드사용 
void pop(Node *s){
	if(s->R_link == NULL) { // 비어있을 경우 
		printf("queue is empty!!\n");
		return;
	}
	Node *p = s->R_link; //제일 처음 노드
	
	printf("pop : %c\n",p->data); //데이터 출력
	
	if(p->R_link != NULL) p->R_link->L_link = p->L_link; //가장 앞의 노드 앞에 있는 노드의 왼쪽 주소를 초기노드로 바꿔줌 
	s->R_link = p->R_link; //가장 앞의 노드주소를 입력
	//주소만 바꿔주고 노드 삭제하면 된다. 
	if(p->R_link == NULL) printf("Now, queue is empty!\n");
	free(p); // 노드 삭제 
} 

//search : 데이터 검색
void search(Node *s, Data e){
	Node *p = s;
	
	if(s->R_link == NULL) {
		isListEmpty(s);
		return;
	}
	
	int cnt = 0; // 몇번째 노드인지 세자 
	int find = 0; // 검색 성공 여부 | 0 : 실패 | 1: 성공 |  
	isListEmpty(s);
	while(p != NULL){ //끝이 없을때까지 탐색 
		if(p->data == e){
			find = 1;
			printf("%c is in node%d\n", p->data, cnt);  //여기에 있음! 
			break; //반복문 파괴 
		}
		p = p->R_link;
		cnt++; // 숫자 증가 
	}
	if(find != 1) printf("there is no %c\n", e);
}

//노드갯수 구하기
void count(Node *s){
	Node *p = s;
	int cnt = 0; // 몇번째 노드인지 카운트  
	isListEmpty(s);
	
	while(p->R_link != NULL){ //끝이 없을때까지 탐색 
		cnt++; // 숫자 증가 
		p = p->R_link;
	}
	
	printf("the number of node is %d\n", cnt);  //노드 갯수 출력 
} 

//스택 모두 출력 
void show(Node *s){
	int cnt=0;
	if(s->R_link == NULL) {
		isListEmpty(s);
		return;
	}
	while(s != NULL){
		if(cnt != 0) Print(s); //첫번째 노드는 안쓴다. 
		s = s->R_link;
		cnt++;
	} 
	printf("\n");
}

//스택 역순 출력 
void reverse(Node *s){
	if(s->R_link == NULL) {
		isListEmpty(s);
		return;
	}
	s = finalNode(s);
	int cnt=0;
	while(s->L_link != NULL){
		Print(s);
		s = s->L_link;
		cnt++;
	}
	printf("\n");
}  

//Print : 스택 내용 출력(배열과 동일하게 출력되도록)
void Print(Node *s){
	printf("%c ", s->data);
} 

//노드의 필드를 출력하는 메소드 
void printNode(Node *s){
	printf("data : %c | L-link : %p | R-link : %p |\n", 
	s->data, s->L_link, s->R_link);
}

//노드가 비어있으면 비었다고 알리는 메소드 
void isListEmpty(Node *s){
	if(s->R_link == NULL) printf("queue is empty!!\n");
}


void main() {
	char input1, input2; //입력 
	Node *s; //기본 시작점 
	s = (Node*)malloc(sizeof(Node)); // 노드 초기화
	s->data = '.'; // 초기화 데이터 
	s->L_link = NULL;
	s->R_link = NULL;
	
	printf("***********Command***********\n");
  	printf("+<c> : add <c>, P : pop, S : show all queue, R : show reverse queue\n");
   	printf("?<c> : search <c>, C : count node, Q: Quit\n");
   	printf("*****************************\n");
	
	while (1) {
      printf("\nCommand> ");
      input1 = getchar();
      input1 = toupper(input1);
  		 switch (input1) {
     		case '+':
      		   	input2 = getchar();
     		    push(s, input2);
    		    break;
    		    
 		    case 'P':
 		      	pop(s);
  		       	break;
  		       	
 		    case '?':
  		        input2 = getchar();
  		        search(s, input2);
  		       break;
  		       
  		    case 'C':
  		     	count(s);
  		     	break;
  		     	
  		    case 'S':
  		    	show(s);
			  	break;  
				  	
			case 'R':
  		    	reverse(s);
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

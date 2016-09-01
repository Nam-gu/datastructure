#include <stdio.h>
#include <stdlib.h>

//나만의 약속 선언 
#define Data char

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

//노드의 필드를 출력하는 메소드 
void printNode(Node *s){
	printf("data : %c | L-link : %p | R-link : %p |\n", 
	s->data, s->L_link, s->R_link);
}

//노드가 비어있으면 비었다고 알리는 메소드 
void isListEmpty(Node *s){
	if(s->R_link == NULL) printf("list is empty!!\n");
}


//노드 추가 
void addNode(Node *s, Data e){
	Node *p;
	s = finalNode(s); // 맨마지막 노드 검색 
	
	p =(Node*)malloc(sizeof(Node)); // 노드 크기만큼 동적할당
	p-> data  = e ; //가져온 데이터 입력
	p->L_link = s; //왼쪽 주소에는 마지막노드(지금노드)의 주소 입력 
	p->R_link = NULL; // 끝임을 표시 ,  오른쪽에 null입력 
	s->R_link = p;// 기존의 노드가 가리킨다고 표현 
	
	printf("new Node created!\n"); //만들어졌음 표시 
}

 //노드 삭제  데이터가 일치하는 노드 삭제 
void deleteNode(Node *s, Data e){
	Node *p = s;
	isListEmpty(s);
	while(p != NULL){ //끝이 없을때까지 탐색 
		if(p->data == e){
			if(p->R_link == NULL){ //마지막 노드의 경우 
				p->L_link->R_link = NULL; // 마지막만 지워버림 
			} else { //마지막이 아닌경우 
				p->R_link->L_link = p->L_link; //삭제할 노드가 가리키는 왼쪽을 오른쪽 노드의 L_link에 넣음
				p->L_link->R_link = p->R_link; //삭제할 노드가 가리키는 오른쪽을 왼쪽 노드의 R_link에 넣음 
			} 
			printf("%c is deleted\n", p->data); //삭제표시 
			free(p); // p노드 삭제 
			isListEmpty(s); //남은 노드가 없다면 비었다고 표시 
			break; //반복문 파괴 
		}
		p = p->R_link;
	}
	
} 

//노드 검색 
void searchNode(Node *s, Data e){
	Node *p = s;
	int cnt = 0, find=0; // 몇번째 노드인지 세자 
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
void countNode(Node *s){
	Node *p = s;
	int cnt = 0; // 몇번째 노드인지 카운트  
	isListEmpty(s);
	
	while(p->R_link != NULL){ //끝이 없을때까지 탐색 
		cnt++; // 숫자 증가 
		p = p->R_link;
	}
	
	printf("the number of node is %d", cnt);  //노드 갯수 출력 
} 

//모든 노드를 순서대로 출력하는 메소드   
void showNode(Node *s){
	int cnt=0;
	while(s != NULL){
		if(cnt != 0) printNode(s);
		s = s->R_link;
		cnt++;
	}  
}

//모든 노드들을 정반대로 출력하는 메소드  
void reverseNode(Node *s){
	s = finalNode(s);
	int cnt=0;
	while(s->L_link != NULL){
		printNode(s);
		s = s->L_link;
		cnt++;
	}
} 


void main() {
	char input1, input2; //입력 
	Node *s;
	s = (Node*)malloc(sizeof(Node)); // 노드 초기화
	s->data = '.'; // 초기화 데이터 
	s->L_link = NULL;
	s->R_link = NULL;
	
	printf("***********Command***********\n");
  	printf("+<c> : add <c>, -<c> : delete <c>,\n");
   	printf("?<c> : search <c>, C : count node, Q: Quit\n");
   	printf("*****************************\n");
	
	while (1) {
      printf("\nCommand> ");
      input1 = getchar();
      input1 = toupper(input1);
  		 switch (input1) {
     		case '+':
      		   	input2 = getchar();
     		    addNode(s, input2);
    		    break;
    		    
 		    case '-':
 		     	input2 = getchar();
 		      	deleteNode(s, input2);
  		       	break;
  		       	
 		    case '?':
  		        input2 = getchar();
  		        searchNode(s, input2);
  		       break;
  		       
  		    case 'C':
  		     	countNode(s);
  		     	break;
  		     	
  		    case 'S':
  		    	showNode(s);
			  	break;  
				  	
			case 'R':
  		    	reverseNode(s);
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

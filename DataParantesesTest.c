#include<stdio.h>
#include<string.h>
#define SIZE 50

typedef struct{
	char data[SIZE];
	int top;
}stack;

int isFullStk(stack *stk);
int isEmptyStk(stack *stk);
void initilizeStk(stack *stk);
void push(stack *stk,char takenData);
char pop(stack *stk);

int main(){
	char nameOfFile[30];
	char takenChar;
	int error=0;
	stack stk;
	initilizeStk(&stk);
	printf("Enter the name of .txt file that include your code.\n");
	fflush(stdin);
	gets(nameOfFile);
	strcat(nameOfFile,".txt");
	FILE *myfile=fopen(nameOfFile,"r");
	while(!feof(myfile)&&!error){
		takenChar=fgetc(myfile);
		if(takenChar=='('||takenChar=='{'||takenChar=='['){
			push(&stk,takenChar);
		}
		else if(takenChar==')'||takenChar=='}'||takenChar==']'){
			if(takenChar==')'&&pop(&stk)!='(')
				error=1;
			else if(takenChar=='}'&&pop(&stk)!='{')
    			error=1;
			else if(takenChar==']'&&pop(&stk)!='[')
    			error=1;
		}
	}
	if(!error&&pop(&stk)!='\0')
		error=1;
	if(error){
		printf("Error\n");
	}
	return 0;
}

int isFullStk(stack *stk){
	if(stk->top==SIZE-1)
		return 1;
	else
		return 0;
}

int isEmptyStk(stack *stk){
	if(stk->top==-1)
		return 1;
	else
		return 0;
}

void initilizeStk(stack *stk){
	stk->top=-1;
}

void push(stack *stk,char takenData){
	if(isFullStk(stk))
		return;
		//printf("Stack is full!\n");
	else{
		stk->data[++stk->top]=takenData;
	}
}

char pop(stack *stk){
	if(isEmptyStk(stk)){
		//printf("Stack is empty!\n");
		return '\0';
	}
	else{
		char retData=stk->data[stk->top--];
		return retData;
	}
}

#include<stdio.h>
#include<conio.h>
#define MAX 20

int PrefixValue,PostfixValue;

typedef struct stack{
	int data[MAX];
	int top;
}stack;

void init(stack *a){
	a->top = -1;
}

void push(stack *a,int x){
	a->top = a->top+1;
	a->data[a->top] = x;	
}

int pop(stack *a){
	int x;
	x = a->data[a->top];
	a->top = a->top-1;
	return x;
}

int evaluate(char x,int op1,int op2){
	if(x=='+')
		return(op1+op2);
	if(x=='-')
		return(op1-op2);
	if(x=='*')
		return(op1*op2);
	if(x=='/')
		return(op1/op2);
	if(x=='%')
		return(op1%op2);
}

int PostfixEvaluation(){
	char x;
	int op1, op2;
	stack post;
	init(&post);
	while((x=getchar())!='\n')
	{
		if(isdigit(x))
			push(&post,x-48);
		else
		{
			op2=pop(&post);
			op1=pop(&post);
			PostfixValue=evaluate(x,op1,op2);
			push(&post,PostfixValue);
		}
	}
	return PostfixValue=pop(&post);
}

int Prefixcalculation(char x[]){
	char c;
	int op1, op2, i, val;
	stack pre;
	init(&pre);
	for(i=0;(c=x[i])!=' ';i++){
		if(isdigit(c))
			push(&pre,c-48);
		else
		{
			op2=pop(&pre);
			op1=pop(&pre);
			val=evaluate(c,op1,op2);
			push(&pre,val);
		}
    }
	return val=pop(&pre);
}

int PrefixEvaluation(){
	char x[MAX],temp,ret;
	int i,j,k;
	for(i=0;(x[i]=getchar())!='\n';i++);
	x[i]=' ';
	k=i;
	for(i=0,j=k-1;i<=j;i++,j--){
		temp=x[i];
		x[i]=x[j];
		x[j]=temp;
	}
	return PrefixValue=Prefixcalculation(x);
}

int main(){
	printf("\nEnter the Postfix Expression : ");
	printf("\nResult after Postfix Evaluation : %d",PostfixEvaluation());
	printf("\n\nEnter the Prefix Expression : ");
	printf("\nResult after Prefix Evaluation : %d",PrefixEvaluation());
	return 1;
}

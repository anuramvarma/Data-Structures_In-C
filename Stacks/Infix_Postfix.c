#include<stdio.h>
#define max 50               
char stack[max];
int top = -1;
char infix[50],postfix[50];
void push(char element)     
{
	stack[++top]=element;
}
char pop()
{
	return(stack[top--]);
}
int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x=='^') 
        return 3;
    return 0;   
} 
 int check(char ch)   
{   
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')|| (ch>='0' && ch<='9' ));   
}   
int main(void) 
{
	char ch,element;
	int i=0,k=0;
	printf("READ THE INFIX\n\n");
	scanf("%s",infix);
	push('#');                                 
    
	while((ch = infix[i++])!='\0')
  {
		if(ch=='(')
		push(ch);
		else if(check(ch))
		postfix[k++]=ch;
		else if(ch==')'){
			while(stack[top]!='(')
			{
			postfix[k++]=pop();
			}
			element=pop();                    
		}
		else{
			while(priority(stack[top])>=priority(ch))  
			postfix[k++]=pop();
			push(ch);
		}
	}
	while(stack[top]!='#')
  {
		postfix[k++]=pop();
	}
	postfix[k]='\0';
	printf("\n\nGiven Infix Expn: %s\nPostfix Expn: %s\n", infix, postfix);
	return 0;
}

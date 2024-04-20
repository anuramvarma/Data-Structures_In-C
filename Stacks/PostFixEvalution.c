#include <stdio.h>
#include<stdlib.h>
#define max 50               
char postfix[max];
char stack[max];
int top = -1;

void push(char element)     
  {
	top++;
	stack[top]=element;
  }
char pop(){
	if(top==-1) 
	{
	  printf("Stack underflow");
	  exit(1);
	}
	return(stack[top--]);
}

 int check(char ch)   
{   
    return (ch>='0' && ch<='9');   
}   

int main(void) 
{
	char ch,element,s;
	int i=0,k=0,num1,num2,ans;
	printf("READ THE postfix\n\n");
	scanf("%s",postfix);
	while((postfix[i])!='\0')
	{
		ch=postfix[i];
		if(check(ch))
		   push(ch);
		else{
			num1=pop()-'0';
			num2=pop()-'0';
			printf("%d %d ",num1,num2);
			switch(ch) 
	{
            case '+' :
                ans=num2+num1;
                break;
            case '-' :
                ans=num2-num1;
                break;
            case '*' :
                ans=num2*num1;
                break;
            case '/':
                ans=num2/num1;
                break;
        }
  			ans=ans+'0';
                push(ans) ;
        }
             i++;
}
	printf("\nGiven postfix Expn: %s", postfix );
	printf("\nAnswer=%d",pop()-'0');
	return 0;
}

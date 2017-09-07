#include <stdio.h>
#include <string.h>
int precedence(char symbol)
{
 if(symbol == '^')
 {
  return(3);
 }
 else if(symbol == '*' || symbol == '/')
 {
  return(2);
 }
 else if(symbol == '+' || symbol == '-')
 {
  return(1);
 }
 else return 0;
}
void main()
{
	char ix[100], stack[100], px[100];
	int top=-1;
	char item,x;
	printf("Enter expression within parenthesis\n");
	gets(ix);
	int i=0,j=0;
	item=ix[0];
 	while(item != '\0')
	{	
		
		if (item == '(')
    	{
			stack[++top]=item;
    	}
		else if(item=='^' || item=='*' || item=='/' || item=='+' || item=='-')
		{
			if (precedence(item)>precedence(stack[top]))
			{
				stack[++top]=item;
			}
			else if (precedence(item)<=precedence(stack[top]))
			{
				while((precedence(item)<=precedence(stack[top])))
				{
					px[j++]=stack[top--];
				}
				stack[++top]=item;
			}
		}
		else if ((item>='a' && item<='z') || (item>='A' && item<='Z'))
		{
			px[j++]=item;
		}
		else if(item == ')')
    	{
    		x =stack[top];
    		while(x != '(')
    		{
    			px[j++] = x;
    			x = stack[--top];
    		}
    		top--;
   		}
   		item=ix[++i];
	}
		px[j]='\0';
		printf("Expression in postfix form\n");
		puts(px);
		getch();
}

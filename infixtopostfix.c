#include <stdio.h> #include <ctype.h>

#define MAX 100


char stack[MAX]; int top = -1;

void push(char ch) { stack[++top] = ch;
}


char pop() {
return stack[top--];

}


char peek() {
return stack[top];
}


int precedence(char ch) { if (ch == '+' || ch == '-')
return 1;
if (ch == '*' || ch == '/') return 2;
if (ch == '^') return 3;
return 0;
}


int main() {
char infix[MAX], postfix[MAX]; int i, j = 0;

printf("Enter infix expression: "); scanf("%s", infix);

for (i = 0; infix[i] != '\0'; i++) { char ch = infix[i];

if (isalnum(ch)) { postfix[j++] = ch;
}
else if (ch == '(') {

push(ch);
}
else if (ch == ')') {
while (top != -1 && peek() != '(') postfix[j++] = pop();
pop();
}
else {
while (top != -1 &&
precedence(peek()) >= precedence(ch)) { postfix[j++] = pop();
}
push(ch);
}
}


while (top != -1) postfix[j++] = pop();

postfix[j] = '\0';


printf("Infix Expression : %s", infix); printf("\nPostfix Expression : %s", postfix);

return 0;
}

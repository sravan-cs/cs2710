#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>
#include<sstream>
#include<cstdlib>
/*  The class stack defines an ADT stack. 
    See Ref. Aho, Hopcroft and Ullmann : Data Structures and Algorithms,
    Addison Wesley, 1978. */

/* begin {Definition of class stack} */


#define STACK_SIZE 1000
#define EXPR_LENGTH 1000
typedef  int ElemType;

using namespace std;
class stack {
  ElemType stackArray[STACK_SIZE];        // A stack of characters
  int tos;              // A pointer to the top of stack.

public :
  ElemType Top();               // returns the element on Top of the stack
  void Push(ElemType x);      // Pushes an element on to the stack
  ElemType Pop();             // Pops an element from the stack
  int Empty();            // returns 1 if stack is Empty
  void MakeNull();        // creates an Empty stack
 };
/* end{Definition of class stack} */


/* begin{Implementation of the class stack} */

ElemType stack::Top() {

  if (tos < STACK_SIZE)
    return (stackArray[tos]);
  else
    return(0);
  }

int stack::Empty() {

  if (tos >= STACK_SIZE)
	 return 1;
  else
	 return 0;
}

void stack::Push(ElemType x) {

  tos--;
  stackArray[tos] = x;
}

ElemType stack::Pop() {

  ElemType tmp;

  if (tos >= STACK_SIZE) 
    return (-1); 
  else {
    tmp = stackArray[tos];
    tos++;
    return (tmp);
  }
}

void stack::MakeNull() {

  tos = STACK_SIZE;

}
/* end {Implementation of stack} */

int EvaluatePostFix(char **postFixExpr, int exprLength) {
   int result=0;
    stack solve;//creating a new stack
    solve.MakeNull();
    int i=0;
    for(i=0;i<exprLength;i++){
    if(postFixExpr[i][0]=='+'||postFixExpr[i][0]=='-'||postFixExpr[i][0]=='/'||postFixExpr[i][0]=='*'){
         int num1=solve.Pop();
        int num2=solve.Pop();//taking top two elements of the stack
        switch (postFixExpr[i][0])
          {
          case '+':
            result=num2+num1;
            break;
          case '-':
            result=num2-num1;
            break;
          case '/':
            result=num2/num1;
            break;
          case '*':
            result=num2*num1;
            break;
          default:
            break;
          }//performing the asked opertions
          solve.Push(result);//pushing the resuult of operations into the stack
      }
    else{
        int num=stoi(postFixExpr[i]);
        solve.Push(num);//pushing the operands into the stack
    }
    }
  	result=solve.Pop();//taking the last element of the stack as the result of the post fix expression
   return result;
}


int main() {
  char **postFixExpr;
  int  n;
  int  i;
  char c;
  cin >> n;//storing the number of rows
    i=0;  
    int j=0;
    scanf("%c",&c);
    postFixExpr=(char**)malloc(n*sizeof(char*));
    for(i=0;i<n;i++){postFixExpr[i]=(char*)malloc(7*sizeof(char));}//allocating the space for the 2D array dynamically
    for(i=0;i<n-1;i++){
        for(j=0;;j++){
            scanf("%c",&c);
            if(c==' ' || c=='\0' || c==EOF){
                postFixExpr[i][j]='\0';
                break;
            }
            else{postFixExpr[i][j]=c;}
            printf("%c",postFixExpr[i][j]);
        }//storing the input and printing it simultaneously
        printf(" ");
    }
    scanf("%c",&c);
    postFixExpr[n-1][0]=c;
    postFixExpr[n-1][1]='\0';//storin the last character
    printf("%c\n",postFixExpr[n-1][0]);
    int sol=EvaluatePostFix(postFixExpr,n);
    cout<<"The Result is :"<<sol;//printing the result
    
  
}
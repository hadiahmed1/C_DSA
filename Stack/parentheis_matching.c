#include <stdio.h>
#include <stdlib.h>
struct stack{
    int size;
    int top;
    char* arr;
};
struct stack* createStack(int size){
    struct stack* st=(struct stack*)malloc(sizeof(struct stack));
    st->top=-1;
    st->size=size;
    st->arr=(char*)malloc(st->size*sizeof(char));
    return st;
}
void push(struct stack* s,char ch,int i){
    printf("pushing %d\n",i);
    s->top=s->top+1;
    s->arr[s->top]=ch;
    return;
}
void pop(struct stack* s,int i){
    printf("popping %d\n",i);
    s->top -=1;
    return;
}
int matchParenthesis(char str[100]){
    struct stack* s=createStack(50);
    int index=0;
    char ch=str[index];
    while(ch!='\0'){
        if(ch=='(')
            push(s,'(',index);
        if(ch==')'){
            if(s->top<0)//cannot push underflow stack
                return 0;
            pop(s,index);
        }
        index+=1;
        ch=str[index];
    }
    printf("Top=%d\n",s->top);
    return (s->top==-1)?(1):(0);
}
void check(int c){
    if(c)
        printf("Parentheis Matching SUCESSFULL\n");
    else
        printf("Parentheis Matching FAILED\n");
}

int main(){
    printf("Enter Expression:");
    char str[100];
    scanf("%s",str);
    check(matchParenthesis(str));
    return 0;
}
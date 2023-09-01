#include<stdio.h>
int head = -1;
int n=5, x, choice;
int arr[5];
void makeEmpty(int arr[])
{
    head=-1;
}
void push(int x, int arr[])
{
    if(head==n-1)
    {
        
        printf("Stack is full");
        return;
    }
    head++;
    arr[head]= x;
}
void pop(int arr[])
{
    if(head==-1)
    {
        printf("empty Stack");
        return;
    }
    head--;
}
void printArr(int arr[])
{
    if(head==-1)
    {
       
        printf("Stack is empty");
        return;
    }
    for(int i=0; i<= head; i++){
        printf("%d\n", arr[i]);
    }
}
void main()
{

   
    while(choice!=4)
    {
       
        printf("\n\n\n\n-----These are the menu panel-----");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Traverse");
        printf("\n4. Exit");
        printf("\nenter the option no.: ");
        scanf("%d", &choice);

       
        switch(choice)
        {
         
            case 1: 
            printf("enter the number you wnat to push: ");
            scanf("%d", &x);
            push(x, arr);
                break;
            case 2: pop(arr);
                break;
            case 3: printArr(arr);
                break;
            case 4:
                break;
            default:
                printf("incorrect choice");
        }
    }

   
    printf("You got exit\n");
}
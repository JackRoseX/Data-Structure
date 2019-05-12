/***********************************************************
• 创建一个栈数据结构
• 实现栈的push及pop操作
************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Status_def{
	STATUS_NO_ERROR,
	STATUS_STACK_FULL_ERROR,
	STATUS_STACK_EMPTY_ERROR,
	STATUS_ERROR
}Status;

typedef struct Stack_def
{
	int *ptr;
	int *top;
	int  depth;
}Stack_S;

Status Stack_Init(Stack_S *stack, int *p, int depth)
{
	stack->ptr = p;
	stack->top = p-1;
	stack->depth = depth;

	return STATUS_NO_ERROR;
}

Status Stack_Push(Stack_S *stack, int data)
{
	if (stack->top >= (stack->ptr + stack->depth - 1))
	{
		printf("stack is full\n");
		return STATUS_STACK_FULL_ERROR;
	}
	else
	{
		stack->top++;
		*(stack->top) = data;
	}

	return STATUS_NO_ERROR;
}

Status Stack_Pop(Stack_S *stack, int *data)
{
	if(stack->top < stack->ptr)
	{
		printf("stack is empty\n");
		return STATUS_STACK_EMPTY_ERROR;
	}
	else
	{
		*data = *(stack->top);
		stack->top--;
	}

	return STATUS_NO_ERROR;
}

int main(int argc, char const *argv[])
{
	int data[100];

	int a;

	Stack_S stack;

	Stack_Init(&stack, data, 100);

	printf("stack top is:%p\nstack ptr is:%p\nstack depth is:%d\naddress of the stack's last one data is:%p\n",stack.top, stack.ptr, stack.depth,stack.ptr + stack.depth - 1);


	for (int i = 0; i < 100; ++i)
	{
		if(Stack_Push(&stack, 156) == STATUS_STACK_FULL_ERROR)
			break;
	}
	
	printf("After push data, the stack's top is:%p\n", stack.top);

	Stack_Pop(&stack, &a);

	printf("After pop data, the stack's top is:%p\n", stack.top);

	printf("pop data is:%d\n", a);

	return 0;
}


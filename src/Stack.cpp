/*

 * Vincent Ha

 * CIS 22C, Winter 2017

 */

#include "Stack.h"
#include "assert.h"
#include <iostream>
using namespace std;

Stack::Stack(): top(NULL), size(0) { }

Stack::Stack(const Stack &stack)
{
	size = stack.size;
	if(stack.size == 0){
		top = NULL;
	} else{
		top = new Node(stack.top -> data);
		NodePtr iter1 = stack.top;
		NodePtr iter2 = top;
		while(iter1->next != NULL){
			iter2->next = new Node(iter1->next->data);
			iter1 = iter1->next;
			iter2 = iter2->next;
		}
	}
}

Stack::~Stack()
{
	NodePtr deleting;
	NodePtr iter = top;
	while(iter != NULL){
		deleting = iter;
		iter = iter->next;
		delete deleting;
	}
}

void Stack::pop()
{
	assert(size != 0);
	if(size == 1){
		delete top;
		top = NULL;
	}else{
		NodePtr temp = top;
		top = top->next;
		delete temp;
	}
	size--;
}

void Stack::push(string data){
	NodePtr N = new Node(data);
	if(size == 0){
		top = N;
	}else{
		N->next = top;
		top = N;
	}
	size++;
}

string Stack::peek()
{
	assert(size != 0);
	return top->data;
}

int Stack::get_size()
{
	return size;
}

bool Stack::is_empty()
{
	return size == 0;
}

void Stack::print()
{
	NodePtr iter = top;
	while(iter != NULL){
		cout << iter->data << " ";
		iter = iter->next;
	}
	cout << endl;
}

bool Stack::operator==(const Stack &stack)
{
	if(size != stack.size){
		return false;
	}

	NodePtr iter1 = top;
	NodePtr iter2 = stack.top;
	while(iter1 != NULL){
		if(iter1->data != iter2->data){
			return false;
		}
		iter1 = iter1->next;
		iter2 = iter2->next;
	}

	return true;
}

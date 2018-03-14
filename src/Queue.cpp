/**

 * Vincent Ha

 * CIS 22C, Winter 2017

 */

#include <iostream>
#include "Queue.h"
#include "assert.h"
using namespace std;

Queue::Queue() {
	front = end = NULL;
	size = 0;
}

Queue::Queue(const Queue &queue) :
		size(queue.size) {
	if (queue.front == NULL) {
		end = front = NULL;
	} else {
		front = new Node;
		front->data = queue.front->data;
		NodePtr temp;
		temp = queue.front;
		NodePtr qtemp = front; //create temporary iterator

		while (temp->next != NULL) {

			qtemp->next = new Node;
			qtemp = qtemp->next;
			temp = temp->next;
			qtemp->data = temp->data;

		}
		end = qtemp;
	}

}

Queue::~Queue() {
	NodePtr temp = front;
	NodePtr temp2 = front;
	while (temp != NULL) {
		temp = temp->next;
		delete temp2;
		temp2 = temp;
	}
}

void Queue::dequeue() {
	assert(size != 0);
	if (size == 1) {
		delete front;
		front = end = NULL;
	}

	else {
		NodePtr temp = front;
		front = front->next;
		delete temp;
	}

	size--;
}

void Queue::enqueue(string data) {
	NodePtr N = new Node(data);
	if (size == 0) {
		front = end = N;
	}

	else {
		end->next = N;
		end = N;
	}

	size++;
}

bool Queue::operator==(const Queue &queue) {
	if(size != queue.size){
		return false;
	}

	NodePtr tracker1 = front;
	NodePtr tracker2 = queue.front;

	while (tracker1 != NULL) {
		if(tracker1->data != tracker2->data){
			return false;
		}
		tracker1 = tracker1->next;
		tracker2 = tracker2->next;
	}

	return true;
}

string Queue::get_front() {
	assert(size != 0);
	return front->data;
}

int Queue::get_size() {
	return size;
}

bool Queue::is_empty() {
	return size == 0;
}

void Queue::print() {
	NodePtr temp = front;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}



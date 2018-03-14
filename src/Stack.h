/*

 * Vincent Ha

 * CIS 22C, Winter 2017

 */

#ifndef STACK_H_
#define STACK_H_

#include <string>
#include <cstddef>
using namespace std;


class Stack
{
    public:
        /**constructors and destructors*/

        Stack();
        //initializes an empty stack
        //post: an empty stack

        Stack(const Stack &stack);
        //initializes stack to have same elements as another stack
        //post: a copy of stack

        ~Stack();
        //frees memory allocated to the stack
        //post: memory for stack has been freed

        void pop();
        //removes an element from the top of the stack
        //pre: the stack is not empty
        //post: an element has been removed from the top of the stack

        void push(string data);
        //adds an element to the top of the stack
        //post: an element added to the top of the stack

        /**accessors*/

        string peek();
        //returns the element at the top of the stack
        //pre: the stack is not empty

        int get_size();
        //returns the size of the stack


        bool is_empty();
        //returns whether the stack is empty

        /**additional stack operations*/
        void print();
        //prints the elements in the stack in a programmer-specified format to stdout

        bool operator==(const Stack &stack);
        //returns whether this stack is equal to another stack


    private:
        struct Node
        {
            string data;
            Node* next;
            Node(): data(""), next(NULL){}
            Node(string data): data(data), next(NULL){}

        };
        typedef Node* NodePtr;

        NodePtr top;
        int size;

};

#endif /* STACK_H_ */

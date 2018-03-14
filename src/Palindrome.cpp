/*

 * Vincent Ha

 * CIS 22C, Winter 2017

 */

#include "Queue.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cctype>
using namespace std;

int main() {
	Queue pdqueue;
	Stack pdstack;

	ifstream fin("Palindrome.txt");
	if (!fin.good()) {
		cerr << "Cannot find the file" << endl;
		exit(-100);
	}

	string text;
	vector<string> fileContents;
	while (!fin.eof()) {
		getline(fin, text);
		fileContents.push_back(text);
		text.clear();
	}
	text.clear();
	fin.close();

	bool isPalindrome = true;
	for (int a = 0; a < fileContents.size(); a++) {
		isPalindrome = true;
		cout << fileContents[a] << " ";
		text = fileContents[a];
		for (int b = 0; b < text.length(); b++) {
			char temp = static_cast<char>(text[b]);
			if (temp != ' ' && temp != '.' && temp != '\'' && temp != ','
					&& temp != '!' && temp != '?') {
				char input = static_cast<char>(tolower(static_cast<int>(temp)));
				string pushInto(1, input);
				pdqueue.enqueue(pushInto);
				pdstack.push(pushInto);
			}
		}
		text.clear();

		while (!pdqueue.is_empty()) {
			if (pdqueue.get_front() != pdstack.peek()) {
				isPalindrome = false;
				while (!pdqueue.is_empty()) {
					pdqueue.dequeue();
					pdstack.pop();
				}
				break;
			}
			pdqueue.dequeue();
			pdstack.pop();
		}

		if (isPalindrome) {
			cout << "(Palindrome)" << endl;
		} else {
			cout << "(Not a Palindrome)" << endl;
		}
	}
}

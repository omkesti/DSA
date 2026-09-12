#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next = nullptr;
};

void display(Node* head)
{
	Node* curr = head;
	while (curr != nullptr) {
		cout << curr->data << " ";
		curr = curr->next;
	}
}

void insert(int val, Node*& head)
{
	Node* node = new Node;

	node->data = val;
	node->next = nullptr;

	Node* curr = head;

	if (head == nullptr) {
		head = node;
		return;
	}

	while (curr->next != nullptr)
		curr = curr->next;

	curr->next = node;
	return;
}

void insertAtIdx(int val, int idx, Node*& head)
{
	Node* node = new Node;

	node->data = val;
	node->next = nullptr;

	if (idx == 0) {
		node->next = head;
		head = node;
		return;
	}

	Node* curr = head;
	Node* prev = nullptr;
	int cnt = 0;

	while (curr->next != nullptr)
	{
		prev = curr;
		curr = curr->next;
		cnt++;

		if (cnt == idx) {
			node->next = curr;
			prev->next = node;
			return;
		}
	}

	if (idx == (cnt + 1)) {
		curr->next = node;
		return;
	}

	cout << "Invalid index entered." << endl;
}

void del(int val, Node*& head)
{
	Node* curr = head;
	Node* prev = nullptr;

	// head condition first
	if (curr == head && val == curr->data) {
		head = curr->next;
		return;
	}
	
	while (curr->next != nullptr)
	{
		prev = curr;
		curr = curr->next;

		if (val == curr->data) {
			prev->next = curr->next;
			return;
		}
	}

	cout << "Value not found in the list." << endl;
	return;
}

int main() {
	Node* head = nullptr;
	
	insert(23, head);
	insert(34, head);
	insertAtIdx(43, 0, head);

	display(head);

	del(23, head);
	
	cout << endl;
	display(head);
	
	return 0;
}

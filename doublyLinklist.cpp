#include <iostream>
using namespace std;

struct Node {
	Node* prev = nullptr;
	int data;
	Node* next = nullptr;
};

void insert(int val, Node*& head)
{
	Node* node = new Node;

	node->data = val;
	node->prev = nullptr;
	node->next = nullptr;

	if (head == nullptr) {
		head = node;
		node->prev = head;
		return;
	}

	Node* curr = head;

	while (curr->next != nullptr) {
		curr = curr->next;
	}

	curr->next = node;
	node->prev = curr;
}

void del(int val, Node*& head)
{
	if (val == head->data) {
		head = head->next;
		return;
	}

	Node* curr = head;
	Node* prev = nullptr;

	while (curr->next != nullptr) {
		curr = curr->next;
		prev = curr;

		if (val == curr->data) {
			Node* back = curr->prev;
			back->next = curr->next;
			return;
		}
	}

	cout << "Value not found." << endl;
}

void display(Node* head)
{
	Node* curr = head;
	while (curr != nullptr)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
}

int main()
{
	Node* head = nullptr;
	insert(23, head);
	insert(34, head);
	insert(43, head);

	display(head);
	cout << endl;

	del(23, head);
	display(head);

	return 0;
}

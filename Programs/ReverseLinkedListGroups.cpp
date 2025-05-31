#include<iostream>
using namespace std;

class Node
{
	public:
	int val;
	Node* next;

	Node(int val)
	{
		this->val = val;
		this->next = nullptr;
	}
};

Node* reverse_linked_list_groups(Node* head,int k)
{
	Node* prev = nullptr;
	Node* curr = head;
	Node* next_node = nullptr;

	int i = 0;

	while(curr!=nullptr && i<k)
	{
		next_node = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next_node;
		i++;
	}

	if(next_node!=nullptr)
	{
		head->next = reverse_linked_list_groups(next_node, k);
	}

	return prev;
}

void printList(Node* head)
{
	Node* current = head;
	while(current!=nullptr)
	{
		cout << current->val;
		if(current->next != nullptr)
		{
			cout << "->";
		}

		current = current->next;
	}

	cout << endl;

}

int main()
{
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	head->next->next->next->next->next = new Node(6);
	head->next->next->next->next->next->next = new Node(7);
	head->next->next->next->next->next->next->next = new Node(8);
	head->next->next->next->next->next->next->next->next = new Node(9);
	head->next->next->next->next->next->next->next->next->next = new Node(10);

	int k = 3;

	Node* result = reverse_linked_list_groups(head, k);

	printList(result);
}
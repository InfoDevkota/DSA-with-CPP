#include <cstddef> //To use NULL
#include <iostream> //To use cout , cin

class Node
{
	public:
		int data;
		Node *next;
};
class LinkedList
{
	Node *head;
	public:
		LinkedList()
		{
			head = NULL;
		}
		void deletionAtFirst()
		{
			Node *temp = head;
			head = head -> next;
			delete temp; // delete the head node to release memory
			return;
		}
		void insertionAtFirst(int data)
		{
			Node *temp = new Node;
			temp -> data = data;
			if(head == NULL)
				head = temp;
			else
			{
				temp -> next = head;
				head = temp;
			}
			return;
		}
		void deletionAtLast()
		{
			if(noOfNodes() == 1)//Check of only one is remaining in Linked List.
			{
				deletionAtFirst();
				return;
			}
			Node *ahead = head;
			while(ahead -> next -> next != NULL)
				ahead = ahead -> next;
			ahead -> next = NULL;
			delete ahead -> next; // delete the last node to release the memory
			return;
		}
		int noOfNodes()
		{
			Node *ahead = head;
			int counter = 0;
			while(ahead!= NULL)
			{
				counter++;
				ahead = ahead->next;
			}
			return counter;
		}
		void insertionAtLast(int data)
		{
			Node *temp = new Node;
			temp -> data = data;
			if(head == NULL)
			{
				head = temp;
				return;
			}
			Node *ahead = head;
			while(ahead -> next != NULL)
				ahead = ahead -> next;
			ahead -> next = temp;
			return;
		}
		void deletionAtPosition(int pos)
		{
			Node *ahead = head;
			Node *temp = new Node;
			if(pos == 1)
			{
				deletionAtFirst();
				return;
			}
			while(pos >2)
			{
				pos--;
				ahead = ahead -> next;
			}
			temp = ahead->next;
			ahead -> next = ahead -> next -> next;
			delete(temp);
		}
				
		void insertionAtPosition(int pos, int data)
		{
			Node *temp = new Node;
			temp -> data = data;
			if(head == NULL)
			{
				head = temp;
				return;
			}
			if(pos == 1)
			{
				insertionAtFirst(data);
				return;
			}
			Node *ahead = head;
			while(pos >2)
			{
				pos--;
				ahead = ahead->next;
			}
			temp -> next = ahead -> next;
			ahead -> next = temp;
			return;
		}

		void display()
		{
			using std::cout; //Similar to using namespace std but here we use the cout from std
			Node *ahead = new Node;
			ahead = head;
			while(ahead!= NULL)
			{
				cout<< ahead->data <<"\t";
				ahead = ahead->next;
			}
			cout << "\n";
		}
};
using std::cout;
using std::cin;
int main()
{
	LinkedList obj;
	int data;
	int next = 1;
	int option;
	while(next == 1)
	{
		cout<<"Option\tTo do\n1\tTo Insert at First\n2\tTo Insert at Last\n3\tTo Insert at Position\n4\tTo Display Linked list\n5\tTo Delete at First\n6\tTo Delete at last\n7\tTo delete at postion\n8\tTo print no. of nodes\n9\tTo Close the program\nYour Option:- ";
		cin >> option;
		switch(option)
		{
			case 1:
			{
				cout<<"Enter the Element to insert at first:- ";
				cin >> data;
				obj.insertionAtFirst(data);
				break;
			}
			case 2:
			{
				cout<<"Enter the Element to insert at last:- ";
				cin >> data;
				obj.insertionAtLast(data);
				break;
			}
			case 3:
			{
				int pos;
				cout<<"Enter the Position:- ";
				cin >> pos;
				cout<<"Enter the Element to insert at last:- ";
				cin >> data;
				obj.insertionAtPosition(pos,data);
				break;
			}
			case 4:
			{
				obj.display();
				break;
			}
			case 5:
			{
				obj.deletionAtFirst();
				break;
			}
			case 6:
			{
				obj.deletionAtLast();
				break;
			}
			case 7:
			{
				int pos;
				cout<<"Enter the postion to delete:- ";
				cin>>pos;
				obj.deletionAtPosition(pos);
				break;
			}
			case 8:
			{
				int a = obj.noOfNodes();
				cout<<"Total no of nodes on the linked list are "<<a<<".\n";
				break;
			}
			case 9:
			{
				next = 0; //next? NO
				cout<<"Thank you :)\n";
				break;
			}
			default:
				cout<<"Please Enter a valid option. \n";
		}
	}
}

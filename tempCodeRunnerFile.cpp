
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

node *takeinput()
{
    int data;
    cin >> data;
    node *head = NULL;
    while (data != -1)
    {
        node *newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        cin >> data;
    }
    return head;
}

int lenll(node *head)
{
    int count = 0;
    node *tail = head;
    while (tail != NULL)
    {
        count = count + 1;
        tail = tail->next;
    }
    return count;
}

node *takeinputless()
{
    int data;
    cin >> data;
    node *head = NULL;
    node *tail = NULL;
    while (data != -1)
    {
        node *newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {

            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(node *head)
{
    node *tail = head;
    while (tail != NULL)
    {
        cout << tail->data << endl;
        tail = tail->next;
    }
}

int main()
{
    /*node n1(1);
    node n2(2);
    node n3(3);
    node n4(4);
    node n5(5);
    node *head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    print(head);*/
    node *head = takeinputless();
    print(head);
    int length = lenll(head);
    cout << "Length of linked list is " << length << endl;
}
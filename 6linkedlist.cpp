
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
    /*while (tail != NULL)
    {
        count = count + 1;
        tail = tail->next;
    }*/
    while (tail != NULL)
    {
        count += 1;
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

int getindex(int value, node *head)
{
    int index = 0;
    node *tail = head;
    while (tail != NULL)
    {
        if (tail->data == value)
        {
            return index;
        }
        else
        {
            index = +1;
            tail = tail->next;
        }
    }
    return -1;
}
node *insert(node *head, int i, int data)
{
    node *tail = head;
    node *newnode = new node(data);
    int n = 0;
    if (i == 0)
    {
        newnode->next = head;
        head = newnode;
        return head;
    }
    while (tail != NULL && n < i - 1)
    {
        tail = tail->next;
        n++;
    }
    if (tail != NULL && i != 0)
    {
        node *temp = tail->next;
        tail->next = newnode;
        newnode->next = temp;
    }
    return head;
}

node *deleteindex(node *head, int index)
{
    if (index >= lenll(head))
    {
        return head;
    }
    if (index == 0)
    {
        head = head->next;
        return head;
    }
    int n = 0;
    node *temp = head;
    node *a, *b;
    while (n < index - 1)
    {
        temp = temp->next;
        n++;
    }
    a = temp->next;
    b = a->next;
    temp->next = b;
    delete a;
    return head;
}
int lenllr(node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    return lenllr(head->next) + 1;
}
node *insertr(node *head, int i, int data)
{
    if (i == 0)
    {
        node *newnode = new node(data);
        newnode->next = head;
        head = newnode;
        return head;
    }
    node *newhead = insertr(head->next, i - 1, data);
    head->next = newhead;
    return head;
}
node *deleteindexr(node *head, int index)
{
    if (index == 0)
    {
        head = head->next;
        return head;
    }
    node *newhead = deleteindexr(head->next, index - 1);
    head->next = newhead;
    return head;
}

// find a node in linked list

int findnode(node *head, int value)
{
    if (head->data == value)
    {
        return 0;
    }
    return 1 + findnode(head->next, value);
}
int findnode2(node *head, int value, int index)
{
    if (head->next == NULL)
    {
        return -1;
    }
    if (head->data == value)
    {
        return index;
    }
    int i = findnode2(head->next, value, index + 1);
    return i;
}
int findnode3(node *head, int a)
{
    node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        if (temp->data == a)
        {
            return i;
        }
        else
        {
            i = i + 1;
            temp = temp->next;
        }
    }
    return -1;
}
node *AppendLastNToFirst(node *head, int n)
{
    int x = lenllr(head) - n;
    node *temp = head;
    node *tail = head;
    for (int i = 0; i < x - 1; i++)
    {
        temp = temp->next;
    }
    node *b = temp->next;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    temp->next = NULL;
    tail->next = head;
    head = b;
    return head;
}
void removeduplicates(node *t1, node *t2)
{
    if (t1 == NULL or t2 == NULL)
    {
        t1->next = t2;
        return;
    }
    if (t1->data != t2->data)
    {
        t1->next = t2;
        removeduplicates(t2, t2->next);
    }
    if (t1->data == t2->data)
    {
        removeduplicates(t1, t2->next);
    }
}

void printreversell(node *head)
{
    int n = 0;
    node *tail = head;
    while (tail != NULL)
    {
        tail = tail->next;
        n = n + 1;
    }
    for (int j = n - 1; j >= 0; j--)
    {
        node *temp = head;
        for (int i = 0; i < j; i++)
        {
            temp = temp->next;
        }
        cout << temp->data << " ";
    }
}
void printreversellr(node *head)
{
    if (head == NULL)
    {
        return;
    }
    printreversellr(head->next);
    cout << head->data << " ";
}
bool checkpalindromehelper(node *head, node *tail, int len)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    if (head->data != tail->data)
    {
        return false;
    }
    else
    {
        node *newtail = head;
        for (int i = 0; i < len - 1; i++)
        {
            newtail = newtail->next;
        }
        return (head->next, newtail, len - 2);
    }
}

bool checkpalindromer(node *head)
{
    node *tail = head;
    int count = 0;
    while (tail->next != NULL)
    {
        tail = tail->next;
        count = count + 1;
    }
    return checkpalindromehelper(head, tail, count);
}

void printmiddlell(node *head)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count = count + 1;
    }
    node *tail = head;
    if (count % 2 == 0)
    {
        int midpoint = (count - 1) / 2;
        for (int i = 0; i < midpoint; i++)
        {
            tail = tail->next;
        }
        cout << tail->data;
    }
    else
    {
        int midpoint = (count) / 2;
        for (int i = 0; i < midpoint; i++)
        {
            tail = tail->next;
        }
        cout << tail->data;
    }
}

node *printmiddlell2(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        fast = fast->next;
    }
    return slow;
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
    // print(head);
    // int length = lenll(head);
    // cout << "Length of linked list is " << length << endl;
    // cout << "Enter the number u want to find" << endl;
    // int num;
    // cin >> num;
    // int index = getindex(num, head);
    // cout << "Index of" << num << " is " << index << endl;
    // cout << " Enter the index and number u want to insert: ";
    // int index, data;
    // cin >> index >> data;
    // head = insert(head, index, data);
    // print(head);
    // cout << " Enter the index of number u want to delete: ";
    // int index;
    // cin >> index;
    // head = deleteindex(head, index);
    // print(head);
    // int length = lenllr(head);
    // cout << "Length of linked list is " << length << endl;
    // cout << " Enter the index and number u want to insert: ";
    // int index, data;
    // cin >> index >> data;
    // head = insertr(head, index, data);
    // print(head);
    // int value;
    // cin >> value;
    // int index = findnode(head, value);
    // int index = findnode2(head, value, 0);
    // cout << index;
    int value;
    cin >> value;
    int index = findnode3(head, value);
    cout << index;
    // int n;
    // cin >> n;
    // head = AppendLastNToFirst(head, n);
    // print(head);
    // head = AppendLastNToFirst(head, n);
    // print(head);
    // node *t1 = head;
    // node *t2 = head->next;
    // removeduplicates(t1, t2);
    // print(head);
    // // printreversell(head);
    // // cout << endl;
    // // printreversellr(head);
    // // bool x = checkpalindromer(head);
    // // cout << x;
    // // printmiddlell(head);
    // node *ans = printmiddlell2(head);
    // cout << ans->data;
}
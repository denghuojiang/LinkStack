
#include <iostream>
using namespace std;
typedef int ElemType;
struct Node
{
    ElemType data;
    Node* next=NULL;
};
class LinkStack
{
public:
	LinkStack();
	~LinkStack();
    int push(ElemType* e);
    ElemType* gettop();
    ElemType pop();
private:
    Node* top=NULL;
    int size =NULL;
};

LinkStack::LinkStack()
{
    this->top = new Node;
    this->size = 0;
}

LinkStack::~LinkStack()
{
    delete top;
}
int main()
{
    std::cout << "Hello World!\n";
    LinkStack ls;
    ElemType i = 23;
    ElemType e = 1;
    ls.push(&i);
    ls.push(&e);
    cout << *ls.gettop()<<endl;
    ls.pop();
    cout<<*ls.gettop();
}
int LinkStack::push(ElemType* e)
{
    Node* pnew = new Node;
    pnew->data = *e;
    pnew->next = this->top;
    this->top = pnew;
    this->size++;
    return 0;
}
ElemType* LinkStack::gettop()
{   
    return &this->top->data;
}
ElemType LinkStack::pop()
{
    if (this->size == 0)return NULL;
    Node* pfree = this->top;
    this->top = this->top->next;
    free(pfree);
    this->size--;
    return this->top->data;
}
#include <iostream>
#include <exception>
#include <new>

namespace mylib{

    template <typename T>
    class node{
    public:
        T element;
        node* next;
        node(node* nextval = nullptr):next(nextval){}
        node(T elemval,node* nextval = nullptr):element(elemval),next(nextval){}
    };

    template <typename T>
    class stack
    {
        node<T>* ptop;
        node<T>* bottom;
        int stackSize=0;
    public:
        int flag=1;
        stack()
        {
            ptop=nullptr;
        }

        bool empty()
        {
            return stackSize ? false : true;
        }

        bool push(T it)
        {
            if(flag==1)
            {
                ptop=new node<T>(it,nullptr);
                bottom=ptop;
                flag++;
                stackSize++;
            }
            else
            {
                node<T>* temp=new node<T>(it,nullptr);
                temp->next=ptop;
                ptop=temp;
                stackSize++;
            }
            return true;
        }

        stack(std::initializer_list<T> arr)
        {
            for(auto& i:arr)
                push(i);

        }

        T top()
        {
            if(stackSize==0) {std::cerr<<"/nStack Empty. Exiting.";exit(-1);}
            return ptop->element;
        }

        bool pop()
        {
            if(ptop==nullptr) return 0;
            if(ptop==bottom)
            {
                popmech();
                ptop=nullptr;
                return 1;
            }
            popmech();
            return 1;
        }

        bool clear()
        {
            while(pop());
            flag = 0;
        }

        void popmech()
        {
            auto temp = ptop;
            ptop = ptop->next;
            stackSize--;
            delete temp;
        }
        int size(){return stackSize;}
    };
}

int fact(mylib::stack<int> myStck);

int main()
{
    mylib::stack<int> s1;


    mylib::stack<int> s2={1,3,5,7,9};



    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    s1.clear();

   // std::cout << s1.empty();

    s1={1,2,3,4,5,6,7};

    std::cout << fact(s1);

}

int fact(mylib::stack<int> myStck)
{
    auto myStckC = myStck;
    int result=1;
    while(!myStckC.empty())
    {
        //std::cout<<myStckC.top();
        result*=myStckC.top();
        myStckC.pop();
    }
    return result;
}

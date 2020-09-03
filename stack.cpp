#include <iostream>

const int MAX_STACK_SIZE = 256;

//Element structure
template<class T>
struct Element
{
    Element* prev;
    T data;
};

//Stack class
template<class T>
class Stack
{
private:
    int stack_size;
    int max_stack_size;
    Element<T>* top;
public:
    Stack();
    //stack actions
    T pop();
    void push(T i);
    
    //prints data of every stack element
    void print_stack();
    
    //inline methods
    //returns true if stack is empty
    inline bool empty(){
        return top ? false : true;
    };
    //returns true if stack is full
    inline bool full(){
        return stack_size == max_stack_size ? true : false ;
    }
    //returns actual stack size
    inline T size(){
        return stack_size;};
    //returns data at top of 
    //stack without removing an element
    inline T peek(){
        return top->data;
    }
};

template<class T>
Stack<T>::Stack():stack_size(0),top(nullptr),max_stack_size(MAX_STACK_SIZE){};

//push method, inserts new element at top
template<class T>
void Stack<T>::push(T i)
{
    if(full()) 
        throw(std::string("Stack is full"));
     
    Element<T>* new_el = new Element<T>;
    new_el->data = i;
    new_el->prev = top;
    top = new_el;
    stack_size++;
}

//pop method, removes element from top and returns its value
template<class T>
T Stack<T>::pop()
{
    if(empty())
        throw(std::string("Stack is empty"));

    Element<T>* temp = top;
    top = top->prev;
    T data_to_ret = temp->data;
    delete temp;
    stack_size--;
    return data_to_ret;
}

//prints every stack value descending
template<class T>
void Stack<T>::print_stack()
{
    if(empty())
        throw(std::string("Stack is empty"));
    
    int i = stack_size;
    Element<T>* temp = top;
    
    std::cout << "Position : Data" << std::endl;
    while(temp != nullptr){
        std::cout << --i << " : " << temp->data << std::endl;
        temp = temp->prev;
    }
}

int main()
{
    //double type data stack
    Stack<double> s;
    char c;
    do
    {
        std::cout << "1 - empty()\n";
        std::cout << "2 - push()\n";
        std::cout << "3 - pop()\n";
        std::cout << "4 - print_stack()\n";
        std::cout << "5 - size()\n";
        std::cout << "6 - Push 100 elements\n";
        std::cout << "7 - Pop 100 elements\n";
        std::cout << "8 - full()\n";

        std::cout << "Enter your choice: ";
        std::cin >> c;
        std::cout << '\n';
        
        switch (c)
        {
            case '1':
                std::cout << "Empty: " << std::boolalpha <<  s.empty() << std::endl;
                break;
            
            case '2':
                try{
                    s.push(double(rand()%100+1));
                }
                catch(std::string s){
                    std::cerr << s << std::endl; 
                }
                break;

            case '3':
                try{ 
                    s.pop();
                }
                catch(std::string s){
                    std::cerr << s << std::endl;
                }
                break;

            case '4':
                try{ 
                    s.print_stack();
                }
                catch(std::string s){
                    std::cerr << s << std::endl;
                }
                break;

            case '5':
                std::cout << "Stack size: " << s.size() << std::endl;
                break;
            
            case '6':
                try{
                    for(int i=0;i<100;++i)
                        s.push(double(rand()%10+1));
                }
                catch(std::string s){
                    std::cerr << s << std::endl; 
                }
                break;
            
            case '7':
                try{
                    for(int i=0;i<100;++i) 
                        s.pop();    
                }
                catch(std::string s){
                    std::cerr << s << std::endl; 
                }
                break;
            
            case '8':
                std::cout << "Full: " << std::boolalpha <<  s.full() << std::endl;
                break;
            
            default:
                std::cout << "There is no " 
                << "option available for \'" 
                << c << "\'" << std::endl;
                break;
        }
    } while (c!='q');
    return 0;
}
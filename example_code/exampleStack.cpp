#include <iostream>
#include <optional>

using namespace std;

/*
 * Stack that is implemented using array containint elements of type E 
 * Implemented as a class template to allow this stack to operate on various data types
 * Type parameter E represents any data type
 */
template <typename E> 
class Stack		
{
private:
	E* A;	    // pointer to an array for storing stack elements
    int size;
	int top;	// index of the stack top

public:
	Stack(int s);
    ~Stack();

    bool isFull();
    bool isEmpty();

    bool push(E item);
    E pop();
    E peekTop();
};

// Constructor: create an empty stack with the specified size
template <typename E>
Stack<E>::Stack(int s)
{
    
}

template <typename E>
Stack<E>::~Stack()
{
}

// Return true if the stack is already full 
template <typename E>
bool Stack<E>::isFull()
{
}

/*
 * Return true if the stack is empty
 */
template <typename E>
bool Stack<E>::isEmpty()
{
}

/*
 * Insert a given item to the top of the stack
 * Return true if the push operation completes successfully
*/
template <typename E>
bool Stack<E>::push(E item)
{
    
}

/*
 * Return and remove an item from the top of the stack 
 */
template <typename E>
E Stack<E>::pop()
{
    
}

/*
 * Return the top item of the stack
 */
template <typename E>
E Stack<E>::peekTop()
{
    
}

/**
 * 
 * Class that parses a string and determine if delimiters are used correctly
 */
class BracketChecker
{
private:
    // Return true if the delimiters a and b match 
    bool isMatched(char a, char b)
    {
        return ((a == '(' && b == ')') ||
                (a == '[' && b == ']') ||
                (a == '{' && b == '}'));
    }

public:
    
    // Return true if the given string (str) uses brackets correctly 
    bool isLegal(string str)
    {
        Stack<char> brackets(100);                                   // create a stack containing characters with max size 100

        for (int i = 0; i < str.length(); i++)                      // scan the string from left toward right
        {
            char cur = str.at(i);  
            
            if (cur == '(' || cur == '{' || cur == '[')             // push openning brackets into stack
                brackets.push(cur);
            else
            {
                if (cur == ')' || cur == '}' ||cur == ']')           // when reaching a closing bracket
                {
                    if (brackets.isEmpty())                         // no openning bracket in the stack        
                        return false;
                    else                                                    
                    {
                        char topItem = brackets.pop();              // pop an opennig bracket from the stack
                        if(!isMatched(topItem, cur))                // openning bracket does not match with the closing bracket 
                            return false;
                    }
                }
            }
        }

        return brackets.isEmpty();                                 // there are still some openning brackets left over in stack
    }
};

/*
 * Class that handles postfix expressions 
 * Assume: operands are single-digit numbers
 */
class PostfixExpression
{
private:
    // Return true if operator a has higher precedence than operator b
    bool hasHigherPrecedence(char a, char b)
    {
        if (b == '(')
            return true;
        else if ((a == '*' || a == '/') && (b == '+' || b == '-'))
            return true;
        else
            return false;
    }

public:
    string exp;            // postfix expression

    // Constructor: create a postfix expression e 
    PostfixExpression(string e)
    {
        exp = e;
    }

    PostfixExpression()
    {
        exp = "";
    }

    // Convert from the given infix expression to the equivalent postfix expression
    void infixToPostfix(string infix)
    {
        Stack<char> operatorStack(infix.length());
        exp = "";

        for (int i = 0; i < infix.length(); i++)    // scan the infix expression from left to right
        {
            char t = infix.at(i);                   // current character we are looking at in the infix expression
            
            switch(t)
            {
                case '(':
                    operatorStack.push(t);
                    break;
                case ')':
                    while(!operatorStack.isEmpty())
                    {
                        char temp = operatorStack.pop();
                        if (temp == '(')   
                            break;
                        exp = exp + temp;
                    }  
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                    while (!operatorStack.isEmpty() && !hasHigherPrecedence(t, operatorStack.peekTop()))
                        exp = exp + operatorStack.pop();

                    operatorStack.push(t);
                    break;
                default:                                   // it's an operatand
                    exp = exp + t;
            }
        }

        while (!operatorStack.isEmpty())                           // there are still some operators in stack
            exp = exp + operatorStack.pop();
    }
    
    // Evaluation postfix expression 
    int evaluate()
    {
        Stack<int> resultStack(exp.length());

        for (int i = 0; i < exp.length(); i++)
        {
            char t = exp.at(i);
            if (t == '+' || t == '-' || t == '*' || t == '/')       // it's an operator
            {
                // pop two operands from stack
                int s2 = resultStack.pop();           
                int s1 = resultStack.pop();
                
                // do calculation
                int value;
                switch(t)
                {
                    case '+':   
                        value = s1 + s2;    
                        break;
                    case '-':   
                        value = s1 - s2;    
                        break;
                    case '*':   
                        value = s1 * s2;    
                        break;
                    default:   
                        value = s1 / s2;    
                }                    
                resultStack.push(value);
            }
            else                                                    // it's an operand
                resultStack.push(t - '0');            
        }
        return resultStack.pop();                                 
    }
};
    
void checkBrackets()
{
    cout << "Enter a string with or without brackets: ";
    string str;
    cin >> str;
    
    BracketChecker bc;
    if (bc.isLegal(str))
        cout << str << " is legal." << endl;
    else
        cout << str << " is illegal." << endl;
}

void reverseSequence()
{
    Stack<int> inStack(10);   // create a stack with at most 10 int elements

    // push 0, 1, 2, ,3, ..., 9 into stack
    for (int i = 0; i < 10; i ++)
        inStack.push(i);

    // pop all items out of stack and print them
    while (!inStack.isEmpty())
        cout << inStack.pop() << "  " ;            

    cout << endl;    
}

void postfixDemo()
{
    PostfixExpression postfix;
    
    int option;
    do
    {
        cout << "Select from: " << endl;
        cout << "1. Read an expression in infix notation" << endl;
        cout << "2. Convert infix to postfix" << endl;
        cout << "3. Evaluate the postfix expression" << endl;
        cout << "0. Exit" << endl;
        
        string e;
        cin >> option;
        switch(option)
        {
            case 1:
                cout << "Enter an infix expression: ";
                cin >> e;
                postfix.infixToPostfix(e);
                cout << "The entered infix expresion is: " << e << endl;
                break;
            case 2:
                cout << "The corresponding postfix expresion is: " << postfix.exp << endl;
                break;
            case 3:
                cout << postfix.exp << " = " << postfix.evaluate() << endl;
                break;
            case 0:
                break;
            default:
                cout << "Invalid option. Try again." << endl;
        }
    } while (option != 0);
}

int main()
{
	Stack<int> myStack(5);

    try
    {
        myStack.pop();
    }
    catch (const std::runtime_error& e) 
    {
        cout << e.what() << endl;
    }

    myStack.push(100);
    cout << myStack.peekTop() << endl;

    reverseSequence();  // use stack to help reverse a sequence of data   
    checkBrackets();    // use stack to help parse string and check delimiters
    postfixDemo();      // use stack to help convert from infix to postfix, and evaluate postfix expression

	return 0;
}


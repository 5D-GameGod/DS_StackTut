#include <iostream>
#include <string>

using namespace std;

class Stack
{
private:
    int top;
    int arr[5];

public:
    Stack()
    {
        top = -1;
        for (int i{ 0 }; i < 5; i++)
        {
            arr[i] = 0;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if(top == 4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int val)
    {
        if(isFull())
        {
            cout << "stack overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }

    int pop()
    {
        if(isEmpty())
        {
            cout << "stack underflow" << endl;
            return 0;
        }
        else
        {
            int popvalue = arr[top];
            arr[top] = 0;
            top--;
            return popvalue;
        }
    }

    int count()
    {
        return(top + 1);
    }

    int peek(int pos)
    {
        if (isEmpty())
        {
            cout << "stack underflow" << endl;
            return 0;
        }
        else
        {
            return arr[pos];
        }
    }

    void change(int pos, int val)
    {
        arr[pos] = val;
        cout << "value changed at location " << pos << endl;
    }

    void display()
    {
        cout << "All values in the stack are " << endl;
        for(int i{4}; i>=0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    Stack s1;
    int option, position, value;

    do
    {
        cout << "What operation do you want to perform? Select option number." << endl;
        cout << "0. Exit Application." << endl;
        cout << "1. Add a number to the stack." << endl;
        cout << "2. Remove and display last added number." << endl;
        cout << "3. Check if the stack is empty." << endl;
        cout << "4. Check if the stack is full." << endl;
        cout << "5. Display the last added number." << endl;
        cout << "6. Determine how many numbers are in the stack." << endl;
        cout << "7. Change the number at a certain position" << endl;
        cout << "8. Display all the numbers in the stack." << endl;
        cout << "9. Clear Screen" << endl;

        cin >> option;
        switch(option)
        {
            case 0:
                break;
            case 1:
                cout << "Enter a number to add to the stack" << endl;
                cin >> value;
                s1.push(value);
                break;

            case 2:
                cout << "You have removed " << s1.pop() << " from the stack." << endl;
                break;

            case 3:
                if(s1.isEmpty())
                {
                    cout << "Stack is empty" << endl;
                }
                else
                {
                    cout << "Stack is not empty" << endl;
                }
                break;
            case 4:
                if (s1.isFull())
                {
                    cout << "Stack is full" << endl;
                }
                else
                {
                    cout << "Stack is not full" << endl;
                }
                break;
            case 5:
                cout << "Enter the position of the number you want to see: " << endl;
                cin >> position;
                cout << "The number at index " << position << " is " << s1.peek(position) << endl;
                break;
            case 6:
                cout << "There are " << s1.count() << " number(s) in the stack" << endl;
                break;
            case 7:
                cout << "Enter the position of the number you want to change: ";
                cin >> position;
                cout << "\n Enter the value you want to replace the previous number with: ";
                cin >> value;
                cout << endl;
                s1.change(position, value);
                break;
            case 8:
                cout << "These are all the numbers in the stack: " << endl;
                s1.display();
                break;
            case 9:
                system("cls");
                break;
            default:
                cout << "Enter proper option number " << endl;
        }
    } while (option != 0);

    return 0;
}

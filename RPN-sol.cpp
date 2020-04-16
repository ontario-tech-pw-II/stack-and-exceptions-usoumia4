// RPN calculator

#include <iostream> 
#include <string>
#include <stack> 

using namespace std;
bool is_str_digit(string);          // returns true if input parameter string is and integer (e.g., "127343")
bool is_str_operator(string);       // returns true if the input parameter is an operator character (e.g., "+", "*")


int main() 
{
    string in;
    stack<string> st;

    cin >> in;

    try 
    {
        while(in != "q")
        {
            if(is_str_digit(in))
            {
                st.push(in);
            }
            else if(is_str_operator(in))
            {
                int value3 ;
                int value1 = stoi(st.top());
                st.pop();

                int value2 = stoi(st.top());
                st.pop();

                switch(in[0])
                {
                    case '+':
                        value3 = value2 + value1;
                        break;

                    case '-':
                        value3 = value2 - value1;
                        break;

                    case '*':
                        value3 = value2 * value1;
                        break;

                    case '/':
                        value3 = value2 / value1;
                        break;

                }
                st.push(to_string(value3));        
            }
            else 
                throw 1;

            cin >> in;
        }
        cout << "The answer is : " << st.top() << endl;

    }
    catch(int e)
    {
        switch(e){
            case 1: 
                cout << "The token is not operator nor integer !" << endl;
                break;
        }
    }
    
    return 0; 
}

bool is_str_digit(string s)
{
    for (int i = 0; i < s.length(); ++i)
    {
            if(!isdigit(s[i]))
                return false;
    }
    return true;
}
bool is_str_operator(string s)
{
    return (s.length()==1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0]== '/'));
}

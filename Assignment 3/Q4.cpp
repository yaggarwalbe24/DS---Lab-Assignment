#include <iostream>
using namespace std;
#define MAX 100
class Stack {
    int top;
    char arr[MAX];
public:
    Stack() {
        top = -1;
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == MAX - 1;
    }
    void push(char c) {
        if (!isFull()) {
            arr[++top] = c;
        }
    }
    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return '\0';
    }
    char peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        return '\0';
    }
};
int precedence(char c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}
void infixToPostfix(const char* infix, char* postfix) {
    Stack s;
    int i = 0, k = 0;
    char c;
    while ((c = infix[i]) != '\0') {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix[k++] = c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix[k++] = s.pop();
            }
            if (!s.isEmpty() && s.peek() == '(') {
                s.pop();
            }
        } else if (isOperator(c)) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                if (c == '^' && s.peek() == '^') {
                    break;
                } else {
                    postfix[k++] = s.pop();
                }
            }
            s.push(c);
        }
        i++;
    }
    while (!s.isEmpty()) {
        postfix[k++] = s.pop();
    }
    postfix[k] = '\0';
}
int main() {
    char infix[MAX], postfix[MAX];
    cout << "Enter infix expression:\n";
    cin.getline(infix, MAX);
    infixToPostfix(infix, postfix);
    cout << "Postfix expression:\n" << postfix << endl;
    return 0;
}

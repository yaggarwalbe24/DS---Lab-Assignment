#include <iostream>
using namespace std;
#define MAX 100
class Stack {
    int top;
    int arr[MAX];
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
    void push(int value) {
        if (!isFull()) {
            arr[++top] = value;
        }
    }
    int pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return -1;
    }
};
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
int evaluatePostfix(const char* expr) {
    Stack s;
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (c == ' '){
            continue;
        }
        if (c >= '0' && c <= '9') {
            int num = 0;
            while (c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
                i++;
                c = expr[i];
            }
            i--;
            s.push(num);
        } else if (isOperator(c)) {
            int val2 = s.pop();
            int val1 = s.pop();
            int result;

            switch (c) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
            }
            s.push(result);
        }
    }
    return s.pop();
}
int main() {
    char expr[MAX];
    cout << "Enter postfix expression:\n";
    cin.getline(expr, MAX);
    int result = evaluatePostfix(expr);
    cout << "Result: " << result << endl;
    return 0;
}
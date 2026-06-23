#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct BiTNode {
	char data;
	BiTNode* lchild;
	BiTNode* rchild;
	BiTNode(char ch) : data(ch), lchild(NULL), rchild(NULL) {}
};

int priority(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return 0;
}

void createSubTree(stack<BiTNode*>& nodeStack, stack<char>& opStack) {
	char op = opStack.top();
	opStack.pop();

	BiTNode* right = nodeStack.top();
	nodeStack.pop();
	BiTNode* left = nodeStack.top();
	nodeStack.pop();

	BiTNode* root = new BiTNode(op);
	root->lchild = left;
	root->rchild = right;
	nodeStack.push(root);
}

BiTNode* createExpressionTree(const string& exp) {
	stack<BiTNode*> nodeStack;
	stack<char> opStack;

	for (int i = 0; i < (int)exp.length(); i++) {
		char ch = exp[i];
		if (ch == '=') break;

		if (ch >= '0' && ch <= '9') {
			nodeStack.push(new BiTNode(ch));
		}
		else if (ch == '(') {
			opStack.push(ch);
		}
		else if (ch == ')') {
			while (!opStack.empty() && opStack.top() != '(') {
				createSubTree(nodeStack, opStack);
			}
			if (!opStack.empty()) opStack.pop();
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			while (!opStack.empty() && opStack.top() != '(' &&
				priority(opStack.top()) >= priority(ch)) {
				createSubTree(nodeStack, opStack);
			}
			opStack.push(ch);
		}
	}

	while (!opStack.empty()) {
		createSubTree(nodeStack, opStack);
	}
	return nodeStack.empty() ? NULL : nodeStack.top();
}

int evaluate(BiTNode* root) {
	if (root == NULL) return 0;
	if (root->data >= '0' && root->data <= '9') {
		return root->data - '0';
	}

	int leftValue = evaluate(root->lchild);
	int rightValue = evaluate(root->rchild);

	switch (root->data) {
	case '+': return leftValue + rightValue;
	case '-': return leftValue - rightValue;
	case '*': return leftValue * rightValue;
	case '/': return leftValue / rightValue;
	default: return 0;
	}
}

void destroyTree(BiTNode* root) {
	if (root == NULL) return;
	destroyTree(root->lchild);
	destroyTree(root->rchild);
	delete root;
}

int main() {
	string exp;
	while (cin >> exp) {
		if (exp == "=") break;
		BiTNode* root = createExpressionTree(exp);
		cout << evaluate(root) << endl;
		destroyTree(root);
	}
	return 0;
}

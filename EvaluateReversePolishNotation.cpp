//Evaluate Reverse Polish Notation

bool isOperation(string token) {
	return token == "+" || token == "-" || token == "*" || token == "/";
}

int evalRPN(vector<string>& tokens) {
	stack<int> s;
	for (int i = 0; i < tokens.size(); i++) {
		string token = tokens[i];
		if (isOperation(token)) {
			int op2 = s.top();
			s.pop();
			int op1 = s.top();
			s.pop();
			int res = 0;
			if (token == "+")
				res = op1 + op2;
			else if (token == "-")
				res = op1 - op2;
			else if (token == "*")
				res = op1 * op2;
			else
				res = op1 / op2;
			s.push(res);
		} else {
			s.push(atoi(token.c_str()));
		}
	}
	return s.top();
}
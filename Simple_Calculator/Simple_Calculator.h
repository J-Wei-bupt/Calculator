#pragma once

#ifndef SIMPLE_CALCULATOR_H_
#define SIMPLE_CALCULATOR_H_

#include <iostream>
#include<string>
#include<vector>
#include<stack>
#include<stdlib.h>

#include<iomanip>

using namespace std;

void calculator(string str) {
	string::iterator it = str.begin();
	stack<char> s1;
	stack<double> s2;
	while (it != str.end()) {  
		if (isdigit(*it) != 0) { //输入数字
			s2.push(double(*it - '0') );
		}
		else if (s1.empty() ||  s1.top() == '(') s1.push(*it);  //输入第一个运算符（除去括号
		else { //运算
			//cout << ":::::::::::::::::s1.top()" << s1.top() << endl;
			//cout << ":::::::::::::::::s2.top()" << s2.top() << endl;
			switch (*it) {
			case '(':  //‘（’直接存
				s1.push(*it);
				break;
			case ')': //‘）’计算到‘（’
				while (s1.top() != '(') {
					double num2 = s2.top();   s2.pop(); //计算
					double num1 = s2.top();   s2.pop();
					switch (s1.top()) {
					case '+':
						s2.push(num1 + num2); break;
					case '-':
						s2.push(num1 - num2); break;
					case '*':
						s2.push(num1 * num2); break;
					case '/':
						s2.push(num1 / num2); break;
					}
					s1.pop();
				}
				s1.pop();//pop‘（’
				break;
			case '*':
			case '/':
				switch (s1.top()) {
				case '+':
				case '-':
					s1.push(*it); break;
				case '*':
				case '/':
					double num2 = s2.top();   s2.pop();
					double num1 = s2.top();   s2.pop();
					if (s1.top() == '*') s2.push(num1 * num2);
					else   s2.push(num1 / num2);
					s1.pop();
					s1.push(*it);
					break;
				}
				break;
			case '+':
			case '-':
				double num2 = s2.top();   s2.pop();
				double num1 = s2.top();   s2.pop();
				if (s1.top() == '+') s2.push(num1 + num2);
				else if (s1.top() == '-') s2.push(num1 - num2);
				else if (s1.top() == '*') s2.push(num1 * num2);
				else   s2.push(num1 / num2);
				s1.pop();
				s1.push(*it);
				break;
			}
		}
		//cout << ":::::::::::::::::*it" << *it << endl;
		

		++it;
	}
	//cout << "zhezhezhezhezhes1.top()" << s1.top() << endl;
	//cout << "zhezhezhezhezhes2.top()" << s2.top() << endl;
	//栈内残余
	while(!s1.empty()){
		double num2 = s2.top();
		s2.pop();
		double num1 = s2.top();
		s2.pop();
		if (s1.top() == '+') s2.push(num1 + num2);
		else if (s1.top() == '-') s2.push(num1 - num2);
		else if (s1.top() == '*') s2.push(num1 * num2);
		else   s2.push(num1 / num2);
		s1.pop();
	}
		cout << s2.top() << endl;
		s2.pop();
	
}


#endif


#pragma once

//计算器系统
class Calculator
{
private:
	CString expression;	//中缀表达式
	CString post_expression;	//后缀表达式
	CString result;	//计算结果(字符串)
	double _result;	//计算结果
	bool isShow;		//标志
public:
	Calculator();
	~Calculator();
	void AddChar(char* ch);	//按下按键增加字符
	void MakeZero();	//归零
	void DelChar();	//回删
	void ShowResult(bool EnSave);	//显示结果

private:
	bool _CalcuResult();		//计算结果
	void _ShowExpression();	//显示中缀表达式
	void _ShowResult();		//显示结果
	void _SaveToFile();		//保存记录
	bool _EnCalcu();		//判断是否可以计算结果
	bool _JudgeChar(char ch);	//判断运算符
	bool _SwitchChar(char ch);		//判断并计算
	bool _SelfSub(int &index, char ch);	//符号运算
	void _CStrToStr(std::string &obj1, CString obj2);//将CString转化为string
	bool _GetNum(double &num, int &index);	//从字符串中提取操作数
	CString _DelPostZero(double num);	//去除尾部的零
};


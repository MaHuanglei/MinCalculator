#include "stdafx.h"
#include "Calculator.h"
#include "���׼�����Dlg.h"

extern C���׼�����Dlg *pDlg;
extern HWND g_hWnd;
std::stack<char> charStack;
std::stack<double> numStack;


Calculator::Calculator()
{
	isShow = false;
}

Calculator::~Calculator()
{
	
}

void Calculator::AddChar(char* ch)
{
	if (isShow)
	{
		MakeZero();
		_ShowResult();
		isShow = false;
	}
	if (_JudgeChar(*ch))expression += ch;
	_ShowExpression();

	if (_EnCalcu())
		ShowResult(false);
}

void Calculator::MakeZero()
{
	expression.Empty();
	post_expression.Empty();
	result.Empty();
	_result = 0;

	_ShowExpression();
	_ShowResult();
}

void Calculator::DelChar()
{
	expression.Delete(expression.GetLength() - 1, 1);
	_ShowExpression();

	if (_EnCalcu())
		ShowResult(false);
	else
	{
		result = "";
		_ShowResult();
	}
}

void Calculator::ShowResult(bool EnSave)
{
	if (expression.IsEmpty())
		return;
	if (_CalcuResult())
	{
		_ShowResult();
		if (EnSave)
		{
			_SaveToFile();
			isShow = true;
		}
	}
}

bool Calculator::_CalcuResult()
{
	
	while (!charStack.empty())charStack.pop();
	while (!numStack.empty())numStack.pop();
	post_expression.Empty();
	result.Empty();
	_result = 0;

	double num;
	char temp; int index = 0;
	while (index < expression.GetLength())
	{
		switch (expression[index])
		{
		case '(':
			charStack.push('(');
			index++;
			break;
		case ')':
		{
					temp = charStack.top();
					charStack.pop();
					while (temp != '(')
					{
						if (charStack.empty())
						{
							result = "�������Ų�ƥ��";
							_ShowResult();
							return false;
						}
						post_expression += temp;
						if (!_SwitchChar(temp))
							return false;
						temp = charStack.top();
						charStack.pop();
					}
					index++;
		}
			break;
		case '+':
		case '-':
		{
					if (_SelfSub(index, expression[index]))
					{
						break;
					}
					while (!charStack.empty() && charStack.top() != '(')
					{
						temp = charStack.top();
						post_expression += temp;
						charStack.pop();
						if (!_SwitchChar(temp))
							return false;
					}
					if (expression[index] == '+')
						charStack.push('+');
					else charStack.push('-');
					index++;
		}
			break;
		case '*':
		case '/':
		{
					while (!charStack.empty() && (charStack.top() == '*' || charStack.top() == '/'))
					{
						temp = charStack.top();
						post_expression += temp;
						charStack.pop();
						if (!_SwitchChar(temp))
							return false;
					}
					if (expression[index] == '*')
						charStack.push('*');
					else charStack.push('/');
					index++;
		}
			break;
		default:
			if (_GetNum(num, index))
			{
				numStack.push(num);
				post_expression += _DelPostZero(num);
			}
			else return false;
			break;
		}
	}
	while (!charStack.empty())
	{
		
		temp = charStack.top();
		if (temp == '(')
		{
			result = "�������Ų�ƥ��";
			_ShowResult();
			return false;
		}
		post_expression += temp;
		charStack.pop();
		if (!_SwitchChar(temp))
			return false;
	}

	_result = numStack.top();
	numStack.pop();
	while (!numStack.empty())
	{
		_result *= numStack.top();
		numStack.pop();
		post_expression += "*";
	}
	result = _DelPostZero(_result);
	return true;
}

void Calculator::_ShowExpression()
{
	if (pDlg->m_list.GetCount() != 0)
		pDlg->m_list.DeleteString(0);
	pDlg->m_list.AddString(expression);

	if (expression.GetLength() > 30)
		MessageBox(g_hWnd, _T("���ʽ���ȹ���"), _T("��ʾ"), MB_OK);
}

void Calculator::_ShowResult()
{
	if (pDlg->m_outList.GetCount() == 1)
		pDlg->m_outList.DeleteString(0);
	pDlg->m_outList.AddString(result);
	if (result.GetLength() > 30)
		MessageBox(g_hWnd, _T("���������ȹ���"), _T("��ʾ"), MB_OK);
}

void Calculator::_CStrToStr(std::string &obj1, CString obj2)
{
#ifndef UNICODE
	obj1 = obj2;
#else
	USES_CONVERSION;
	obj1 = W2A(obj2.LockBuffer());
	obj2.UnlockBuffer();
#endif
}

void Calculator::_SaveToFile()
{
	CTime time = CTime::GetCurrentTime();
	CString cstrTime, tempExpre, tempPost;
	cstrTime.Format(L"%s%s%s",_T("ʱ�䣺"), time.Format("%Y-%m-%d %H:%M:%S"),_T("\r\n"));
	tempExpre = _T("�������ʽ��") + expression + _T(" = ") + result + _T("\r\n");
	tempPost = _T("��׺���ʽ��") + post_expression + _T("\r\n\r\n");

	std::string strTime;
	_CStrToStr(strTime, cstrTime);
	std::string strPre;
	_CStrToStr(strPre, tempExpre);
	std::string strPost;
	_CStrToStr(strPost, tempPost);

	std::fstream file;
	file.open(_T("���׼�������־.txt"), std::ios::out | std::ios::app);
	if (!file)
	{
		MessageBox(g_hWnd, _T("��־�ļ���ʧ��"), _T("��ʾ"), MB_OK);
		return;
	}
	file.write(strTime.c_str(),strTime.size());
	file.write(strPre.c_str(), strPre.size());
	file.write(strPost.c_str(), strPost.size());
	file.close();
}

bool Calculator::_JudgeChar(char ch)
{
	if ('0' <= ch&&ch <= '9')
		return true;

	char temp; bool flag = true;
	if (!expression.IsEmpty() && expression[expression.GetLength() - 1] == '('&&ch == ')')
	{
		// �����ʽ��Ϊ�����߱��ʽ���һ���ַ�Ϊ'('��������ӵ��ַ�Ϊ')'����Ϊ��Ч����
		flag = false;
	}
	else if (expression.IsEmpty() || expression[expression.GetLength() - 1] == '(')
	{
		// �����ʽΪ�ջ��߱��ʽ���һ���ַ�Ϊ'('��������ӵ��ַ�Ϊ')'��'+
		// ��'*'��'/'��'.'����Ϊ��Ч����
		switch (ch)
		{
		case '+':
		case '*':
		case '/':
		case ')':
		case '.':
			flag = false;
			break;
		default:
			break;
		}
	}

	if (!expression.IsEmpty() && ((temp = expression[expression.GetLength() - 1]) == '+' || temp == '-' || temp == '*'
		|| temp == '/' || temp == '.'))
	{
		//�ж��Ƿ������������������
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '.')
		{
			flag = false;
		}
	}

	return flag;
}

bool Calculator::_EnCalcu()
{
	bool flag = false;
	int index = expression.GetLength() - 1;
	while (index >= 0)
	{
		switch (expression[index])
		{
		case '+':
		case '-':
		case '*':
		case '/':
		case '(':
		case ')':
			flag = true;
			break;
		default:
			break;
		}
		if (flag)break;
		index--;
	}
	
	return flag;
}

bool Calculator::_SelfSub(int &index,char ch) 
{
	if (ch != '-')return false;

	if (index == 0 || (expression[index-1] == '('))
	{
		double num; index += 1;
		if(_GetNum(num, index))
			numStack.push(0 - num);
		else
		{
			numStack.push(0);
		}
		return true;
	}
	return false;
}

bool Calculator::_SwitchChar(char ch)
{
	if (numStack.empty())
	{
		result = "����ȱ�ٲ�����";
		_ShowResult();
		return false;
	}
	double num2 = numStack.top();
	numStack.pop();

	if (numStack.empty())
	{
		result = "����ȱ�ٲ�����";
		_ShowResult();
		return false;
	}
	double num1 = numStack.top();
	numStack.pop();

	switch (ch)
	{
	case '+':
		numStack.push(num1 + num2);
		break;
	case '-':
		numStack.push(num1 - num2);
		break;
	case '*':
		numStack.push(num1 * num2);
		break;
	case '/':
		if (num2 == 0)
		{
			result = "���󣬳�������Ϊ0";
			_ShowResult();
			return false;
		}
		numStack.push(num1 / num2);
		break;
	}
	return true;
}

bool Calculator::_GetNum(double &num,int &begin)
{
	if (begin >= expression.GetLength())
		return false;

	int length = begin; num = 0;
	while ((expression[length] <= '9'&&expression[length] >= '0') || expression[length] == '.')
		length++;
	length -= begin;
	CString temp = expression.Mid(begin,length);
	begin += length;

	int i = 0;
	int index_point;
	if (temp.Find('.') > -1)
	{
		index_point = temp.Find('.');
		while (i < index_point)
		{
			num = num * 10 + (temp[i] - '0');
			i++;
		}
		double tempNum = 0; 
		i = length - 1;
		while (i > index_point)
		{
			tempNum = tempNum * 0.1 + (temp[i] - '0') * 0.1;
			i--;
		}
		num += tempNum;
	}
	else
	{
		while (i < length)
		{
			num = num * 10 + (temp[i] - '0');
			i++;
		}
	}

	return true;
}

CString Calculator::_DelPostZero(double num)
{
	CString temp;
	temp.Format(_T("%lf"), num);
	int index = temp.Find('.');
	int i = temp.GetLength() - 1;
	while (i >= index)
	{
		if (temp[i] == '0' || temp[i] == '.')
		{
			temp.Delete(i, 1);
			i--;
		}
		else break;
	}
	return temp;
}
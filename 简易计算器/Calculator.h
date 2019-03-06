#pragma once

//������ϵͳ
class Calculator
{
private:
	CString expression;	//��׺���ʽ
	CString post_expression;	//��׺���ʽ
	CString result;	//������(�ַ���)
	double _result;	//������
	bool isShow;		//��־
public:
	Calculator();
	~Calculator();
	void AddChar(char* ch);	//���°��������ַ�
	void MakeZero();	//����
	void DelChar();	//��ɾ
	void ShowResult(bool EnSave);	//��ʾ���

private:
	bool _CalcuResult();		//������
	void _ShowExpression();	//��ʾ��׺���ʽ
	void _ShowResult();		//��ʾ���
	void _SaveToFile();		//�����¼
	bool _EnCalcu();		//�ж��Ƿ���Լ�����
	bool _JudgeChar(char ch);	//�ж������
	bool _SwitchChar(char ch);		//�жϲ�����
	bool _SelfSub(int &index, char ch);	//��������
	void _CStrToStr(std::string &obj1, CString obj2);//��CStringת��Ϊstring
	bool _GetNum(double &num, int &index);	//���ַ�������ȡ������
	CString _DelPostZero(double num);	//ȥ��β������
};


#pragma once
int Add(int left, int right);
//�������
//�����ȷʹ�÷�������ͷ�ļ�����Ȼ��ѳ�Ա�����Ķ������/
//.cpp�ļ��У�
class Date
{
private:
	int _year;
	int _month;//Ĭ�ϳ�Ա������˽��
	//��Ա�����ǹ���
	int _day;//���������������Ҫ��־�ǿ��ռ�(����ʵ����)
public:
	void Init(int year, int month, int day);
};
//֮��Ժ��������ʱ����Ҫ�ں���ǰ���Date::
//Ҳ����������������ȥ�ң�

 
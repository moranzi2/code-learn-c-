#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//****************************************
//�ڴ����
//������1.�ں˿ռ䣨�û����벻�ܶ�д��
//2.ջ(��������)(����)
//3.�ڴ�ӳ���(�ļ�ӳ�䣬��̬�⣬����ӳ��)
//4.�ѣ�����������(malloc)
//5.���ݶΣ�ȫ�����ݣ���̬���ݣ�(��̬��)
//6.����Σ���ִ�д��룬ֻ��������(������)

//int main()
//{
//	char char2[] = "abcd";
//	//abcd�ڳ�����������ջ������һ�����飬���a��bcd��
//	//���*char2��ջ��
//	const char char3[] = "abds";//����һ����������Ĺ���;
//	//char3Ҳ��ջ����*char3�ڳ�����;
//
//class ListNode
//{
//public:
//	ListNode* _next;
//	ListNode* _prev;
//	int val;
//	ListNode(int vla)
//		:val (vla)
//	{
//
//	}
//};
//int main()
//{
//	//c++�ڴ������
//	int* p1 = new int;
//	int* p2 = new int[10];//��Ҫʮ��int��С�Ŀռ����
//	delete p1;
//	delete[]p2;//���new[]��ҲҪ����[]��
//	//���Կ��Ƴ�ʼ����
//	int* p3 = new int(10);//newһ��int��ʼ��Ϊ10;
//	int* p4 = new int[10] {1, 2, 3, 4, 5};//new������ʼ��;
//	delete p3;
//	delete[]p4;
//	//newһ���Զ�������,���ռ�ӹ��캯��;
//	//newʧ���Ժ��Լ������쳣������Ҫ�ֶ����;
//	ListNode* node1 = new ListNode(1);
//	try {
//		
//	}
//	catch (const exception& e)//�����쳣
//	{
//		cout << e.what() << endl;
//	}
//	//operator new�Ƕ�malloc��װ��operator free�Ƕ�free��װ;
//	//����ûʲô��,����ϵͳ���õ�;
//}
class A {
public:
	A()
	{
		cout << "coutA->" << endl;
	}
	~A()
	{
		cout << "cout~A->" << endl;
	}
private:
	int a;
};
//int main()
//{
//	A* p1 = new A; //����Լ�û��д�������ǾͲ��ô��ˣ���Ϊ��ֱ�Ӳ�������
//	A* p2 = new A[10];//ʵ���Ͽ�����11��int�Ŀռ䣬��ǰ��Ŀռ����һ��10����������������Ӧ����������
//	int* b = new int[10];//����ʮ��int�ռ�
//	delete[] p2;//����ʮ��+operator delete
//	//new�ĵײ���ʵ����malloc�����ǿ���Ū�Զ������ͣ�
//	//���ҿ����Զ����ù��캯�����㲢���Զ����;
//	//new=operator new+���캯��;operator new=malloc;
//	//sizeof()�����,�����ʱ����Ѿ��������;
//	//strlen���������е�ʱ���ٽ���;
//	//newҲ��һ���������������ʱ��ֱ��ת��Ϊoperator new;
//}

//int main()
//{
//	//��ʽ���ù��캯������������;
//	A* p2 = (A*)operator new(sizeof(A));
//	//�ڴ��;//��΢�˽�
//	new(p2)A();
//	p2->~A();
//	operator delete(p2);
//}


///////////////////////////////////////
//malloc/free��new/delete����;
//1.malloc��free�Ǻ���
//2.malloc����Ŀռ䲻���ʼ��
//3.malloc����ռ���Ҫ���㴫�ݿռ��С��newֻ��Ҫ���Ͽռ�����ͺ�����
//4.malloc����ֵ��void*����Ҫǿת��new����
//5.malloc��Ҫ�ж��Ƿ�ΪNULL��new�Լ��Ჶ���쳣
//6.malloc/free������ù��캯����������������new����ù��캯������������;

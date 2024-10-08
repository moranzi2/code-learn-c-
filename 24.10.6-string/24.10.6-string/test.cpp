//#define  _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using std::swap;
//int main()
//{
//	int i = 0, t = 5;
//	swap(i, t);
//}
////��ģ�������Ͷ��岻���ڲ�ͬ�ļ�

//ctrl+f����;
#include<iostream>
#include<string>
using namespace std;
void test2()
{
	string s1("hello world");
	//string��size������/0;
	//s2.end()Ϊ\0���ڵ�λ��;
	for (size_t i = 0; i < s1.size(); i++)
	{
		//��ʵ����������[]
		cout << s1[i] << " ";
		cout << s1.operator[](i) << " ";
	}
	cout << endl;
	string::iterator it1 = s1.begin();//����������ָ�뵫����Ϊ����ָ��;
	while (it1 != s1.end())//end�����һ�����ݵ���һ��λ��;
	{
		cout << *it1 << " ";
	}
	//��Χfor���Ա�������
	//�ײ���ʵ���ǵ�����;
	for (auto e : s1)
	{
		cout << e << " ";
	}
}
void test3()
{
	//���������,�Ӻ���ǰ����;
	string s1("hello world");
	string::reverse_iterator rit = s1.rbegin();
		while (rit != s1.rend())
		{
			cout << *rit << " ";
			++rit;//��Ȼ��++;
	}
		cout << endl;
		//const������,�����ط�����;
		//��ͨ�������ǿɶ���д�ģ�����const������ֻ��;
		const string s2("hello world");
		//����һ��const_reverse_iterator;ֻ�����������;
		string::const_iterator it = s2.begin();
		while (it != s2.end())
		{
			cout << *it << " ";
			++it;
		}
}

//reserve ��������,��������
//reverse ��ת,��ת����ת������;
void test4()
{
	string s1("hello world");
	cout << s1.size() << endl;//size��length��ʵ��һ����;��������\0
	cout << s1.length() << endl;
	cout << s1.max_size() << endl;//�������;
	cout << s1.capacity() << endl;//����;
	s1.clear();//��������ݣ�������������;
	//Ϊ�˽���������ݺ������˷�
	s1.shrink_to_fit();//����;��������0;
	//��֪����Ҫ����������ݵ�ʱ�������ǰ���ÿռ�;
	s1.reserve(100);//��ǰ�����ռ�,Ҳ��������;���Ǳ�capacityС��ʱ�򲻻�����;
	//string��ʵ���ϲ����������ַ�\0��Ϊ�ַ����������жϻ��ƣ����ǿ�size����˿��Գ���\0��
	s1.resize(10);//�ı�size�������sizeС���Ǿ�ɾ������size�󣬾Ͳ�����ַ�\0����capacity�󣬾�����
	cout << s1.size() << endl;
	s1.resize(20, 'a');//������size������a;
	cout << s1.size() << endl;
}
void test5()
{
	string s1("hello world");
	
	//[]��at�Ĺ�����һ���ģ�
	//operator[]����;
	cout << s1[4] << endl;//assert���Է�ֹԽ��
    //��Ա����at;
	cout << s1.at(4) << endl;//���쳣��ֹԽ��
	cout << s1.front() << endl;//ͷ
		cout << s1.back() << endl;//β
}
void test6()
{
	string s1("hello world");
	s1.push_back('!');//����һ���ַ�;
	cout << s1 << endl;
	s1.append("hello bit");//����һ���ַ�������string;
	    //string& append(const string & str);����string
		//string& append(const string & str, size_t subpos, size_t sublen);string��subpos��sublen��
		//string & append(const char* s);���ַ���
		//string& append(const char* s, size_t n);���ַ���ǰn����
		//string& append(size_t n, char c);��n���ַ�
		//template <class InputIterator>   string& append(InputIterator first, InputIterator last);
	 //����
	string s2(" hello ");
	s1.append(++s2.begin(), --s2.end());

	//����+=,����+=�ַ�����string���ַ�;
	s1 += s2;
	s1 += "appel";
	s1 += '  ';


	//assign��ֵ
	s1.assign("xxxxx");//ֱ�Ӷ�ԭ���Ŀռ���и��ǣ��������ݣ��ӿں�append�����캯������;
	

	//insert����
	s1.insert(0, "yyyy");//��posλ�ò��������ַ�������string;

	//eraseɾ��;
	s1.erase(2, 4);//���±�2λ��ɾ�������4���ַ�,Ĭ��Ϊ-1��Ҳ����ȫ��ɾ��;
	s1.erase();//ȫȱʡ�Ļ��൱��clear;

	//replace���ض�λ�õĵط��ļ����ַ��滻Ϊ�ַ�������string���Լ���ӿ�
	string s3("hello world");
	s3.replace(5, 1, "%20");
	//insert,erase,replace�����������ã�����ҪŲ�����ݣ�Ч�ʽϵ�;
	//find Ѱ��һ���ַ������ַ���; ���û�ҵ���return npos;Ҳ����size_t -1
}

class Solution {
public:
	bool isLetter(char s)
	{
		if (s >= 'a' && s <= 'z')
			return true;
		if (s >= 'A' && s <= 'Z')
			return true;
		else
			return false;
	}
	string reverseOnlyLetters(string s) {
		size_t left = 0;
		size_t right = s.size()-1;
		while (left < right)
		{
			while (left < right && !isLetter(s[left]))
				left++;
			while (left < right && !isLetter(s[right]))
				right--;
			swap(s[left], s[right]);
			++left;
			--right;
		}
		return s;
	}
};
int main()
{
	string s1("s   ");
	Solution s2;
	s2.reverseOnlyLetters(s1);
	//���캯��
	//1.string();
	//2.string (const string& str);������������string����
	//3.string (const string& str, size_t pos, size_t len = npos);���������pos��ʼ��ǰn��
	//4.string (const char* s);��������һ���ַ���
	//5.string (const char* s, size_t n);���������ַ�����ǰn����
	//6.string (size_t n, char c)����n��c��ĸ
}
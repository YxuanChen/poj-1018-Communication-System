#include<iostream>
#include<vector>
#include<algorithm>
#include <iomanip> 
using namespace std;

//�洢����۸�Ľ��
struct node
{
	double b;//����
	double p;//�۸�
};

//
//void Swap(double a, double b)
//{
//	double temp = a;
//	a = b;
//	b = temp;
//};
//
//int Partition(double* a, int p, int r)
//{
//	int i = p, j = r + 1;
//	double x = a[p];
//	while (true)
//	{
//		while (a[++i] < x);
//		while (a[--j] > x);
//		if (i >= j)
//			break;
//		double temp = a[i];
//
//		Swap(a[i], a[j]);
//	}
//	a[p] = a[j];
//	a[j] = x;
//	return j;
//};
//
////����
//void QuickSort(double*a, int p, int r)
//{
//	if (p < r)
//	{
//		int q = Partition(a, p, r);
//		QuickSort(a, p, q - 1);
//		QuickSort(a, q + 1, r);
//	}
//};
//
////ð������
//void Sort(double* a,int length){
//	for (int i = 0; i < length; i++)
//	{
//		
//		for (int j = i; j < length; j++)
//		{
//
//			if (a[i]>a[j])
//			{
//				int temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//				
//			}
//		}
//	
//	}
//};

int main()
{
	int firstR;//�ܹ��ж��ٸ���������
	int t;//������Ҫ���ٸ��豸��0<t<=10)
	int n;//һ���豸�ж��ټ��̼ҿ����ṩ��0<n<=100)
	node a[100][100];//�洢ÿһ���̼ҵĴ���۸���ֵ
	vector<double> b;//���������
	//double *b1;//����b
	vector<int> num;//ÿһ���豸�ṩ�̵����������ں�����ȡÿһ���̼ҵļ۸�
	vector<double>bp;//����b/p�Ľ������
	double *allResult;//ÿ���������������ս��

	int size=0;//b����Ĵ�С
	int cases = 0;//�ڼ�����������
	int r ;//����a�ڼ���
	
	//������ٸ��豸
	cin >> firstR;
	//ΪallResult����ռ�
	allResult = new double[firstR];
	for (int i = 0; i < firstR; i++)
	{
		allResult[i] = 0;
	}
	int tempF = firstR;
	
	//������ֵ�ʹ���
	while (firstR--)
	{
		//��r��0��ʹ��֮��ÿһ�������ֵ��ͷ��ʼ�洢
		r = 0;
		//��������������豸��
		cin >> t;
		int temp = t;
		//����ÿһ�е���ֵ
		while (t--)
		{
			cin >> n;
			for (int i = 0; i < n; i++){
				cin >> a[r][i].b >> a[r][i].p;
				b.push_back(a[r][i].b);
			}
			num.push_back(n);//��¼ÿһ���豸�Ĺ�Ӧ������
			r++;
		}

		size = b.size();

		sort(b.begin(), b.end());

		//��b���Ƶ�b1
		/*size = b.size();
		b1 = new double(size);
		for (int i = 0; i < b.size(); i++)
		{
		b1[i] = b[i];
		}*/
		//QuickSort(b1, 0, b.size() - 1);//�Դ����������
		//Sort(b1,size);//�Դ����������

		double sumPrice = 0;//����ÿһ��ѡ��Ĵ���ļ۸��ܺ�
		bool out = false;//�����Ƿ�����ѭ������Ҫ�ٽ��У�һ����һ������û�н⣬�������Ķ�������Ч�⣩
		for (int i = 0; i < size; i++)//�����С�������μ�������ֵ
		{
			double sumPrice = 0;//����۸��ܺ�
			for (int j = 0; j < temp; j++)//�豸
			{
				double price = 0;//�۸�
				for (int k = 0; k < num[j]; k++)//�̼�
				{
					if (a[j][k].b >= b[i])//�жϴ����Ƿ����Ҫ��
					{

						if (price == 0)//price��ʼ��ֵ
						{
							price = a[j][k].p;
						}
						if (a[j][k].p < price)//�и��͵ļ۸�ѡ��
						{
							price = a[j][k].p;
						}
					}
				}
				if (price == 0)//���һ���豸��û�з����������̼ң����ǽ�
				{
					out = true;
					break;
				}
				sumPrice += price;//��������ѡ���豸�۸��ܺ�
			}
			if (out)
			{
				break;
			}
			double result = b[i] / sumPrice;
			bp.push_back(result);
		}

		//�Ƚ�b/p����ֵ���
		double max = 0;
		for (int i = 0; i < bp.size(); i++)
		{
			if (i == 0)
			{
				max = bp[i];
			}
			else{
				if (bp[i]>max){
					max = bp[i];
				}
			}
		}

		allResult[cases] = max;
		cases++;

		//delete[]b1;
		b.clear();
		num.clear();
		bp.clear();
	}
	
	//��ӡֵ
	for (int i = 0; i < tempF; i++)
	{
		cout << fixed << setprecision(3) << allResult[i] << endl;
	}
	delete[] allResult;
	
	return 0;
}


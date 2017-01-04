#include<iostream>
#include<vector>
#include<algorithm>
#include <iomanip> 
using namespace std;

//存储带宽价格的结点
struct node
{
	double b;//带宽
	double p;//价格
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
////快排
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
////冒泡排序
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
	int firstR;//总共有多少个测试用例
	int t;//输入需要多少个设备（0<t<=10)
	int n;//一个设备有多少家商家可以提供（0<n<=100)
	node a[100][100];//存储每一行商家的带宽价格数值
	vector<double> b;//带宽的数组
	//double *b1;//复制b
	vector<int> num;//每一行设备提供商的数量，便于后面提取每一个商家的价格
	vector<double>bp;//最终b/p的结果数组
	double *allResult;//每个测试用例的最终结果

	int size=0;//b数组的大小
	int cases = 0;//第几个测试用例
	int r ;//数组a第几行
	
	//输入多少个设备
	cin >> firstR;
	//为allResult分配空间
	allResult = new double[firstR];
	for (int i = 0; i < firstR; i++)
	{
		allResult[i] = 0;
	}
	int tempF = firstR;
	
	//输入数值和处理
	while (firstR--)
	{
		//将r置0，使得之后每一次输入的值从头开始存储
		r = 0;
		//输入该用例所需设备数
		cin >> t;
		int temp = t;
		//输入每一行的数值
		while (t--)
		{
			cin >> n;
			for (int i = 0; i < n; i++){
				cin >> a[r][i].b >> a[r][i].p;
				b.push_back(a[r][i].b);
			}
			num.push_back(n);//记录每一个设备的供应商数量
			r++;
		}

		size = b.size();

		sort(b.begin(), b.end());

		//将b复制到b1
		/*size = b.size();
		b1 = new double(size);
		for (int i = 0; i < b.size(); i++)
		{
		b1[i] = b[i];
		}*/
		//QuickSort(b1, 0, b.size() - 1);//对带宽进行排序
		//Sort(b1,size);//对带宽进行排序

		double sumPrice = 0;//计算每一次选择的带宽的价格总和
		bool out = false;//设置是否后面的循环不需要再进行（一旦有一个带宽没有解，则比它大的都不是有效解）
		for (int i = 0; i < size; i++)//带宽从小到大依次计算最优值
		{
			double sumPrice = 0;//计算价格总和
			for (int j = 0; j < temp; j++)//设备
			{
				double price = 0;//价格
				for (int k = 0; k < num[j]; k++)//商家
				{
					if (a[j][k].b >= b[i])//判断带宽是否符合要求
					{

						if (price == 0)//price初始赋值
						{
							price = a[j][k].p;
						}
						if (a[j][k].p < price)//有更低的价格选择
						{
							price = a[j][k].p;
						}
					}
				}
				if (price == 0)//如果一个设备中没有符合条件的商家，则不是解
				{
					out = true;
					break;
				}
				sumPrice += price;//最终所有选择设备价格总和
			}
			if (out)
			{
				break;
			}
			double result = b[i] / sumPrice;
			bp.push_back(result);
		}

		//比较b/p最大的值输出
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
	
	//打印值
	for (int i = 0; i < tempF; i++)
	{
		cout << fixed << setprecision(3) << allResult[i] << endl;
	}
	delete[] allResult;
	
	return 0;
}


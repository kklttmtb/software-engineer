#include <iostream>
#include <stdio.h>

using namespace std;
#define LONG 50
int MaxSubsequenceSum(int Array[], int n)
{
	int tempSum, maxSum;
	maxSum = 0;
	for (int i = 0; i < n; i++)
	{
		tempSum = 0;
		for (int j = i; j < n; j++)
		{
			tempSum += Array[j];
			maxSum=(((tempSum) > (maxSum)) ? (tempSum) : (maxSum));
		}
	}
	return maxSum;
}

int main()
{

	int a[LONG], i = 0;
	int num;
	cout << "集合大小为：" << endl;
	scanf("%d", &num);
	cout << "请输入集合：" << endl;
	while (i < num)
	{
		scanf("%d", &a[i]);
		i++;
	}
	int maxSubSum = MaxSubsequenceSum(a, num);
	cout << "结果为" << maxSubSum << endl;
	system("pause");
	return 0;
}
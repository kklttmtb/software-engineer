#include <pch.h>

#include <CppUnitTest.h>
#include<stdio.h>
#include<stdlib.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int Array[50] = { -7,-6,-5,-4 }, n = 4;
			int tempSum, maxSum;
			maxSum = 0;
			for (int i = 0; i < n; i++)
			{
				tempSum = 0;
				for (int j = i; j < n; j++)
				{
					tempSum += Array[j];
					maxSum = (((tempSum) > (maxSum)) ? (tempSum) : (maxSum));
				}
			}
			Assert::AreEqual(0, maxSum);
		}
		TEST_METHOD(TestMethod2)
		{
			int Array[50] = { 7,-6,-5,4 }, n = 4;
			int tempSum, maxSum;
			maxSum = 0;
			for (int i = 0; i < n; i++)
			{
				tempSum = 0;
				for (int j = i; j < n; j++)
				{
					tempSum += Array[j];
					maxSum = (((tempSum) > (maxSum)) ? (tempSum) : (maxSum));
				}
			}
			Assert::AreEqual(15, maxSum);
		}
	};
}

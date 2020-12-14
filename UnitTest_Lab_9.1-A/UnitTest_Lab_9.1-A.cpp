#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_9.1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab91A
{
	TEST_CLASS(UnitTestLab91A)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			int k1 = 0;

			struct Student
			{
				unsigned NumGr;
				string prizv;
				Kurs kurs;
				Spec spec;
				unsigned Fiz = 5;
				unsigned Mat = 5;
				unsigned Inf = 4;
			};
			
			t = Mat_5(5, k1);
			
			Assert::AreEqual(t, 3);
		}
	};
}







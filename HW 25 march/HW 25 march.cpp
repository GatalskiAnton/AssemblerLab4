#include <iostream>

//int noduplicate(int* arr)
//{
//	int i = 1, count = 1;
//	while (arr[i])
//	{
//		++i;
//		++count;
//	}
//	return count;
//}


int* mixArr(int* arr1 , int* arr2)
{
	int size1, size2;
	size1 = _msize(arr1) / sizeof(int);
	size2 = _msize(arr2) / sizeof(int);
	int* res_arr = new int[size1+size2];
	for (int i = 0; i < size1; i++)
	{
		res_arr[i] = arr1[i];
	}
	for (int i = 0; i < size2; i++)
	{
		res_arr[i + size1] = arr2[i];
	}
	//bubble sort
	int temp = 0;
	for (int i = 0; i < size1+size2 - 1; i++) 
	{
		for (int j = 0; j < size1+size2 - i - 1; j++) 
		{
			if (res_arr[j] > res_arr[j + 1])
			{
				std::swap(res_arr[j], res_arr[j + 1]);
			}
		}
	}
	return res_arr;
}

int stringCmp( char str1[], char str2[])
{
	/* Сравнить две строки языка Си.*/

	int i = 0;
	while (i < std::max(std::strlen(str1), std::strlen(str2)))
	{
		if (str1[i] < str2[i])
			return -1;
		if (str1[i] > str2[i])
			return 1;
		++i;
	}
	//char str[] = { 'a', 'b' };
	//int length_ = std::max(std::strlen(str1), std::strlen(str2)),result = 0;
	//_asm
	//{
	//	movsx eax, byte ptr[str1]

	//	mov ecx, 0		//int i = 0;

	//	beg: 	//while (i < std::max(std::strlen(str1), std::strlen(str2)))
	//		cmp ecx, length_
	//		jge end

	//			/*mov eax,[str1]
	//			mov ebx,[str2]*/
	//			
	//			inc str1
	//			inc str2
	//		inc ecx
	//		jmp beg
	//	end:

	//}
	return 0;
}

int diagSum(int a[3][3])
{
	/*Вычислить сумму диагональных элементов статической
	квадратной матрицы.*/

	int sum = 0, i = 0;

	/*while (i < 3)
	{
		sum += a[i][i];
		++i;
	}*/
	_asm
	{
		//mov ecx,0		//int i = 0;

		//beg:		//while (i < 3)
		//	cmp ecx, 3
		//	jge end
		//	inc ecx
		//

		//	mov eax, a[12*ecx + ecx*4]
		//	add sum, ebx
		//	jmp beg
		//end:
		mov eax, a[0]
		mov sum, eax
	}
	return sum;
}


int main()
{
	int* arr1 = new int[5] { 3,2,5,4,1};
	int* arr2 = new int[5]{ 8,9,8,7,10 };
	int* arr3 = mixArr(arr1,arr2);
	int a[3][3] = 
	{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	std::cout << diagSum(a) << '\n';
}


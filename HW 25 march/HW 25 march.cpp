#include <iostream>
void noduplicate(int* &arr)
{
	int u_count = 0;
	for (int i = 0; i < _msize(arr) / sizeof(int); ++i)
	{
		bool flag = false;
		for (int j = i + 1; j < _msize(arr) / sizeof(int); ++j)
		{
			if (arr[i] == arr[j])
				flag = true;
		}
		if (!flag)
			u_count++;
	}
	int* res_arr = new int[u_count+1];
	res_arr[0] = u_count;//first element is number of unique elements
	int current = 1;
	for (int i = 0; i < _msize(arr) / sizeof(int); ++i)
	{
		bool flag = false;
		for (int j = 1; j < current; ++j)
		{
			if (res_arr[j] == arr[i])
				flag = true;
		}
		if (!flag)
		{
			res_arr[current] = arr[i];
			++current;
		}
	}
	arr = res_arr;
}


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
				std::swap(res_arr[j], res_arr[j + 1]);
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
	
	int a[3][3] =
	{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	int current = 0;
	int sum = 0;
	//i*4*кол-во j + j*4
	_asm
	{
		mov ecx, 0//int i = 0;
		beg:
			cmp ecx, 3
			jge end
				mov ebx, a[ecx*4]
				add sum, ebx
				inc ecx
			jmp beg
		end:
	}
	std::cout << sum << '\n';
}


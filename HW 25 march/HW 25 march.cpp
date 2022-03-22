#include <iostream>

//tasks 1-3 in HW 17.03.2022

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

int stringCmp(const char* str1,const char* str2)
{
	/* Сравнить две строки языка Си.*/

	/*int i = 0;
	while (i < std::min(std::strlen(str1), std::strlen(str2)))
	{
		if (str1[i] < str2[i])
			return -1;
		if (str1[i] > str2[i])
			return 1;
		++i;
	}*/
	int length_ = std::min(std::strlen(str1), std::strlen(str2)),result = 0;
	_asm
	{
		mov ecx, 0		//int i = 0;
		mov eax, str1
		mov ebx, str2

		beg:		//while (i < std::min(std::strlen(str1), std::strlen(str2)))
			cmp ecx, length_
			jge end

				mov edi, [eax][ecx*4]
				mov esi, [ebx][ecx*4]

				cmp edi, esi
				jge jge1		//if (str1[i] < str2[i])
					mov result,-1
					jmp end
				jge1:

				cmp edi,esi
				jle jle1		//if (str1[i] > str2[i])
					mov result, 1
					jmp end
				jle1:

			inc ecx
			jmp beg
		end:
	
	}
	return result;
}

void diagSum_s()
{
	/*Вычислить сумму диагональных элементов статической
	квадратной матрицы.*/

	/*while (i < n)
	{
		sum += matrix[i][i];
		++i;
	}*/
	const int n = 3;
	int matrix[n][n] =
	{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	int sum = 0;
	_asm
	{
		mov ecx, 0	//int i = 0;

		beg:		//while (i < n)
		cmp ecx, n
			jge end
				mov eax, ecx
				imul eax, 4
				mov edx, eax
				imul eax, n
				add eax, edx
				mov ebx, matrix[eax]
				add sum, ebx		//sum+= a[i][i]	
			inc ecx
			jmp beg
		end :
	}
	std::cout << sum << '\n';
}

void diagSum_d()
{
	/*Вычислить сумму диагональных элементов динамической
	квадратной матрицы*/

	const int n = 3;
	int** matrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = i + j + 1;
			std::cout << matrix[i][j] << " ";
		}
		std::cout << '\n';
	}

	/*while (i < n)
	{
		sum += matrix[i][i];
		++i;
	}*/

	int sum = 0;	
	_asm
	{
		mov ecx, 0		//int i = 0
		mov edx, matrix

		beg:
			cmp ecx, n		//while(i < n)
				jge end

				mov eax, [edx][ecx*4]
				mov ebx, [eax][ecx*4]
				add sum, ebx		//sum+= a[i][i]

				inc ecx
				jmp beg
		end:

	}
	std::cout << sum << '\n';
}

int main()
{
}
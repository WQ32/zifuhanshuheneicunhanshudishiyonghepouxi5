#include <stdio.h>


//前面学习的函数是指操作对象是字符串 ，与'\0'有关，但对整形数组，浮点型数组，结构体数组不适用


////内存函数 memcpy - 内存拷贝
//// void* memcpy(void*destination,const void*source,size_t num)   size_t num指拷贝多少个字节
//// 不处理重叠问题
////void* - 通用类型指针 
//
//struct S
//{
//	char name[100];
//	int age;
//};
//#include <assert.h>
//
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	void* ret = dest;
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		++(char*)dest;
//		++(char*)src;
//	}
//	return ret;
//}
//
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[5] = { 0 };
//	struct S arr3[2] = { {"Zhangsan",20},{"Lisi",18} };
//	struct S arr4[3] = {0};
//	// memcpy(arr2, arr1, sizeof(arr1));
//	my_memcpy(arr4, arr3, sizeof(arr3));
//	return 0;
//}

//C语言标准：
// memcpy 只要处理不重叠的内存拷贝就可以（他在VS编译下也可以处理重叠的，但不是标准）
// memmove 处理重叠内存的拷贝
//内存函数 memmove - 内存移动 处理内存重叠的情况
// void* memmove(void*destination,const void*source,size_t num)

#include <assert.h>
void* my_memmove(void* dest, const void* src, size_t num)
{
	void* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	if (dest > src)
	{
		while (num--)
		{
			*(char*)dest = *(char*)src;
			++(char*)dest;
			++(char*)src;
		}
	}
	else
	{
		while (num--)
		{
			*(char*)dest = *(char*)src;
			(char*)dest+=1;
			(char*)src+=1;
		}
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	//将12345拷贝到34567的位置上
	my_memmove(arr + 2, arr, 20);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
	//1 2 1 2 3 4 5 8 9 10
}

//内存函数 memcmp - 内存比较
#include <stdio.h>


//ǰ��ѧϰ�ĺ�����ָ�����������ַ��� ����'\0'�йأ������������飬���������飬�ṹ�����鲻����


////�ڴ溯�� memcpy - �ڴ濽��
//// void* memcpy(void*destination,const void*source,size_t num)   size_t numָ�������ٸ��ֽ�
//// �������ص�����
////void* - ͨ������ָ�� 
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

//C���Ա�׼��
// memcpy ֻҪ�����ص����ڴ濽���Ϳ��ԣ�����VS������Ҳ���Դ����ص��ģ������Ǳ�׼��
// memmove �����ص��ڴ�Ŀ���
//�ڴ溯�� memmove - �ڴ��ƶ� �����ڴ��ص������
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
	//��12345������34567��λ����
	my_memmove(arr + 2, arr, 20);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
	//1 2 1 2 3 4 5 8 9 10
}

//�ڴ溯�� memcmp - �ڴ�Ƚ�
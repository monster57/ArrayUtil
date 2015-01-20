#include "../expr_assert.h"
#include "arrayUtil.h"
void test_to_check_for_two_arrays_are_equal_for_right_condition(){
	int array1[] ={1,2,3};
	int array2[] ={1,2,3};
	int result;
	ArrayUtil arr1 ,arr2 ;
	arr1.base = array1;
	arr1.typeSize=sizeof(int);
	arr1.length = 3;
	arr2.base = array2;
	arr2.typeSize=sizeof(int);
	arr2.length = 3;
	result = areEqual(arr1,arr2);
	assertEqual(result, 1);
} 
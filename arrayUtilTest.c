#include "expr_assert.h"
#include "arrayUtil.h"
void test_to_check_for_two_arrays_are_equal_for_right_condition(){
	int array1[] ={1,2,3};
	int array2[] ={1,2,3};
	int result;
	ArrayUtil util1 = {array1 ,sizeof(int) ,3 } ;
	ArrayUtil util2 = {array2,sizeof(int),3} ;
	result = areEqual(util1,util2);
	assertEqual(result, 1);
} 

void test_to_check_for_two_arrays_are_not_Equal_for_different_sizes(){
	int array1[] ={1,2,3,4};
	int array2[] ={1,2,3};
	int result;
	ArrayUtil util1 = {array1, sizeof(int), 4} ;
	ArrayUtil util2 = {array2, sizeof(int), 3} ;
	result = areEqual(util1,util2);
	assertEqual(result, 0);
}

void test_to_create_new_array_and_check_for_all_element_is_0(){
	ArrayUtil array = create(sizeof(int),3);
	assertEqual(array.length,3);
	assertEqual(array.typeSize,sizeof(int));
	assertEqual(((int *)array.base)[0],0);
	assertEqual(((int *)array.base)[1],0);
	assertEqual(((int *)array.base)[2],0);

}

void test_to_check_the_size_of_array_is_greater_and_zero_is_added_to_new_places(){
	ArrayUtil array1 = create(sizeof(int),3);
	ArrayUtil array2;
	((char *)array1.base)[0]=1;
	((char *)array1.base)[1]=2;
	((char *)array1.base)[2]=3;
	array2 =  resize(array1,5);
	assertEqual(array2.length, 5);
	assertEqual(((char *)array2.base)[0],1);
	assertEqual(((char *)array2.base)[1],2);
	assertEqual(((char *)array2.base)[2],3);
	assertEqual(((char *)array2.base)[3],0);
	assertEqual(((char *)array2.base)[3],0);

}

void test_to_check_the_size_of_array_is_lesser_and_remove_extra_places(){
	ArrayUtil array1 = create(sizeof(int),4);
	ArrayUtil array2;
	((char *)array1.base)[0]=1;
	((char *)array1.base)[1]=2;
	((char *)array1.base)[2]=3;
	((char *)array1.base)[3]=4;
	array2 =  resize(array1,3);
	assertEqual(array2.length, 3);
	assertEqual(((char *)array2.base)[0],1);
	assertEqual(((char *)array2.base)[1],2);
	assertEqual(((char *)array2.base)[2],3);
}

void test_to_check_findIndex_returns_1_for_the_Index_of_2(){
	int index;
	int element = 2;
	ArrayUtil util = create(sizeof(int),3);
	((int *)util.base)[0]=1;
	((int *)util.base)[1]=2;
	((int *)util.base)[2]=3;
	index = findIndex(util, &element);
	assertEqual(index,1);
}

void test_to_check_findIndex_returns_charcter_index_for_character_array(){
	int index;
	int element = 'b';
	ArrayUtil array1 = create(sizeof(char),3);
	((char *)array1.base)[0]='a';
	((char *)array1.base)[1]='b';
	((char *)array1.base)[2]='c';
	index = findIndex(array1, &element);
	assertEqual(index,1);
}

void test_to_check_findIndex_returns_1_for_the_Index_of_two_point_five(){
	int index;
	float element = 2.5;
	ArrayUtil array1 = create(sizeof(float),3);

	((float *)array1.base)[0]=1.6;
	((float *)array1.base)[1]=2.5;
	((float *)array1.base)[2]=3.5;
	index = findIndex(array1, &element);
	assertEqual(index,1);
}

void test_to_check_findIndex_retruns_minus_one_index_of_given_element_(){
	int index;
	int element = 5;
	ArrayUtil array1 = create(sizeof(int),3);

	((int *)array1.base)[0]=1;
	((int *)array1.base)[1]=2;
	((int *)array1.base)[2]=3;
	index = findIndex(array1, &element);
	assertEqual(index,-1);
}



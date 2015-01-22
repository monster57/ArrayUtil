#define SIZEOF_INT sizeof(int)
#define SIZEOF_FLOAT sizeof(float)
#define SIZEOF_CHAR sizeof(char)
#define SIZEOF_DOUBLE sizeof(double)
#include <string.h>
#include <stdlib.h>

#include "expr_assert.h"
#include "arrayUtil.h"
int int_array[] ={1,2,3};
int result;
void test_areEqual_gives_1_when_two_integer_arrays_are_same(){
	ArrayUtil util1 = {int_array,SIZEOF_INT ,3 } ;
	result = areEqual(util1,util1);
	assertEqual(result, 1);
}
void test_areEqual_gives_1_when_two_integer_arrays_are_equal(){
	ArrayUtil util1 = {int_array,SIZEOF_INT ,3 } ;
	ArrayUtil util2 = {int_array,SIZEOF_INT,3} ;
	result = areEqual(util1,util2);
	assertEqual(result, 1);
} 
void test_areEqual_gives_1_two_character_arrays_are_equal(){
	char array1[] ={'a','b','c'}, array2[] ={'a','b','c'};
	int result;
	ArrayUtil util1 = {array1, SIZEOF_CHAR, 3};
	ArrayUtil util2 = {array2, SIZEOF_CHAR, 3};
	result = areEqual(util1,util2);
	assertEqual(result, 1);
}
void test_areEqual_gives_1_when_two_float_arrays_are_equal(){
	float array1[] ={1.1,2.2,3.3}, array2[] ={1.1,2.2,3.3}; 
	int result;
	ArrayUtil util1 = {array1, SIZEOF_FLOAT, 3};
	ArrayUtil util2 = {array2, SIZEOF_FLOAT, 3};
	result = areEqual(util1, util2);
	assertEqual(result, 1);
}
void test_areEqual_gives_1_when_two_double_arrays_are_equal(){
	double array1[] ={1.1,2.2,3.3}, array2[] ={1.1,2.2,3.3};
	int result;
	ArrayUtil util1 = {array1, SIZEOF_DOUBLE, 3} ;
	ArrayUtil util2 = {array2, SIZEOF_DOUBLE, 3} ;
	result = areEqual(util1, util2);
	assertEqual(result, 1);
}
void test_areEqual_gives_0_when_two_arrays_are_not_Equal_for_different_length(){
	int array1[] ={1,2,3,4}, array2[] ={1,2,3}, result;
	ArrayUtil util1 = {array1, SIZEOF_INT, 4} ;
	ArrayUtil util2 = {array2, SIZEOF_INT, 3} ;
	result = areEqual(util1, util2);
	assertEqual(result, 0);
}
void test_areEqual_gives_0_when_two_arrays_are_not_Equal_for_different_array_elements(){
	int array1[] ={4,5,6}, array2[] ={1,2,3}, result;
	ArrayUtil util1 = {array1, SIZEOF_INT, 3} ;
	ArrayUtil util2 = {array2, SIZEOF_INT, 3} ;
	result = areEqual(util1, util2);
	assertEqual(result, 0);
}
void test_areEqual_gives_0_when_two_arrays_are_not_Equal_for_different_array_type(){
	int array1[] ={4,5,6}, result;
	float array2[] ={1.1,2.2,3.3};
	ArrayUtil util1 = {array1, SIZEOF_INT, 3} ;
	ArrayUtil util2 = {array2, SIZEOF_FLOAT, 3} ;
	result = areEqual(util1,util2);
	assertEqual(result, 0);
}
void test_create_creates_new_integer_array_of_given_size(){
	ArrayUtil array = create(SIZEOF_INT,3);
	assertEqual(array.length,3);
}
void test_create_creates_new_integer_array_of_given_typeSize(){
	ArrayUtil array = create(SIZEOF_INT,3);
	assertEqual(array.typeSize,SIZEOF_INT);
}
void test_create_creates_new_integer_array_of_all_0_elements(){
	int counter;
	ArrayUtil array = create(SIZEOF_INT,3);
	for(counter = 0;counter<3;counter++){
		assertEqual(((int *)array.base)[counter],0);
	}
}
void test_create_creates_new_float_array_of_all_0_elements(){
	int counter;
	ArrayUtil array = create(SIZEOF_FLOAT,3);
	for(counter = 0;counter<3;counter++){
		assertEqual(((float *)array.base)[counter],0.0);
	}
}
void test_create_creates_new_char_array_of_all_0_elements(){
	int counter;
	ArrayUtil array = create(SIZEOF_CHAR,3);
	for(counter = 0;counter<3;counter++){
		assertEqual(((char *)array.base)[counter], 0);
	}
}
void test_create_creates_new_double_array_of_all_0_elements(){
	int counter;
	int arr[3] = {0,0,0};
	ArrayUtil array = create(SIZEOF_DOUBLE,3);
	for(counter = 0;counter<3;counter++){
		assertEqual(((double *)array.base)[counter], 0);
	}
}
void test_resize_change_the_current_size_3_to_5(){
	int array[] = {1,2,3};
	ArrayUtil util1 = {array, SIZEOF_INT, 3};
	ArrayUtil array2;
	array2 =  resize(util1,5);
	assertEqual(array2.length, 5);
}

void test_resize_change_the_current_size_5_to_3(){
	int array[] = {1,2,3,4,5};
	ArrayUtil util1 = {array, SIZEOF_INT, 5};
	ArrayUtil array2;
	array2 =  resize(util1,3);
	assertEqual(array2.length, 3);
	free(array2.base);
}

void test_resize_add_0_to_the_new_places_created_in_integer_array(){
	int array[] = {1,2,3}, arr[] = {1,2,3,0,0};
	ArrayUtil array2, util1 = {array, SIZEOF_INT, 3};
	ArrayUtil expected = {arr, SIZEOF_INT ,5};
	array2 =  resize(util1,5);
	assert(areEqual(array2 , expected));
}
void test_resize_add_0_to_the_new_places_created_in_float_array(){
	float array[] = {1.1,2.2,3.2}, arr[] = {1.1,2.2,3.2,0.0,0.0};
	ArrayUtil array2, util1 = {array, SIZEOF_FLOAT, 3};
	ArrayUtil expected = {arr, SIZEOF_FLOAT ,5};
	array2 =  resize(util1,5);
	assert(areEqual(array2 , expected));
}
void test_resize_add_0_to_the_new_places_created_in_char_array(){
	char *array= "abc";
	char arr[] = {'a','b','c',0,0};
	ArrayUtil array2, util1 = {array, SIZEOF_CHAR, 3};
	ArrayUtil expected = {arr, SIZEOF_CHAR ,5};
	array2 =  resize(util1,5);
	assert(areEqual(array2 , expected));
}
void test_resize_add_0_to_the_new_places_created_in_double_array(){
	double array[] = {1,2,3}, arr[] = {1,2,3,0.0,0.0};
	ArrayUtil array2, util1 = {array, SIZEOF_DOUBLE, 3};
	ArrayUtil expected = {arr, SIZEOF_DOUBLE ,5};
	array2 =  resize(util1,5);
	assert(areEqual(array2 , expected));
}
void test_findIndex_returns_1_for_the_Index_of_2_for_integer_array(){
	int index , array[] = {1,2,3};
	int element = 2;
	ArrayUtil util = {array, SIZEOF_INT, 3};
	index = findIndex(util, &element);
	assertEqual(index,1);
}
void test_findIndex_returns_1_for_the_Index_of_2_point_5_for_float_array(){
	int index;
	float array[] = {1.2,2.5,3.6};
	float element = 2.5;
	ArrayUtil util = {array, SIZEOF_FLOAT, 3};
	index = findIndex(util, &element);
	assertEqual(index,1);
}
void test_findIndex_returns_1_for_the_Index_of_b_for_char_array(){
	int index;
	char *array = "abc";
	char element = 'b';
	ArrayUtil util = {array, SIZEOF_CHAR, 3};
	index = findIndex(util, &element);
	assertEqual(index,1);
}
void test_findIndex_returns_0_for_the_Index_of_1_for_double_array(){
	int index;
	double array[] = {1,2,3};
	double element = 1;
	ArrayUtil util = {array, SIZEOF_DOUBLE, 3};
	index = findIndex(util, &element);
	assertEqual(index,0);
}

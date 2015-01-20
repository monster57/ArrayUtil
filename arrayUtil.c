#include "arrayUtil.h"
#include <stdlib.h>


int elementChecker(ArrayUtil array1 , ArrayUtil array2){
	int counter;
	for(counter=0; counter<array1.length;counter++){
		if(((int*)array1.base)[counter] != ((int*)array2.base)[counter]){
			return 0;
		}
	}
	return 1;
}

int typesizeChecker(ArrayUtil array1 , ArrayUtil array2){
	return (array1.typeSize == array2.typeSize) && elementChecker(array1 , array2);
}

int areEqual(ArrayUtil array1, ArrayUtil array2){
	(array1.length == array2.length) && typesizeChecker(array1 , array2);
	return 1;	
}
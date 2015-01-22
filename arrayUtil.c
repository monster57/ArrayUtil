#include "arrayUtil.h"
#include <string.h>
#include <stdlib.h>


int elementChecker(ArrayUtil array1 , ArrayUtil array2){
	int counter;
	for(counter=0; counter<array1.length;counter++){
		if(((char*)array1.base)[counter] != ((char*)array2.base)[counter]){
			return 0;
		}
	}
	return 1;
}

int typesizeChecker(ArrayUtil array1 , ArrayUtil array2){
	return (array1.typeSize == array2.typeSize) && elementChecker(array1 , array2);
}

int areEqual(ArrayUtil array1, ArrayUtil array2){
	return ((array1.length == array2.length) && typesizeChecker(array1 , array2));	
}

ArrayUtil create(int typeSize, int length){
	ArrayUtil array;
	array.base = calloc(length,typeSize);
	array.typeSize=typeSize;
	array.length =length;
	return array;
}

ArrayUtil resize(ArrayUtil util1, int length){
	ArrayUtil util2 = create(util1.typeSize, length);
	memcpy(util2.base, util1.base, util1.length*util1.typeSize);
	return util2;
}

int findIndex(ArrayUtil array, void* element){
	int counter;
	char *mainArray = (char*)array.base;
	char *ele = (char*)element;
	int maxLength = array.length*array.typeSize;
	for(counter=0;counter<maxLength; counter = counter+array.typeSize){
		if(mainArray[counter] == *ele)
			return counter/array.typeSize;
	}
	return -1;
}

void dispose(ArrayUtil util){
	free(util.base);
}


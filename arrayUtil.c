#include "arrayUtil.h"
#include <string.h>
#include <stdlib.h>

int elementChecker(ArrayUtil util1 , ArrayUtil util2){
	int counter;
	for(counter=0; counter<util1.length;counter++){
		if(memcmp(util2.base, util1.base, util1.length*util1.typeSize))
			return 0;
	}
	return 1;
}
int typesizeChecker(ArrayUtil util1 , ArrayUtil util2){
	return (util1.typeSize == util2.typeSize) && elementChecker(util1 , util2);
}
int areEqual(ArrayUtil util1, ArrayUtil util2){
	return ((util1.length == util2.length) && typesizeChecker(util1 , util2));	
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

int findIndex(ArrayUtil util,void* element){
	int counter;
	for(counter=0;counter<util.length;counter++){
		if(memcmp(util.base+(util.typeSize*counter),element,util.typeSize)==0) 
			return counter;
	}
	return -1;
}

void dispose(ArrayUtil util){
	free(util.base);
}

void* findFirst(ArrayUtil util, MatchFunc* match, void* hint){
	int counter;
	void *item = malloc(util.typeSize);
	char *base = (char *)util.base;
	for(counter = 0; counter<util.length; counter++){
		memcpy( item, &(base[counter*util.typeSize]), util.typeSize);
		if(match(item,hint)){
			return item;
		}
	}
	return NULL;
}
void* findLast(ArrayUtil util, MatchFunc* match, void* hint){
	int counter;
	void *item = malloc(util.typeSize);
	char *base = (char *)util.base;
	for(counter = (util.length - 1); counter>=0; counter--){
		memcpy(item, &(base[counter*util.typeSize]), util.typeSize);
		if(match(item,hint)){
			return item;
		}
	}
	return NULL;
}
int count(ArrayUtil util, MatchFunc* match, void* hint){
	int count=0 , counter;
	int typeSize = util.typeSize;
	for(counter=0; counter<util.length; counter++)
		count += match(hint, util.base + (counter * typeSize));
	
	return count;
}

int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems ){
	int counter,count = 0;
	void* base = util.base;
	void* item;
	for(counter = 0;(counter<util.length && count < maxItems); counter++){
		item = base + counter*util.typeSize;
		if(match(hint, item)) 
			destination[count++] = item;
	}
	return count;
}

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint){
	int counter;
	for(counter=0;counter<source.length;counter++){
		convert(hint,source.base+(counter*source.typeSize),
			destination.base+(counter*destination.typeSize));
	}
}

void forEach(ArrayUtil util, OperationFunc* operation, void* hint){
	int counter;
	int item;
	for(counter=0; counter < util.length;counter++)
		operation(hint,(void*)item);
}

void reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* result){
	int counter;
	void* curr_address=util.base;
	for (counter = 0; counter < util.length; ++counter){
		reducer( hint,  result,  curr_address);
		curr_address+=util.typeSize;
	}	
}
typedef struct arrayUtil ArrayUtil;
struct arrayUtil{
	void *base;
	int typeSize;
	int length;
};

int areEqual(ArrayUtil array1, ArrayUtil array2);
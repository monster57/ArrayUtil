typedef struct arrayUtil ArrayUtil;
struct arrayUtil{
	void *base;
	int typeSize;
	int length;
};

int areEqual(ArrayUtil array1, ArrayUtil array2);

ArrayUtil create(int typeSize, int length);

ArrayUtil resize(ArrayUtil util, int length); 
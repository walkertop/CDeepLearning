//
//  Pointer.c
//  
//
//  Created by walker彬 on 2017/7/21.
//
//

#include "Pointer.h"

 
//void go_south_east(int lat, int lon) {
//    lat = lat - 1;
//    lon = lon + 1;
//}
//
//
//int main() {
//    int latitude = 11;
//    int longitude = 10;
//    
//    go_south_east(latitude,longitude);
//    printf("latitude值为: %i,longitude值为: %i",latitude,longitude);
//    return 0;
//}



void go_south_east(int *lat, int *lon) {
    *lat = *lat - 1;
    *lon = *lon + 1;
}

void testPoint() {
    
        int latitude = 11;
        int longitude = 10;
        go_south_east(&latitude,&longitude);
        printf("latitude值为: %i,longitude值为: %i",latitude,longitude);
}

/*
 数组的地址是0x7fff5d4dda3c
 数组第一个元素的地址是0x7fff5d4dda3c
 数组的长度是6
 数组的指针长度是8 （因为是64位系统，64/8=8）
 由此可见，数组第一个元素的地址 == 数组的地址
 数组的长度包含了后面的\0元素。
 */

void testSizeofFuntion() {
    char array[] = "abcde";
    char *a = array;
    printf("数组的地址是%p\n数组第一个元素的地址是%p\n",&array,&array[0]); //数组的地址是0x7fff5d5ee9aa
   //数组第一个元素的地址是0x7fff5d5ee9aa    数组第一个元素的地址是0x7fff5d4dda3c
    printf("数组的长度是%lu\n",sizeof(array));               //结果为6
    printf("数组的地址是%lu\n",sizeof(a));                   //结果为8
    printf("数组地址的地址长度是%lu\n",sizeof(&a));           //结果为8
    printf("数组的指针长度是%lu\n",sizeof(&array));          //结果为8
}


void testArr() {
    char arr[] = {1,2,3};
    char *temArr = arr;
    // 数组arr[]的长度是12，大小为12
    printf("数组arr[]的长度是%lu，大小为%lu\n\n",sizeof(arr),sizeof(arr));
    
    //数组arr[]的长度是8，大小为8(都是对数组对应的指针进行大小取值)
    printf("数组arr[]的长度是%lu，大小为%lu\n\n",sizeof(temArr),sizeof(temArr));
    
    printf("第一个元素地址为%p，第二个元素地址为%p\n\n",&arr,&arr+1);
    printf("第一个元素地址为%p，第二个元素地址为%p\n\n",temArr,temArr+1);
    printf("arr的地址是%p\n,temArr指向的地址是%p\n，temArr的地址为%p\n",&arr,temArr,&temArr);
}

/// 最终得出的结论
/*          数组的地址 == 数组第一个元素的地址，可以用该数组变量标识数组本身
        1. 数组变量的地址和数组指针不同，例如arr[]的地址 == arr[0] == tempArr是指向数组的指针
        2. sizeof()作用于数组时，是默认求数组的大小，但是作用于数组的指针tempArr上，只会求指针的大小,其大小在64位系统上为8
        3. 对于数组指针tempArr,其值加1，只是指针的大小+1,但对于指针数组，其+1,是根据元素来确定的，比如是char型数组，其地址偏移一个字节，但对于整形数组，偏移4个字节
        4. arr[i] = *(arr + i)
        5. 指针有类型，是为了计算
 
 
///总结:
        1. 数组变量可以用作指针……
        2. 但数组变量和指针又不完全相同
        3. 对数组变量和指针变量使用sizeof，效果不同
        4. 数组变量不能指向其他地方。
        5. 把数组变量传给指针，会发生退化。
        6. 索引的本质是指针算术运算，所以数组从0开始。
        7. 指针变量具有类型，这样就能调整指针算术运算
*/


int main() {
//    testPoint()
//    testSizeofFuntion();
    testArr();
    return 0;
}



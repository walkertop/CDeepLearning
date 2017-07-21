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
    printf("数组的地址是%p\n数组第一个元素的地址是%p\n",&array,&array[0]);
    printf("数组的长度是%lu\n",sizeof(array));
    printf("数组的指针长度是%lu\n",sizeof(&array));
}

int main() {
//    testPoint()
    testSizeofFuntion();
    return 0;
}


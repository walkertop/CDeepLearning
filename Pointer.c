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



//void testPointerOrArray(bool isPointer) {
void testArrayOfvariable() {

//    char *name = "123";        // [1]  4213 bus error  /Users/walker/Dev/DeepLearning/CDeepLearning/Poniter
        char name[5] = "123";
    printf("原来name的地址是%p",&name);
    char temp = name[3];
    name[0] = name[1];
    name[1] = name[2];
    name[2] = name[3];
    name[3] = name[0];
    name[4] = 'e';
    printf("新的name的值是%c\n",name[4]);
    printf("现在name的地址是%p",&name);
}


void testStruct() {
    struct firstTyepFish {
        char *name;
        int teeth;
        int age;
    };
    
    struct secondTyepFish {
        char name[20];
        int teeth;
        int age;
    };
    
    struct firstTyepFish firstFish = {"firstShark", 69, 3};
    struct secondTyepFish secondFish = {"secondShark", 69, 3};
    firstFish.name = "newShark";
    printf("%s",firstFish.name);
    
//    secondFish.name = "newShark";
//    printf("%s",secondFish.name);
    
    /*
     此处会报错  array type 'char [20]' is not assignable
     因为firstFish是以指针形式保存的name，此处的name只是一个字符串指针，具体的内容放在其他地方了，修改内容，只用修改地址的指向就ok了;
     而secondFish中的name是字符数组，其name本身就保存在结构体中，所以不可以更改
     */
}

void structTypedef() {
    /*
     struct firstContact    是   结构名
     firstContact           是   类型名
     */
    struct firstContact {
        int phoneNumber;
        const char *name;
    };
    struct firstContact firstPerson = {1339, "Jimmy"};

    //使用typedef之后
    typedef struct contact{
        int phoneNumber;
        const char *name;
    }secondContact;
    secondContact secondPerson = {1333, "Tom"};
    
    //使用typedef的匿名结构体
    typedef struct {
        int phoneNumber;
        const char *name;
    }thirdContact;
    thirdContact thirdPerson = {1313, "Bob"};
}

typedef struct {
    int phoneNumber;
    const char *name;
}contact;

void updateStructByPointer(contact *person) {
    person->phoneNumber = person->phoneNumber + 1;
    printf("updateStructByPointer使用直接传入结构体的phoneNumber是%i",person->phoneNumber);
}

void updateStruct(contact person) {
    person.phoneNumber = person.phoneNumber + 1;
    printf("updateStruct使用直接传入结构体的phoneNumber是%i",person.phoneNumber);
}


// MARK: ENUM

enum week {
    Mon,
    Tue,
    Wed,
    Thu,
    Fri,
    Sat,
    Sun
};

void testEnum() {
    enum week we;
    printf("%u",we.Fri);
}
int main() {
//    testPoint()
//    testSizeofFuntion();
//    testArr();
//    testArrayOfvariable();
//    testPointerOrArray(TRUE);
    
//    testFuntionSequence();
    
////    testStruct();
//    contact contact = {1111,"Bryant"};
//    updateStruct(contact);              //不能修改，因为此处的contact会赋值一个新的副本，不会对原来的结构体进行修改
//    printf("修改后的phoneNumber是%i\n", contact.phoneNumber);
//    updateStructByPointer(&contact);     //能修改，因为加了指针，会通过结构体的指针找到对应的的成员，然后直接修改
//    printf("修改后的phoneNumber是%i\n", contact.phoneNumber);
    
    testEnum();
    return 0;
}

//这里有个好问题：
/*
？？？C语言是顺序执行的，在main函数之后的函数都会发生错误嘛？
 先说结果： 如果返回值是int类型，只会警告，如下：
 warning: implicit declaration of function 'testFuntionSequence' is invalid in C99
 [-Wimplicit-function-declaration]
 但不会报错；
 若不是int类型，编译器直接报错 conflicting types for 'testFuntionSequence'
 为何会这样呢？
 
分步骤回答：
 1. 在main执行时，编译器看到一个不认识的函数调用,并不会报错，而是记录下来，并且相信在后续的程序中会找到
 2. 编译器此时记录时需要确定函数的返回值类型，但此时不知道，会默认为int
 3. 等找到这个类型，发现不是int,就会报错。意味编译器会认为有两个同名函数，一个返回int，一个返回其它类型。
 
 -->不过通过函数声明可以很好的解决这个问题，这样编译器就不用假设int类型，直接在声明出准确知道类型了
 */
int testFuntionSequence() {
    printf("testFuntionSequence是否调用");
    return 3;
}


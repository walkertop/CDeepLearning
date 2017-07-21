# CDeepLearning
## 重新捡起C语言
### 指针和存储器
#### 指针
##### 指针的好处：

* 避免副本 （指针的好处是之存取地址，而不用拷贝整个数据。）
* 共享数据 （可以依赖地址操作同一份数据，而不用处理两个独立的副本）


#### 使用说明
* &运算符可以找到变量的地址。
* “指针只是一个保存存储器地址的变量
* 运算符可以读取存储器地址中的内容。
* 运算符还可以设置存储器地址中的内容。





```
//  不用指针，输出结果为:
// latitude值为: 11,longitude值为: 10
void go_south_east(int lat, int lon) {
    lat = lat - 1;
    lon = lon + 1;
}

int main() {
    int latitude = 11;
    int longitude = 10;
    go_south_east(latitude,longitude);
    printf("latitude值为: %i,longitude值为: %i",latitude,longitude);
    return 0;
}
```

```

// 此为指针传递，输出结果为：
// latitude值为: 10,longitude值为: 11
//void go_south_east(int *lat, int *lon) {
//    *lat = *lat - 1;
//    *lon = *lon + 1;
//}
//
//
//int main() {
//    int latitude = 11;
//    int longitude = 10;
//    go_south_east(&latitude,&longitude);
//    printf("latitude值为: %i,longitude值为: %i",latitude,longitude);
//    return 0;
//}
```


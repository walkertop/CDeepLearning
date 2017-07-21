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

int main() {
    int latitude = 11;
    int longitude = 10;
    go_south_east(&latitude,&longitude);
    printf("latitude值为: %i,longitude值为: %i",latitude,longitude);//    return 0;
}

#ifndef ROTATE_H
#define ROTATE_H
template <typename T>
void rotate(T* pointerToArray, size_t quantityElements, size_t shift){
    shift %= quantityElements;
    unsigned char byteForValue = sizeof(T);
    unsigned char* myPointer = static_cast<unsigned char*>(static_cast<void*>(pointerToArray));
    for(int i = 0; i < shift * byteForValue; i++){ // move byte = shift * byte for one value
        for(int j = 0; j < 8; j++) // shift one byte
            if((myPointer[0] & 128) == 128){ //first bit == 1// БАГ: эта запись оказывается не то же самое: if(myPointer[0] & 128 == 128) видимо приоритет выше у ==
                for(int k = 0; k < byteForValue * quantityElements - 1; k++){
                    myPointer[k] <<= 1;
                    myPointer[k] |= ((128 & myPointer[k + 1]) >> 7);
                }
                myPointer[byteForValue * quantityElements - 1] <<= 1;
                myPointer[byteForValue * quantityElements - 1] |= 1;
                continue;
            }
            else{
                for(int k = 0; k < byteForValue * quantityElements - 1; k++){
                    myPointer[k] <<= 1;
                    myPointer[k] |= ((128 & myPointer[k + 1]) >> 7);
                }
                myPointer[byteForValue * quantityElements - 1] <<= 1;
            }
    }
}
#endif // ROTATE_H

#ifndef ROTATE_H
#define ROTATE_H
template <typename T>
void rotate(T* pointerToArray, size_t quantityElements, size_t shift){
    for(int i = 0; i < (shift % quantityElements) * sizeof(T); i++){ // move byte = shift * byte for one value
        for(int j = 0; j < 8; j++) // shift one byte
            if((reinterpret_cast<unsigned char*>(pointerToArray)[0] & 128) == 128){ //first bit == 1
                for(int k = 0; k < sizeof(T) * quantityElements - 1; k++){
                    reinterpret_cast<unsigned char*>(pointerToArray)[k] <<= 1;
                    reinterpret_cast<unsigned char*>(pointerToArray)[k] |= ((128 & reinterpret_cast<unsigned char*>(pointerToArray)[k + 1]) >> 7);
                }
                reinterpret_cast<unsigned char*>(pointerToArray)[sizeof(T) * quantityElements - 1] <<= 1;
                reinterpret_cast<unsigned char*>(pointerToArray)[sizeof(T) * quantityElements - 1] |= 1;
                continue;
            }
            else{
                for(int k = 0; k < sizeof(T) * quantityElements - 1; k++){
                    reinterpret_cast<unsigned char*>(pointerToArray)[k] <<= 1;
                    reinterpret_cast<unsigned char*>(pointerToArray)[k] |= ((128 & reinterpret_cast<unsigned char*>(pointerToArray)[k + 1]) >> 7);
                }
                reinterpret_cast<unsigned char*>(pointerToArray)[sizeof(T) * quantityElements - 1] <<= 1;
            }
    }
}
#endif // ROTATE_H

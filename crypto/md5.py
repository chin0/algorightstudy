import math

def append_bit(x, b=0):
    return x << 1 | b

def md5(messeage):
    s = [7,12,17,22,7,12,17,22,7,12,17,22,7,12,17,22]
    s += [5,9,14,20,5,9,14,20,5,9,14,20,5,9,14,20]
    s += [4,11,16,23,4,11,16,23,4,11,16,23,4,11,16,23]
    s += [6,10,15,21,6,10,15,21,6,10,15,21,6,10,15,21]

    k = []

    for i in range(0,64):
        k.append(math.floor(2**32 * abs(math.sin(i+1))))

    a0 = 0x67452301
    b0 = 0xefcdab89
    c0 = 0x98badcfe
    d0 = 0x10325476

    original_length = messeage.bit_length()

    messeage = append_bit(messeage,1)

    while (messeage.bit_length() % 512 != 448 % 512):
        messeage = append_bit(messeage)
    print(messeage.bit_length())

    bit_append = original_length % 2**64
    messeage = messeage << bit_append.bit_length() | bit_append

    print(messeage.bit_length())

md5(5)



    




    

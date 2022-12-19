"""
Implemented Dictionary to convert hextodecimal
Author: Roshan Poudel
"""

def hextodec(str_):
    """This function converts given hexadecimal number to a decimal number"""
    dict_ = {'A': 10, 'B':11, 'C':12, 'D':13, 'E':14, 'F':15}
    dec  = str_.strip()
    dec = [x for x in dec]
 
    for i in range(len(dec)):
        if dec[i] in list(dict_.keys()):
            dec[i] = dict_[dec[i]]
    dec = list(map(int, dec))

    i = len(dec)-1
    power = 0
    num = 0
    while i >= 0:
        num += dec[i] * (16 ** power)
        i-=1
        power+=1   
    return num

def main():
    hexnum = input("Enter a valid hexadecimal number:\n")
    try:
        decval = hextodec(hexnum)
        print(f"The decimal value of {hexnum} is {decval}")
    except:
        print("Please enter a valid Hexadecimal number")

if __name__ == "__main__":
    main()
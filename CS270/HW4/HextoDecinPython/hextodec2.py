"""
Simplest solution for hex to decimal conversion. Other conversions can be done similarly.
Author: Roshan Poudel

"""

def main():

    hexnum = input("Enter a valid hexadecimal number: ")
    try:
        print('Hexadecimal number you entered:', hexnum)
        decnum = int(hexnum, 16)
        print("Equivalent decimal number: ", decnum)
        binnum = bin(int(hexnum, 16)) #binary always only takes one integer argument. So, first we need to convert the hex into dec and then into binary
        print('Equivalent binary number', binnum)
    
    except:
        print("Please enter a valid hexadecimal number")
    

if __name__ == "__main__":
    main()
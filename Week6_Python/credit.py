card_Num = int(input("Number: "))


def isValid(card_Num):
    sum = 0
    isEvenDigit = False
    while card_Num > 0:
        if isEvenDigit:
            if (card_Num % 10)*2 > 9:
                sum += (card_Num % 10)*2 - 9
            else:
                sum += (card_Num % 10)*2
        else:
            sum += (card_Num % 10)
        card_Num = int(card_Num/10)
        isEvenDigit = not isEvenDigit
    if (sum % 10 == 0):
        return True
    else:
        return False


def type_declare(card_Num):
    prefix = int(str(card_Num)[:2])
    if prefix == 34 or prefix == 37:
        return "AMEX"
    elif prefix > 50 and prefix < 56:
        return "MASTERCARD"
    elif int(prefix/10) == 4:
        return "VISA"
    else:
        return "INVALID"


if len(str(card_Num)) > 16 or len(str(card_Num)) < 13:
    print("INVALID")
elif(isValid(card_Num)):
    print(type_declare(card_Num))
else:
    print("INVALID")

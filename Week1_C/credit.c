//link to the problem description
//https://cs50.harvard.edu/x/2021/psets/1/credit/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isValid(long card_num)
{
  // Checks if the credit card format is valid
 int sum=0;
 bool isEvenDigit= false;
 while (card_num > 0)
 {
   if (isEvenDigit)
   {
      if ((card_num%10)*2 > 9)
      {
        sum += (card_num%10)*2 - 9;
      }
      else
      sum += (card_num%10)*2;;

   }
   else
   {
    sum+= (card_num%10);
   }
    card_num/=10;
    isEvenDigit = !isEvenDigit;
 }
 if (sum%10==0)
 return true;
 else
 return false;
}
const char* type_dec(long card_num)
{
  // declare the company that card belongs to.
  while (card_num > 100)
  {
    card_num /=10;
  }
  if (card_num == 34 || card_num ==37)
  {
    return "AMEX\n";
  }
  else if (card_num > 50 && card_num < 56)
  {
   return "MASTERCARD\n";
  }
  else if (card_num/10==4)
  {
    return "VISA\n";
  }
  else
  return "INVALID\n";


}
int main()
{
  long card_num;
  scanf("%li",&card_num);
  if (isValid(card_num))
  {
  printf("%s",type_dec(card_num));
  }
  else
  printf("INVALID\n");
}

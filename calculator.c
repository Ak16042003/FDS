#include <stdio.h>
 int main()
{
  char ch;
  int first, second;
  printf("Enter an operator (+, -, *, /): ");
  scanf("%c", &ch);
  printf("Enter two operands: ");
  scanf("%d %d", &first, &second);

  switch (ch) {
    case '+':
      printf("%d + %d = %d", first, second, first + second);
      break;
    case '-':
      printf("%d - %d = %d", first, second, first - second);
      break;
    case '*':
      printf("%d * %d = %d", first, second, first * second);
      break;
    case '/':
      printf("%d / %d = %d", first, second, first / second);
      break;
    // operator doesn't match any case constant
    default:
      printf("Error! operator is not correct");
  }

  return 0;
}

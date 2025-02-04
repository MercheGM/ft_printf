/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:49:00 by fvizcaya          #+#    #+#             */
/*   Updated: 2025/02/04 23:31:00 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <semaphore.h>
#include "ft_printf.h"

void	test1();
void	test2();
void	test3();
void	test4();
void 	test5();
void 	test6();
void 	test7();
void	test8();
void	test9();

int	main(void)
{
	printf("\n~~~~~~~test1~~~~~~~\n");
	test1();
	printf("\n~~~~~~~test2~~~~~~~\n");
	test2();
	printf("\n~~~~~~~test3~~~~~~~\n");
	test3();
	printf("\n~~~~~~~test4~~~~~~~\n");
	test4();
	printf("\n~~~~~~~test5~~~~~~~\n");
	test5();
	printf("\n~~~~~~~test6~~~~~~~\n");
	test6();
	printf("\n~~~~~~~test7~~~~~~~\n");
	test7();
	printf("\n~~~~~~~test8~~~~~~~\n");
	test8();
	printf("\n~~~~~~~test9~~~~~~~\n");
	test9();

}

void	test1()
{
	int		nbr;
	int		printf_count;
	int		ftprintf_count;

	printf_count = 0;
	ftprintf_count = 0;
	nbr = 42;
	printf("\nPuntero\n");
	ftprintf_count += ft_printf("%p", &nbr);
	printf("\n");
	printf_count += printf("%p", &nbr);
	printf("\n");
	printf("\nPuntero NULL\n");
	ftprintf_count += ft_printf("%p", NULL);
	printf("\n");
	printf_count += printf("%p", NULL);
	printf("\n");
	printf_count += printf("\001\002\007\v\010\f\r\n");
	ftprintf_count += ft_printf("\001\002\007\v\010\f\r\n");
	printf("\n");
	printf("\nAlgunas pruebas que hacen los test de francinette:\n");
	ftprintf_count += ft_printf(" %%");
	printf("\n");
	printf_count += printf(" %%");
	printf("\n");
	ftprintf_count += ft_printf("%%c");
	printf("\n");
	printf_count += printf("%%c");
	printf("\n");
	ftprintf_count += ft_printf("%%%%%%");
	printf("\n");
	printf_count += printf("%%%%%%");
	printf("\n");
	ftprintf_count += ft_printf("%%%c", 'x');
	printf("\n");
	printf_count += printf("%%%c", 'x');
	printf("\n");
	ftprintf_count += ft_printf("%c", 'x');
	printf("\n");
	printf_count += printf("%c", 'x');
	printf("\n");
	ftprintf_count += ft_printf("  %d,%X %d,%X %d,%X %d,%X %d,%X %d,%X %d,%X", \
		INT_MAX, INT_MAX, INT_MIN, INT_MIN, LONG_MAX, LONG_MAX, LONG_MIN, LONG_MIN, ULONG_MAX, ULONG_MAX, 0, 0, -42, -42);
	printf("\n");
	printf_count += printf("  %d,%X %d,%X %d,%X %d,%X %d,%X %d,%X %d,%X", \
		INT_MAX, INT_MAX, INT_MIN, INT_MIN, LONG_MAX, LONG_MAX, LONG_MIN, LONG_MIN, ULONG_MAX, ULONG_MAX, 0, 0, -42, -42);
	printf("\n");
	printf("\nOtras pruebas:\n");
	ftprintf_count += ft_printf("Cero en hexa minúsculas %x", 0);
	printf("\n");
	printf_count += printf("Cero en hexa minúsculas %x", 0);
	printf("\n");
	ftprintf_count += ft_printf("NULL %s NULL", NULL);
	printf("\n");
	printf_count += printf("NULL %s NULL", NULL); 
	printf("\n");
	printf("Numero de caracteres impresos por ft_printf() %d", ftprintf_count);
	printf("\n");
	printf("Numero de caracteres impresos por printf() %d", printf_count);
	printf("\n");
}
void	test2()
{
	int	error;

	error = ft_printf("\001\002\007\v\010\f\r\n");
	printf("Caracteres impresos ====> %d\n", error);
	error = printf("\001\002\007\v\010\f\r\n");
	printf("Caracteres impresos ====> %d\n", error);
	printf("\n\n");
	error = ft_printf("o,9?%c;UH>Sj%c2h:jYD%s\rqd;?#GR\f%X\r!{XC%sXlS\nu%uc/\nu%i9", 320217853, -450119245, "|^`U[Q~>HW0n78s pBh\v\r8J?\nlmu\vtJ@3Eu|r11W]]~hS$B\fOCY[5", 56438883, "09}", 967802697, -140519593);
	printf("\nCaracteres impresos ====> %d\n", error);
	error = printf("o,9?%c;UH>Sj%c2h:jYD%s\rqd;?#GR\f%X\r!{XC%sXlS\nu%uc/\nu%i9", 320217853, -450119245, "|^`U[Q~>HW0n78s pBh\v\r8J?\nlmu\vtJ@3Eu|r11W]]~hS$B\fOCY[5", 56438883, "09}", 967802697, -140519593);
	printf("\nCaracteres impresos ====> %d\n", error);
	error = ft_printf("(&q&E1c%c%d0:q9:,Mg%i", 1544804724, 671876632, 1034788635);
	printf("\nCaracteres impresos ====> %d\n", error);
	error = printf("(&q&E1c%c%d0:q9:,Mg%i", 1544804724, 671876632, 1034788635);
	printf("\nCaracteres impresos ====> %d\n", error);
}

void	test3()
{
	int cont_printf;
	int cont_ftprintf;
	
   cont_printf = printf("1. The value of CHAR_BIT: %d\n", CHAR_BIT);
   cont_ftprintf = ft_printf("2. The value of CHAR_BIT: %d\n", CHAR_BIT);
   printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of SCHAR_MIN: %d\n", SCHAR_MIN);
   cont_ftprintf = ft_printf("2. The value of SCHAR_MIN: %d\n", SCHAR_MIN);
   printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of SCHAR_MAX: %d\n", SCHAR_MAX);
   cont_ftprintf = ft_printf("2. The value of SCHAR_MAX: %d\n", SCHAR_MAX);
	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of UCHAR_MAX: %u\n", UCHAR_MAX);
   cont_ftprintf = ft_printf("2. The value of UCHAR_MAX: %u\n", UCHAR_MAX);
   	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of CHAR_MIN: %d\n", CHAR_MIN);
	cont_ftprintf = ft_printf("2. The value of CHAR_MIN: %d\n", CHAR_MIN);
   	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of CHAR_MAX: %d\n", CHAR_MAX);
   cont_ftprintf = ft_printf("2. The value of CHAR_MAX: %d\n", CHAR_MAX);
   	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of MB_LEN_MAX: %d\n", MB_LEN_MAX);
   cont_ftprintf = ft_printf("2. The value of MB_LEN_MAX: %d\n", MB_LEN_MAX);
   	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of SHRT_MIN: %d\n", SHRT_MIN);
   cont_ftprintf = ft_printf("2. The value of SHRT_MIN: %d\n", SHRT_MIN);
   	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of SHRT_MAX: %d\n", SHRT_MAX);
   cont_ftprintf = ft_printf("2. The value of SHRT_MAX: %d\n", SHRT_MAX);
   	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of USHRT_MAX: %u\n", USHRT_MAX);
   cont_ftprintf = ft_printf("2. The value of USHRT_MAX: %u\n", USHRT_MAX);
   	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of INT_MIN: %d\n", INT_MIN);
   cont_ftprintf = ft_printf("2. The value of INT_MIN: %d\n", INT_MIN);
   	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of INT_MAX: %d\n", INT_MAX);
   cont_ftprintf = ft_printf("2. The value of INT_MAX: %d\n", INT_MAX);
   	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of UINT_MAX: %u\n", UINT_MAX);
      cont_ftprintf = ft_printf("2. The value of UINT_MAX: %u\n", UINT_MAX);
   	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of LONG_MIN: %d\n", LONG_MIN);
   cont_ftprintf = ft_printf("2. The value of LONG_MIN: %d\n", LONG_MIN);
   	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of LONG_MAX: %d\n", LONG_MAX);
   cont_ftprintf = ft_printf("2. The value of LONG_MAX: %d\n", LONG_MAX);
   	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of ULONG_MAX: %u\n", ULONG_MAX);
   cont_ftprintf = ft_printf("2. The value of ULONG_MAX: %u\n", ULONG_MAX);
	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
}

void	test4()
{
	int cont_printf;
	int cont_ftprintf;
	
   cont_printf = printf("1. The value of CHAR_BIT: %d, %x, %X\n", CHAR_BIT, CHAR_BIT, CHAR_BIT);
   cont_ftprintf = ft_printf("2. The value of CHAR_BIT: %d, %x, %X\n", CHAR_BIT, CHAR_BIT, CHAR_BIT);
   printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of SCHAR_MIN: %d, %x, %X\n", SCHAR_MIN, SCHAR_MIN, SCHAR_MIN);
   cont_ftprintf = ft_printf("2. The value of SCHAR_MIN: %d, %x, %X\n", SCHAR_MIN, SCHAR_MIN, SCHAR_MIN);
   printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of SCHAR_MAX: %d, %x, %X\n", SCHAR_MAX, SCHAR_MAX, SCHAR_MAX);
   cont_ftprintf = ft_printf("2. The value of SCHAR_MAX: %d, %x, %X\n", SCHAR_MAX, SCHAR_MAX, SCHAR_MAX);
	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of UCHAR_MAX: %u, %x, %X\n", UCHAR_MAX, UCHAR_MAX, UCHAR_MAX);
   cont_ftprintf = ft_printf("2. The value of UCHAR_MAX: %u, %x, %X\n", UCHAR_MAX, UCHAR_MAX, UCHAR_MAX);
   	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of CHAR_MIN: %d, %x, %X\n", CHAR_MIN, CHAR_MIN, CHAR_MIN);
	cont_ftprintf = ft_printf("2. The value of CHAR_MIN: %d, %x, %X\n", CHAR_MIN, CHAR_MIN, CHAR_MIN);
   	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of CHAR_MAX: %d, %x, %X\n", CHAR_MAX, CHAR_MIN, CHAR_MIN);
   cont_ftprintf = ft_printf("2. The value of CHAR_MAX: %d, %x, %X\n", CHAR_MAX, CHAR_MIN, CHAR_MIN);
   	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of MB_LEN_MAX: %d, %x, %X\n", MB_LEN_MAX, MB_LEN_MAX, MB_LEN_MAX);
   cont_ftprintf = ft_printf("2. The value of MB_LEN_MAX: %d, %x, %X\n", MB_LEN_MAX, MB_LEN_MAX, MB_LEN_MAX);
   	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of SHRT_MIN: %d, %x, %X\n", SHRT_MIN, SHRT_MIN, SHRT_MIN);
   cont_ftprintf = ft_printf("2. The value of SHRT_MIN: %d, %x, %X\n", SHRT_MIN,SHRT_MIN,SHRT_MIN);
   	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of SHRT_MAX: %d, %x, %X\n", SHRT_MAX, SHRT_MAX, SHRT_MAX);
   cont_ftprintf = ft_printf("2. The value of SHRT_MAX: %d, %x, %X\n", SHRT_MAX, SHRT_MAX, SHRT_MAX);
   	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of USHRT_MAX: %u, %x, %X\n", USHRT_MAX, USHRT_MAX, USHRT_MAX);
   cont_ftprintf = ft_printf("2. The value of USHRT_MAX: %u, %x, %X\n", USHRT_MAX, USHRT_MAX, USHRT_MAX);
   	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of INT_MIN: %d, %x, %X\n", INT_MIN, INT_MIN, INT_MIN);
   cont_ftprintf = ft_printf("2. The value of INT_MIN: %d, %x, %X\n", INT_MIN, INT_MIN, INT_MIN);
   	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of INT_MAX: %d, %x, %X\n", INT_MAX, INT_MAX, INT_MAX);
   cont_ftprintf = ft_printf("2. The value of INT_MAX: %d, %x, %X\n", INT_MAX, INT_MAX, INT_MAX);
   	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of UINT_MAX: %u, %x, %X\n", UINT_MAX,UINT_MAX,UINT_MAX);
      cont_ftprintf = ft_printf("2. The value of UINT_MAX: %u, %x, %X\n", UINT_MAX, UINT_MAX, UINT_MAX);
   	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of LONG_MIN: %d, %x, %X\n", LONG_MIN, LONG_MIN, LONG_MIN);
   cont_ftprintf = ft_printf("2. The value of LONG_MIN: %d, %x, %X\n", LONG_MIN, LONG_MIN, LONG_MIN);
   	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of LONG_MAX: %d, %x, %X\n", LONG_MAX, LONG_MAX, LONG_MAX);
   cont_ftprintf = ft_printf("2. The value of LONG_MAX: %d, %x, %X\n", LONG_MAX, LONG_MAX, LONG_MAX);
   	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of ULONG_MAX: %u, %x, %X\n", ULONG_MAX, ULONG_MAX, ULONG_MAX);
   cont_ftprintf = ft_printf("2. The value of ULONG_MAX: %u, %x, %X\n", ULONG_MAX, ULONG_MAX, ULONG_MAX);
	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);


   
}

void test5()
{
	int cont_printf;
	int cont_ftprintf;
	
	cont_printf = printf("1. The value of LONG_MIN: %d, %x, %X\n", LONG_MIN, LONG_MIN, LONG_MIN);
   cont_ftprintf = ft_printf("2. The value of LONG_MIN: %d, %x, %X\n", LONG_MIN, LONG_MIN, LONG_MIN);
   	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of LONG_MAX: %d, %x, %X\n", LONG_MAX, LONG_MAX, LONG_MAX);
   cont_ftprintf = ft_printf("2. The value of LONG_MAX: %d, %x, %X\n", LONG_MAX, LONG_MAX, LONG_MAX);
   	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
   cont_printf = printf("1. The value of ULONG_MAX: %u, %x, %X\n", ULONG_MAX, ULONG_MAX, ULONG_MAX);
   cont_ftprintf = ft_printf("2. The value of ULONG_MAX: %u, %x, %X\n", ULONG_MAX, ULONG_MAX, ULONG_MAX);
	printf("Caracteres impresos con printf: %d\nCaracteres impresos con ft_printf: %d\n\n", cont_printf, cont_ftprintf);
}

void test6()
{
	int cont_printf;
	int cont_ft_printf;
	//Tests de %s
	cont_printf = printf("This is a simple test.");printf("\n");
	cont_ft_printf = ft_printf("This is a simple test.");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("This is a simple test.\nSecond sentence.\n");
	cont_ft_printf = ft_printf("This is a simple test.\nSecond sentence.\n");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("");printf("\n");
	cont_ft_printf = ft_printf("");
	printf("\n***1: %d ***\n***2: %d ***\n----------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("\n");
	cont_ft_printf = ft_printf("\n");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%s", "abc");printf("\n");
	cont_ft_printf = ft_printf("%s", "abc");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("111%s333", "222");printf("\n");
	cont_ft_printf = ft_printf("111%s333", "222");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%s333", "222");printf("\n");
	cont_ft_printf = ft_printf("%s333", "222");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("111%s", "222");printf("\n");
	cont_ft_printf = ft_printf("111%s", "222");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("111%s333%s555", "222", "444");printf("\n");
	cont_ft_printf = ft_printf("111%s333%s555", "222", "444");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("111%s333%s555%saaa%sccc", "222", "444", "666", "bbb");printf("\n");
	cont_ft_printf = ft_printf("111%s333%s555%saaa%sccc", "222", "444", "666", "bbb");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%s%s%s%s%s", "1", "2", "3", "4", "5");printf("\n");
	cont_ft_printf = ft_printf("%s%s%s%s%s", "1", "2", "3", "4", "5");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	char *s = NULL;
	cont_printf = printf("%s", s);printf("\n");
	cont_ft_printf = ft_printf("%s", s);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);	

	//Tests de %d
	cont_printf = printf("%d", 42);printf("\n");
	cont_ft_printf = ft_printf("%d", 42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%d", -42);printf("\n");
	cont_ft_printf = ft_printf("%d", -42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("before %d after", 42);printf("\n");
	cont_ft_printf = ft_printf("before %d after", 42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("a%db%dc%dd", 1, -2, 3);printf("\n");
	cont_ft_printf = ft_printf("a%db%dc%dd", 1, -2, 3);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%d", INT_MAX);printf("\n");
	cont_ft_printf = ft_printf("%d", INT_MAX);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%d", INT_MIN);printf("\n");
	cont_ft_printf = ft_printf("%d", INT_MIN);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);


	//Tests de %p
	int i;
	unsigned long l;
	char *str;
	cont_printf = printf("%p", &i);printf("\n");
	cont_ft_printf = ft_printf("%p", &i);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%p", &l);printf("\n");
	cont_ft_printf = ft_printf("%p", &l);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%p", &str);printf("\n");
	cont_ft_printf = ft_printf("%p", &str);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%p", &strlen);printf("\n");
	cont_ft_printf = ft_printf("%p", &strlen);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);

	//Tests de %%
	cont_printf = printf("%%");printf("\n");
	cont_ft_printf = ft_printf("%%");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("aa%%bb");printf("\n");
	cont_ft_printf = ft_printf("aa%%bb");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%%%%%%%%%%");printf("\n");
	cont_ft_printf = ft_printf("%%%%%%%%%%");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf(".%%.%%.%%.%%.%%.%%.%%.%%.");printf("\n");
	cont_ft_printf = ft_printf(".%%.%%.%%.%%.%%.%%.%%.%%.");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);

	//Test moulitest 06
	cont_printf = printf("s: %s, p: %p, d:%d", "a string", &ft_check_placeholder, 42);printf("\n");
	cont_ft_printf = ft_printf("s: %s, p: %p, d:%d", "a string", &ft_check_placeholder, 42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%s%p%d%d%p%s%p%p%s", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");printf("\n");
	cont_ft_printf = ft_printf("%s%p%d%d%p%s%p%p%s", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);

	//Tests de %i
	cont_printf = printf("%i", 42);printf("\n");
	cont_ft_printf = ft_printf("%i", 42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%i", -42);printf("\n");
	cont_ft_printf = ft_printf("%i", -42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("before %i after", 42);printf("\n");
	cont_ft_printf = ft_printf("before %i after", 42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("a%db%dc%dd", 1, -2, 3);printf("\n");
	cont_ft_printf = ft_printf("a%db%dc%dd", 1, -2, 3);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%i%i%i%i%i", 1, -2, 3, -4, 5);printf("\n");
	cont_ft_printf = ft_printf("%i%i%i%i%i", 1, -2, 3, -4, 5);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);


	//Tests de %u
	cont_printf = printf("%u", 42);printf("\n");
	cont_ft_printf = ft_printf("%u", 42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("before %u after", 42);printf("\n");
	cont_ft_printf = ft_printf("before %u after", 42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%u%u%u%u%u", 1, 100, 999, 42, 999988888);printf("\n");
	cont_ft_printf = ft_printf("%u%u%u%u%u", 1, 100, 999, 42, 999988888);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("a%ub%uc%ud", 0, 55555, 100000);printf("\n");
	cont_ft_printf = ft_printf("a%ub%uc%ud", 0, 55555, 100000);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%u", UINT_MAX);printf("\n");
	cont_ft_printf = ft_printf("%u", UINT_MAX);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	
	//Tests de %x
	cont_printf = printf("%x", 42);printf("\n");
	cont_ft_printf = ft_printf("%x", 42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("before %x after", 42);printf("\n");
	cont_ft_printf = ft_printf("before %x after", 42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%x%x%x%x%x", 1, 100, 999, 42, 999988888);printf("\n");
	cont_ft_printf = ft_printf("%x%x%x%x%x", 1, 100, 999, 42, 999988888);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("a%xb%xc%xd", 0, 55555, 100000);printf("\n");
	cont_ft_printf = ft_printf("a%xb%xc%xd", 0, 55555, 100000);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%x, %x", 0, UINT_MAX);printf("\n");
	cont_ft_printf = ft_printf("%x, %x", 0, UINT_MAX);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);

	//Tests de %X
	cont_printf = printf("%X", 42);printf("\n");
	cont_ft_printf = ft_printf("%X", 42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("before %X after", 42);printf("\n");
	cont_ft_printf = ft_printf("before %X after", 42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%X%X%X%X%X", 1, 100, 999, 42, 999988888);printf("\n");
	cont_ft_printf = ft_printf("%X%X%X%X%X", 1, 100, 999, 42, 999988888);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("a%Xb%Xc%Xd", 0, 55555, 100000);printf("\n");
	cont_ft_printf = ft_printf("a%Xb%Xc%Xd", 0, 55555, 100000);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%X, %X", 0, UINT_MAX);printf("\n");
	cont_ft_printf = ft_printf("%X, %X", 0, UINT_MAX);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);

	//Tests de %C
	cont_printf = printf("%c", 'c');
	cont_ft_printf = ft_printf("%c", 'c');
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%c%c", '4', '2');printf("\n");
	cont_ft_printf = ft_printf("%c%c", '4', '2');
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%c", 0);printf("\n");
	cont_ft_printf = ft_printf("%c", 0);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);

	//Otros tests
	int ncm_p = 5;
	cont_printf = printf("%p", &ncm_p);printf("\n");
	cont_ft_printf = ft_printf("%p", &ncm_p);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);

	cont_printf = printf("%p", NULL);printf("\n");
	cont_ft_printf = ft_printf("%p", NULL);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);

	cont_printf = printf("%%%c", 'x');printf("\n");
	cont_ft_printf = ft_printf("%%%c", 'x');
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);

	
	
	cont_printf += printf("  %d,%X %d,%X %d,%X %d,%X %d,%X %d,%X %d,%X", \
		INT_MAX, INT_MAX, INT_MIN, INT_MIN, LONG_MAX, LONG_MAX, LONG_MIN, LONG_MIN, ULONG_MAX, ULONG_MAX, 0, 0, -42, -42);printf("\n");
	cont_ft_printf += ft_printf("  %d,%X %d,%X %d,%X %d,%X %d,%X %d,%X %d,%X", \
		INT_MAX, INT_MAX, INT_MIN, INT_MIN, LONG_MAX, LONG_MAX, LONG_MIN, LONG_MIN, ULONG_MAX, ULONG_MAX, 0, 0, -42, -42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);


	
	
}
void test7()
{
	int cont_printf;
	int cont_ft_printf;
	
	int num = -5674556;
	cont_ft_printf = 0;
	cont_printf = 0;
	cont_printf = printf("%d, %x, %X", num, num, num);printf("\n");
	cont_ft_printf = ft_printf("%d, %x, %X", num, num, num);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);

	cont_printf = printf("  %d,%X %d,%X %d,%X %d,%X %d,%X %d,%X %d,%X", \
		INT_MAX, INT_MAX, INT_MIN, INT_MIN, LONG_MAX, LONG_MAX, LONG_MIN, LONG_MIN, ULONG_MAX, ULONG_MAX, 0, 0, -42, -42);printf("\n");
	cont_ft_printf = ft_printf("  %d,%X %d,%X %d,%X %d,%X %d,%X %d,%X %d,%X", \
		INT_MAX, INT_MAX, INT_MIN, INT_MIN, LONG_MAX, LONG_MAX, LONG_MIN, LONG_MIN, ULONG_MAX, ULONG_MAX, 0, 0, -42, -42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	

}

void test8()
{
	int cont_printf;
	int cont_ft_printf;
	
cont_printf = printf("%d,%X %d,%X %d,%X %d,%X %d,%X", \
		LONG_MAX, LONG_MAX, LONG_MIN, LONG_MIN, ULONG_MAX, ULONG_MAX, 0, 0, -42, -42);printf("\n");
	cont_ft_printf = ft_printf("%d,%X %d,%X %d,%X %d,%X %d,%X", \
		LONG_MAX, LONG_MAX, LONG_MIN, LONG_MIN, ULONG_MAX, ULONG_MAX, 0, 0, -42, -42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
}
void	test9()
{
	int	num = -645650;
	int cont_printf;
	int cont_ft_printf;
	cont_printf = printf("%d,%x", num, num);printf("\n");
	cont_ft_printf = ft_printf("%d,%x", num, num);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
}
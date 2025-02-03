/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:19:53 by mergarci          #+#    #+#             */
/*   Updated: 2025/01/28 17:10:14 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int	main(void)
{
	int	cont_printf;
	int	cont_ft_printf;

	//Tests de %s
	cont_printf = printf("This is a simple test.");
	cont_ft_printf = ft_printf("This is a simple test.");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("This is a simple test.\nSecond sentence.\n");
	cont_ft_printf = ft_printf("This is a simple test.\nSecond sentence.\n");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	//cont_printf = printf("");
	//cont_ft_printf = ft_printf("");
	//printf("\n***1: %d ***\n***2: %d ***\n----------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("\n");
	cont_ft_printf = ft_printf("\n");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%s", "abc");
	cont_ft_printf = ft_printf("%s", "abc");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("111%s333", "222");
	cont_ft_printf = ft_printf("111%s333", "222");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%s333", "222");
	cont_ft_printf = ft_printf("%s333", "222");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("111%s", "222");
	cont_ft_printf = ft_printf("111%s", "222");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("111%s333%s555", "222", "444");
	cont_ft_printf = ft_printf("111%s333%s555", "222", "444");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("111%s333%s555%saaa%sccc", "222", "444", "666", "bbb");
	cont_ft_printf = ft_printf("111%s333%s555%saaa%sccc", "222", "444", "666", "bbb");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%s%s%s%s%s", "1", "2", "3", "4", "5");
	cont_ft_printf = ft_printf("%s%s%s%s%s", "1", "2", "3", "4", "5");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	char *s = NULL;
	cont_printf = printf("%s", s);
	cont_ft_printf = ft_printf("%s", s);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);	

	//Tests de %d
	cont_printf = printf("%d", 42);
	cont_ft_printf = ft_printf("%d", 42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%d", -42);
	cont_ft_printf = ft_printf("%d", -42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("before %d after", 42);
	cont_ft_printf = ft_printf("before %d after", 42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("a%db%dc%dd", 1, -2, 3);
	cont_ft_printf = ft_printf("a%db%dc%dd", 1, -2, 3);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%d", INT_MAX);
	cont_ft_printf = ft_printf("%d", INT_MAX);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%d", INT_MIN);
	cont_ft_printf = ft_printf("%d", INT_MIN);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);


	//Tests de %p
	int i;
	unsigned long l;
	char *str;
	cont_printf = printf("%p", &i);
	cont_ft_printf = ft_printf("%p", &i);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%p", &l);
	cont_ft_printf = ft_printf("%p", &l);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%p", &str);
	cont_ft_printf = ft_printf("%p", &str);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%p", &strlen);
	cont_ft_printf = ft_printf("%p", &strlen);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);

	//Tests de %%
	cont_printf = printf("%%");
	cont_ft_printf = ft_printf("%%");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("aa%%bb");
	cont_ft_printf = ft_printf("aa%%bb");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%%%%%%%%%%");
	cont_ft_printf = ft_printf("%%%%%%%%%%");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf(".%%.%%.%%.%%.%%.%%.%%.%%.");
	cont_ft_printf = ft_printf(".%%.%%.%%.%%.%%.%%.%%.%%.");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);

	//Test moulitest 06
	cont_printf = printf("s: %s, p: %p, d:%d", "a string", &ft_check_placeholder, 42);
	cont_ft_printf = ft_printf("s: %s, p: %p, d:%d", "a string", &ft_check_placeholder, 42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%s%p%d%d%p%s%p%p%s", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
	cont_ft_printf = ft_printf("%s%p%d%d%p%s%p%p%s", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);

	//Tests de %i
	cont_printf = printf("%i", 42);
	cont_ft_printf = ft_printf("%i", 42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%i", -42);
	cont_ft_printf = ft_printf("%i", -42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("before %i after", 42);
	cont_ft_printf = ft_printf("before %i after", 42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("a%db%dc%dd", 1, -2, 3);
	cont_ft_printf = ft_printf("a%db%dc%dd", 1, -2, 3);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%i%i%i%i%i", 1, -2, 3, -4, 5);
	cont_ft_printf = ft_printf("%i%i%i%i%i", 1, -2, 3, -4, 5);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);


	//Tests de %u
	cont_printf = printf("%u", 42);
	cont_ft_printf = ft_printf("%u", 42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("before %u after", 42);
	cont_ft_printf = ft_printf("before %u after", 42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%u%u%u%u%u", 1, 100, 999, 42, 999988888);
	cont_ft_printf = ft_printf("%u%u%u%u%u", 1, 100, 999, 42, 999988888);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("a%ub%uc%ud", 0, 55555, 100000);
	cont_ft_printf = ft_printf("a%ub%uc%ud", 0, 55555, 100000);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%u", UINT_MAX);
	cont_ft_printf = ft_printf("%u", UINT_MAX);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	
	//Tests de %x
	cont_printf = printf("%x", 42);
	cont_ft_printf = ft_printf("%x", 42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("before %x after", 42);
	cont_ft_printf = ft_printf("before %x after", 42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%x%x%x%x%x", 1, 100, 999, 42, 999988888);
	cont_ft_printf = ft_printf("%x%x%x%x%x", 1, 100, 999, 42, 999988888);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("a%xb%xc%xd", 0, 55555, 100000);
	cont_ft_printf = ft_printf("a%xb%xc%xd", 0, 55555, 100000);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%x, %x", 0, UINT_MAX);
	cont_ft_printf = ft_printf("%x, %x", 0, UINT_MAX);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);

	//Tests de %X
	cont_printf = printf("%X", 42);
	cont_ft_printf = ft_printf("%X", 42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("before %X after", 42);
	cont_ft_printf = ft_printf("before %X after", 42);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%X%X%X%X%X", 1, 100, 999, 42, 999988888);
	cont_ft_printf = ft_printf("%X%X%X%X%X", 1, 100, 999, 42, 999988888);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("a%Xb%Xc%Xd", 0, 55555, 100000);
	cont_ft_printf = ft_printf("a%Xb%Xc%Xd", 0, 55555, 100000);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%X, %X", 0, UINT_MAX);
	cont_ft_printf = ft_printf("%X, %X", 0, UINT_MAX);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);

	//Tests de %C
	cont_printf = printf("%c", 'c');
	cont_ft_printf = ft_printf("%c", 'c');
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%c%c", '4', '2');
	cont_ft_printf = ft_printf("%c%c", '4', '2');
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);
	cont_printf = printf("%c", 0);
	cont_ft_printf = ft_printf("%c", 0);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);

	//Otros tests
	int ncm_p = 5;
	cont_printf = printf("%p", &ncm_p);
	cont_ft_printf = ft_printf("%p", &ncm_p);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);

	cont_printf = printf("%p", NULL);
	cont_ft_printf = ft_printf("%p", NULL);
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);

	cont_printf = printf("%%%c", 'x');
	cont_ft_printf = ft_printf("%%%c", 'x');
	printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);

	//++++++++++++++++++Probar en 42+++++++++++++
	/* cont_printf = printf("  %X %X %lX %lX %lX %X %X", \
		INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	cont_ft_printf = ft_printf("  %X %X %X %X %X %X %X", \
		INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42); 
	//printf("\n***1: %d ***\n***2: %d ***\n---------------\n", cont_printf, cont_ft_printf);

	(void)cont_ft_printf;
	printf("\n***1: %d ***--------------\n", cont_printf);*/

	return (0);
}
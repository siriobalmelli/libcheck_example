#include <unistd.h>
#include <money.h>
#include <stdio.h>

int main()
{
	struct Money *m = money_create(5, "USD");
	printf("got %d %s\n", money_amount(m), money_currency(m));
	money_free(m);
#if 0
	/* enable this to see address sanitizer complain about use-after-free */
	printf("got %d %s\n", money_amount(m), money_currency(m));
#endif
	return 0;
}

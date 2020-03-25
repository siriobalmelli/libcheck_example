#include <money.h>
#include <stdlib.h>

struct Money {
	int amount;
	char *currency;
};

Money *money_create(int amount, char *currency)
{
	struct Money *ret = malloc(sizeof(struct Money));
	ret->amount = amount;
	ret->currency = currency;
	return ret;
}

int money_amount(Money *m)
{
	return m->amount;
}

char *money_currency(Money *m)
{
	return m->currency;
}

void money_free(Money *m)
{
	free(m);
}

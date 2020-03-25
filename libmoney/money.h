#ifndef money_h_
#define money_h_

typedef struct Money Money;

Money *money_create(int amount, char *currency);
int money_amount(Money * m);
char *money_currency(Money * m);
void money_free(Money * m);

#endif /* money_h_ */

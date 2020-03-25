#include <check.h>
#include <money.h>

START_TEST(test_money_create)
{
	Money *m;

	m = money_create(5, "USD");
	ck_assert_int_eq(money_amount(m), 5);
	ck_assert_str_eq(money_currency(m), "USD");
	money_free(m);
}
END_TEST

Suite *money_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Money");

	/* Core test case */
	tc_core = tcase_create("Core");
	tcase_add_test(tc_core, test_money_create);

	suite_add_tcase(s, tc_core);
	return s;
}

int main(void)
{
	SRunner *sr = srunner_create(money_suite());

	srunner_run_all(sr, CK_NORMAL);
	int failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return failed;
}

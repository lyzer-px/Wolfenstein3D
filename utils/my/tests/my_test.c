#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../libmy.h"
#include <stdio.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_strlen, basic, .init = redirect_all_std)
{
    cr_assert_eq(my_strlen("Hello"), 5);
}

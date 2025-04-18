# include <criterion/criterion.h>
# include <criterion/redirect.h>
#include "../libgraphic.h"
#include <stdio.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(default, default, .init = redirect_all_std)
{
    cr_assert_eq(1, 1);
}

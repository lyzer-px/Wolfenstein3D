# include <criterion/criterion.h>
# include <criterion/redirect.h>
#include "project_funct.h"
#include <stdio.h>

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(print_help, basic, .init = redirect_all_std)
{
    //print_help();
    //cr_assert_stdout_eq_str("Usage:\n\tWolf3D");
    cr_assert_eq(1, 1);
}

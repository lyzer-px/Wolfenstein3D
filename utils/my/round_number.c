/*
** EPITECH PROJECT, 2025
** WOLF3D
** File description:
** Round a number
*/

double round_number(double nb, int digits)
{
    double round;

    for (int i = 0; i < digits; i++) {
        nb = nb * 10;
    }
    round = nb - (long)nb;
    round = (long)(round * 2);
    nb = (long)nb + round + 0.1;
    for (int i = 0; i < digits; i++) {
        nb = nb / 10;
    }
    return nb;
}

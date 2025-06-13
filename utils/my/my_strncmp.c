/*
** EPITECH PROJECT, 2025
** my_strncmp
** File description:
** duh
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i;

    for (i = 0; i < n && s1[i] == s2[i]; i += 1) {
    }
    if (i == n)
        return 0;
    if (s1[i] > s2[i])
        return s1[i] - s2[i];
    else if (s1[i] < s2[i])
        return s1[i] - s2[i];
    else
        return 0;
}

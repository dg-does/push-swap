#include "push_swap.h"
#include <unistd.h>

static void printnbr(int n)
{
    long nb = n;
    char c;

    if (nb < 0)
    {
        write(1, "-", 1);
        nb = -nb;
    }
    if (nb >= 10)
        printnbr(nb / 10);
    c = nb % 10 + '0';
    write(1, &c, 1);
}

#include "push_swap.h"
#include <unistd.h>

/* helper to print an integer */
static void ft_putnbr_fd(int n, int fd)
{
    long num;
    char c;

    num = n;
    if (num < 0)
    {
        write(fd, "-", 1);
        num = -num;
    }
    if (num >= 10)
        ft_putnbr_fd(num / 10, fd);
    c = (num % 10) + '0';
    write(fd, &c, 1);
}

/* print stack with full integers */
void debug_stack(const char *label, t_node *a, t_node *b)
{
    t_node *tmp;

    if (a)
    {
        write(1, label, strlen(label));
        write(1, " A: ", 4);
        tmp = a;
        while (tmp)
        {
            ft_putnbr_fd(tmp->value, 1);
            write(1, " ", 1);
            tmp = tmp->next;
        }
        write(1, "\n", 1);
    }

    if (b)
    {
        write(1, label, strlen(label));
        write(1, " B: ", 4);
        tmp = b;
        while (tmp)
        {
            ft_putnbr_fd(tmp->value, 1);
            write(1, " ", 1);
            tmp = tmp->next;
        }
        write(1, "\n", 1);
    }
}

void    print_stack(t_node *a)
{
    while (a)
    {
        ft_putnbr_fd(a->value, 1);
        write(1, " ", 1);
        a = a->next;
    }
    write(1, "\n", 1);
}

void debug_mask(const char *msg, int *mask, int size)
{
    int i;

    if (!DEBUG)
        return ;
    write(1, msg, strlen(msg));
    write(1, " mask: ", 7);
    i = 0;
    while (i < size)
    {
        printnbr(mask[i]);
        write(1, " ", 1);
        i++;
    }
    write(1, "\n", 1);
}

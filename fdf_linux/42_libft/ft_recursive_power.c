#include <libft.h>
#include <ft_printf.h>

int	ft_recursive_power(int nb, int power)
{
	if (power == 1)
		return nb;
	nb *= ft_recursive_power(nb, power - 1);
	if (nb > 2147483647 || nb < 0)
		return 0;
	return nb;
}
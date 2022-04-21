#include <libft.h>
#include <ft_printf.h>

int	ft_hex_ch_to_dec(char a)
{
	if (a == 'a' || a == 'A')
		return (10);
	else if (a == 'b' || a == 'B')
		return (11);
	else if (a == 'c' || a == 'C')
		return (12);
	else if (a == 'd' || a == 'D')
		return (13);
	else if (a == 'e' || a == 'E')
		return (14);
	else if (a == 'f' || a == 'F')
		return (15);
	else
		return ((int)(a - 48));
}

int	ft_hexStr_toInt(char *str)
{
	int	n;
	int	i;

	while(*str && (*str != 'x' && *str != 'X'))
		str++;
	while(*str && (*str == 'x' || *str == 'X'))
		str++;
	while(*str && *str == '0')
		str++;
	i = 0;
	n = 0;
	while (*str)
	{
		n += ft_recursive_power(ft_hex_ch_to_dec(*str), i);
		i++;
		str++;
	}
	return (n);
}

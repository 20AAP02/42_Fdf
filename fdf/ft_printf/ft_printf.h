/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:58:26 by amaria-m          #+#    #+#             */
/*   Updated: 2021/12/04 22:50:53 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h> // write
# include <stdarg.h> // va_list
# include <stdlib.h> // malloc

typedef struct t_print_settings
{
	va_list	args;
	int		hash;
	int		zero;
	int		dash;
	int		space;
	int		plus;
	int		width;
	int		prec;
	int		point;
	int		t_length;
}	t_settings;

char		*ft_exection_t(char a, char *str);
char		*ft_nil(char *a);
int			ft_pf_strlen(const char *s);
char		*ft_printf_substr(char const *s, unsigned int start, size_t len);
int			ft_printf_atoi(const char *str);
int			number_of_digits(long long nb);
void		pass_int_to_str(long long *nb, char *str, int *i);
char		*ft_printf_itoa(int n);
char		*ft_printf_itoa_unsigned_int(unsigned int n);
t_settings	*ft_initialise_tab(t_settings *tab);
t_settings	*set_tab(t_settings *tab);
void		ft_print_padding(t_settings *tab, char pad, int times);
void		ft_print_percent(t_settings *tab, char percent);
void		ft_print_char(t_settings *tab);
void		ft_print_s_dash(t_settings *tab, const char *str);
void		ft_print_s_no_dash(t_settings *tab, const char *str);
void		ft_print_string(t_settings *tab);
int			ft_count_digits(unsigned long i);
char		*ft_putnbr_base(char *str, unsigned long nbr, char *base);
char		*long_to_string(unsigned long i);
void		ft_print_p_zero_pad(t_settings *tab, char *str);
void		ft_print_void(t_settings *tab);
char		*ft_add_beg_str(char *str, int times, char a, int t);
char		*ft_add_char_to_end_str(char *str, int times, char a);
void		ft_print_dec_update_tab(t_settings *tab);
void		print_dec_num_block(t_settings *tab, char *str, int nbr);
void		ft_print_dec_num(t_settings *tab);
void		print_unsigned_dec_block(t_settings *tab, char *str);
void		ft_print_unsigned_dec(t_settings *tab);
char		*ft_uns_int_dec_to_hex(unsigned int i, char a);
void		print_num_hex_block(t_settings *tab, char *str, char l, int nbr);
void		ft_print_num_hex(t_settings *tab, char l);
int			ft_is_format(char letter, char *conversions);
int			ft_convert(t_settings *tab, const char *format, int i);
int			ft_analise_prec(t_settings *tab, const char *format, int i);
int			ft_analise_width(t_settings *tab, const char *format, int i);
int			is_flag(char letter, char *flags);
int			ft_analise_flags(t_settings *tab, const char *format, int i);
int			ft_printf(const char *format, ...);

#endif
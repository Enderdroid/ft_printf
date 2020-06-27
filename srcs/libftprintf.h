#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

# define P_SIZE 50
# define LONG_T unsigned long long int

typedef struct	s_sarg
{
	long long	width;
	long long	perc;
	char		flags[7];
	char		mode;
	char		type;
}				t_sarg;

int				ft_parse(const char *src, va_list *factor, t_sarg *pref);
int				ft_print(t_sarg *pref, va_list *factor, int *ret);
int				ft_print_i(t_sarg *pref, long long num);
int				ft_print_u(t_sarg *pref, LONG_T num);
int				ft_print_c(t_sarg *pref, char c);
int				ft_print_s(t_sarg *pref, char *s);
int				ft_print_hex(t_sarg *pref, LONG_T num);
int				ft_putchar(char c, int fd);
void			ft_printstr(char *pattern, char *arg, int is_z);
int				ft_free_p(void *arg, void *pattern, void *o_str, int key);
char			*ft_pattern(t_sarg *pref, int a_size,\
				int n_size, int is_perc);
int				ft_printf(const char *s, ...);
int				ft_validate(t_sarg *pref);
t_sarg			*ft_reset(t_sarg *pref);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 11:14:43 by mpaincha          #+#    #+#             */
/*   Updated: 2016/03/09 17:58:04 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../Libft/includes/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

/*
**	% [drapeaux] [largeur] [.precision] [modificateur] type
*/

# define FLAGS	"#0-+ "
# define MOD	"hljz"
# define SPEC	"spdouxXc%%"
# define ARG	((t_arg *)(tmpa->content))
# define SFLAGS	((t_flags)(ARG->flags))
# define SMOD	((t_mod)(ARG->mod))
# define SPREC	((t_prec)(ARG->prec))
# define SSTR	((t_str *)(tmps->content))

/*
**	# define SSTR(X) ((t_str *)((X)->content))
**	# define DEBUG	printf("%s - %s: %d\n", __FILE__, __FUNCTION__, __LINE__)
*/

typedef struct		s_counters
{
	int				i;
	int				oct;
	int				cpt_null;
}					t_counters;

typedef struct		s_mask
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;
	unsigned int	new_nb;
}					t_mask;

typedef struct		s_str
{
	char			*str;
	int				n;
}					t_str;

typedef struct		s_mod
{
	int				h;
	int				l;
	int				j;
	int				z;
}					t_mod;

typedef struct		s_flags
{
	int				diez;
	int				zero;
	int				minus;
	int				plus;
	int				space;
	size_t			width;
}					t_flags;

typedef struct		s_prec
{
	int				pt;
	size_t			n;
}					t_prec;

typedef struct		s_arg
{
	void			*arg;
	t_flags			flags;
	t_mod			mod;
	t_prec			prec;
	char			*spec;
	int				action;
}					t_arg;

typedef	void		(*t_action)(t_elem *, char **, int *);

int					ft_printf(const char *format, ...);
void				display_percent(int n, t_dbllist *lst_str);
int					recover_arg(const char *format, t_dbllist *lst_arg, \
					t_dbllist *lst_str, int *i);
int					percent(const char *format, t_dbllist *lst_arg, \
					t_dbllist *lst_str, int *i);
int					split_arg(const char *format, t_dbllist *lst_arg, \
					t_dbllist *lst_str, int *i);
void				recover_param(va_list ap, t_dbllist *lst_arg);

void				ini_sarg(t_arg *sarg);
void				ini_sstr(t_str *sstr);
void				ini_mask(t_mask *mask);
void				ini_counters(t_counters *counters);
void				reini_mod(t_arg *sarg);

int					checks(const char *format, int *i, t_arg *sarg);
int					check_spec(const char *format, int *i, t_arg *sarg);
int					check_prec(const char *format, int *i, t_arg *sarg);
int					check_mod(const char *format, int *i, t_arg *sarg);
int					check_width(char *str, t_arg *sarg, int *i);
int					check_flags(const char *format, int *i, t_arg *sarg);

void				ft_putlststr(t_dbllist *lst_str, int *oct);
int					stock_str(const char *format, int	i, t_dbllist *lst_str);
void				cleanarg(t_dbllist *lst_arg);
void				transformation(t_dbllist *lst_arg, t_dbllist *lst_str, \
					int *cpt_null);

void				ft_string(t_elem *tmpa, char **str, int *cpt_null);
void				ft_ptr(t_elem *tmpa, char **str, int *cpt_null);
void				ft_dec(t_elem *tmpa, char **str, int *cpt_null);
void				ft_octal(t_elem *tmpa, char **str, int *cpt_null);
void				ft_unsig(t_elem *tmpa, char **str, int *cpt_null);
void				ft_hexalower(t_elem *tmpa, char **str, int *cpt_null);
void				ft_hexaupper(t_elem *tmpa, char **str, int *cpt_null);
void				ft_char(t_elem *tmpa, char **str, int *cpt_null);
void				ft_unknown(t_elem *tmpa, char **str, int *cpt_null);

char				*mod_string(t_elem *tmpa);
char				*mod_dec(t_elem *tmpa);
char				*mod_octal(t_elem *tmpa);
char				*mod_unsig(t_elem *tmpa);
char				*mod_hexa(t_elem *tmpa);
char				*mod_char(t_elem *tmpa);

void				diez_o(char **str);
void				diez_hexaupper_zero(char **str, size_t len, t_elem *tmpa);
void				diez_hexaupper(char **str);

void				width(t_elem *tmpa, char **str);

void				space_afterwidth(t_elem *tmpa, char **str, size_t len);
void				space_beforewidth(char **str);

void				plus_space(t_elem *tmpa, char **str, size_t	len);
void				plus_zero(t_elem *tmpa, char **str, size_t	len);
void				minus_space(t_elem *tmpa, char **str, size_t len);
void				minus_zero(t_elem *tmpa, char **str, size_t len);

void				prec_doux(t_elem *tmpa, char **str);
void				prec_s(t_elem *tmpa, char **str);

char				*ft_wchar_str(t_elem *tmpa);
char				*mask_prec(wchar_t c, t_elem *tmpa, size_t *oct);
char				*mask(wchar_t c);
char				*fill_mask(wchar_t nb);
char				*fill_maska(wchar_t snb);
char				*fill_maskb(wchar_t nb);
char				*fill_maskc(wchar_t nb);

void				ft_lstdbldel_str(t_dbllist *list);
void				ft_lstdbldel_arg(t_dbllist *list);
void				ft_strlower(char **str);

char				*ft_itoabase_imax(intmax_t n, size_t base);
char				*ft_itoabase_uimax(uintmax_t n, size_t base);

#endif

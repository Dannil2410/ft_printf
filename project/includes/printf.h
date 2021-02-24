/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 05:52:50 by sazalee           #+#    #+#             */
/*   Updated: 2020/03/03 20:22:48 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct			s_info
{
	int					fhash;
	int					fzero;
	int					fminus;
	int					fplus;
	int					fspace;
	int					width;
	int					point;
	int					precs;
	int					modif;
	int					conv;
	int					valid;
	int					temp;
	int					negativ;
	int					nan;
	int					inf;
}						t_info;

int						ft_printf(const char *format, ...);
int						handleo(t_info *base, va_list args);
int						handlet(t_info *base, va_list args);
int						handlex(t_info *base, va_list args);
int						handlepct(t_info *base);
int						handlef(t_info *base, va_list args);
long long int			modiftransform(t_info *base, va_list args);
void					structcheck(t_info *base, int length,
		int pflength, int temp);
int						lengthprintf(t_info *base, int length, char *temp);
char					*ft_sixteenoa(void *pointer, char temp);
void					putlenchar(int length, char temp);
int						putlencharu(t_info *base, unsigned long long number,
		char *r, char *temp);
void					structfcheck(t_info *base, int pflengthf, int temp);
int						lengthfprintf(t_info *base, char *big);
long double				precisioner(int precs);
long double				rounder(t_info *base, long double number);
void					flagcheckf(t_info *base, long double number);
char					*ft_baseoau(unsigned long long int number,
		int base, char temp);
char					signcheck(t_info *base, long long int number);
int						printfloat(t_info *base, char *big,
		char *small, char sign);
int						baser(unsigned long long number, int base);
char					*ft_baseoa(long long int number);
void					flaghelpf(t_info *base);
long double				smallfloathelp(char *big);
char					*smallfloat(t_info *base, long double number,
		int precs, char *big);
int						lengthfloat(long double number);
char					*bigfloat(long double number);
char					signcheckf(t_info *base, long double number);
void					freetime(t_info *base, char *big, char *small);
long double				modiftransformf(t_info *base, va_list args);
unsigned long long int	modiftransformu(t_info *base, va_list args);
void					flagcheck(t_info *base);
int						handlec(t_info *base, va_list args);
int						handles(t_info *base, va_list args);
int						handlep(t_info *base, va_list args);
int						handled(t_info *base, va_list args);
int						handleu(t_info *base, va_list args);
const char				*parsec(const char *format, t_info *base);
int						parsem(const char *format, t_info *base);
const char				*parsep(const char *format, t_info *base, va_list args);
const char				*parsew(const char *format, t_info *base, va_list args);
const char				*parsef(const char *format, t_info *base);
int						parsestar(int star, t_info *base, va_list args);
int						checksym(const char *format, char *temp);
int						handlenopct(const char *format);
int						handleall(t_info *base, va_list args);
int						parser(const char *format, t_info *base, va_list args);
void					initstruct(t_info *base, int *major);
void					writestr(char *temp, int length, int modif);
void					ft_timetwo(int sec);
void					ft_timeone(int sec, int flag);
int						ft_time(int sec);
int						ft_nbr_of_year(int nbr, int flag);
int						ft_nbr_of_yearthree(int nbr, int flag, int flag_d);
int						ft_nbr_of_yeartwo(int nbr, int flag, int flag_d);
int						ft_nbr_of_yearone(int month, int flag);
void					ft_rot(char *s);
int						ft_nbr_of_yearfour(int n, int flag, int flag_d);

#endif

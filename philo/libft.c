#include "philo.h"

int	ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}

static double	check_dot(const char *str, int i, double res, int is_neg)
{
	double	dot_res;

	if (str[i] != '.')
		return (res);
	i++;
	if (is_neg < 0)
		dot_res = -0.1;
	else
		dot_res = 0.1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res += dot_res * (str[i++] - '0');
		dot_res *= 0.1;
	}
	return (res);
}

double	ft_atof(const char *str)
{
	size_t	i;
	int		is_neg;
	double	res;

	if (!str)
		return (-1);
	i = 0;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		is_neg = -1;
	else
		is_neg = 1;
	if (is_neg == -1 || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	res = check_dot(str, i, res * is_neg, is_neg);
	return (res);
}

#include "ft_printf.h"

static char		*itop(unsigned long n)
{
	char	*ans;
	size_t	i;
	unsigned long	j;

	i = 3;
	j = n;
	while (n /= 16)
		i++;
	if (!(ans = ft_calloc((i + 1), 1)))
		return (0);
	ans[0] = '0';
	while (j)
	{
		n = j % 16;
		if (n > 9)
			ans[--i] = 'a' + (n - 10);
		else
			ans[--i] = '0' + n;
		j /= 16;
	}
	ans[0] = '0';
	ans[1] = 'x';
	return (ans);
}

static int checklen(unsigned long val)
{
	int	i;

	if (val == 0)
		return (1);
	i = 0;
	while (val)
	{	
		i++;
		val /= 16;
	}
	return (i);
}

static int	sort(t_cfc cfc, unsigned long val, int len)
{
	char	*buf;
	char	*temp;

	if (!(buf = ft_calloc(cfc.width + 1, 1)) || !(temp = itop(val)))
		return (-1);
	ft_memset(buf, ' ', cfc.width);
	ft_strlcpy(buf, temp, len + 1);	
	buf[len] = ' ';
	buf[cfc.width] = 0;
	write(1, buf, ft_strlen(buf));
	free(buf);
	free(temp);	
	return (cfc.width);
}

static int	basic(t_cfc cfc, unsigned long val, int len)
{
	char	*buf;
	char	*temp;

	if (!(buf = ft_calloc(cfc.width + 1, 1)) || !(temp = itop(val)))
		return (-1);
	ft_memset(buf, ' ', cfc.width);
	ft_strlcpy(buf + (cfc.width - len), temp, len + 1);
	write(1, buf, ft_strlen(buf));
	free(buf);
	free(temp);
	return (cfc.width);
}

int gop(t_cfc cfc, va_list ap)
{
	unsigned long val;
	int		len;

	val = (unsigned long)va_arg(ap, void *);
	len = checklen(val) + 2;
	if (cfc.width <= 14)
		return (write(1, itop(val), 14));
	else
		if (cfc.sort1zero2 == 1)
			return (sort(cfc, val, len));
		else
			return (basic(cfc, val, len));
}
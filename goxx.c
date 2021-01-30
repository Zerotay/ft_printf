#include "ft_printf.h"

char		*itoxx(unsigned int n)
{
	char	*ans;
	size_t	i;
	unsigned int	j;

	i = 1;
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
			ans[--i] = 'A' + (n - 10);
		else
			ans[--i] = '0' + n;
		j /= 16;
	}
	return (ans);
}

static int checklen(unsigned int val)
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

static int	precisionlong(t_cfc cfc, int val, int len)
{
	char	*buf;
	char	*temp;
	int		i;
	int		ret;

	i = 0;
	if (!(buf = ft_calloc(cfc.precision + 1, 1)) || !(temp = itoxx(val)))
		return (-1);
	while (cfc.precision-- - len)
		buf[i++] = '0';
	ft_strlcpy(buf + i, temp, len + 1);
	ret = write(1, buf, ft_strlen(buf));
	free(temp);
	free(buf);
	return (ret);
}

static int	sort(t_cfc cfc, int val, int len)
{
	char	*buf;
	char	*temp;
	int		i;
	int		zero;

	i = 0;
	if (!(buf = ft_calloc(cfc.width + 1, 1)) || !(temp = itoxx(val)))
		return (-1);
	if (cfc.precision >= len)
	{
		zero = cfc.precision - len;
		while (zero--)
			buf[i++] = '0';
	}
	ft_strlcpy(buf + i, temp, len + 1);	
	i = cfc.precision >= len ? cfc.precision : len;
	while (i < cfc.width)
		buf[i++] = ' ';
	buf[cfc.width] = 0;
	write(1, buf, ft_strlen(buf));
	free(buf);
	free(temp);	
	return (cfc.width);
}

static int zero(t_cfc cfc, int val, int len)
{
	char	*buf;
	char	*temp;
	int		i;

	i = 0;
	if (!(buf = (char *)malloc(sizeof(char) * (cfc.width + 1))))
		return (-1);
	buf[cfc.width] = 0;
	if (!(temp = itoxx(val)))
		return (-1);
	while (i < cfc.width - len)
		buf[i++] = '0';
	ft_strlcpy(buf + i, temp, len + 1);
	write(1, buf, ft_strlen(buf));
	free(buf);
	free(temp);
	return (cfc.width);
}

static int	basic(t_cfc cfc, int val, int len)
{
	char	*buf;
	char	*temp;
	int		i;

	i = 0;
	if (!(buf = (char *)malloc(sizeof(char) * (cfc.width + 1))))
		return (-1);
	buf[cfc.width] = 0;
	if (!(temp = itoxx(val)))
		return (-1);
	if (cfc.precision >= len)
	{
		while (i < cfc.width - cfc.precision)
			buf[i++] = ' ';
		while (cfc.precision-- - len)
			buf[i++] = '0';
		ft_strlcpy(buf + i, temp, len + 1);
	}
	else
	{
		while (i < cfc.width - len)
			buf[i++] = ' ';
		ft_strlcpy(buf + i, temp, len + 1);
	}
	write(1, buf, ft_strlen(buf));
	free(buf);
	free(temp);
	return (cfc.width);
}

static int	onlyfornull(t_cfc cfc)
{
	char *buf;

	if (!(buf = ft_calloc(cfc.width + 1, 1)))
		return (0);
	ft_memset(buf, ' ', cfc.width);
	write(1, buf, cfc.width);
	free(buf);
	return (cfc.width);
}

int	goxx(t_cfc cfc, va_list ap)
{
	unsigned int	val;
	int	len;

	val = va_arg(ap, unsigned int);
	len = checklen(val);
	if (!val && !cfc.precision)
		return (onlyfornull(cfc));
	else
		if (cfc.width < len)
			if (cfc.precision >= len)
				return (precisionlong(cfc, val, len));
			else
				return (write(1, itoxx(val), len));
		else
			if (cfc.precision >= cfc.width)
				return (precisionlong(cfc, val, len));
			else
				if (cfc.sort1zero2 == 1)
					return (sort(cfc, val, len));
				else if (cfc.sort1zero2 == 2)
					return (zero(cfc, val, len));
				else
					return (basic(cfc, val, len));
}
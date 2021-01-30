#include "ft_printf.h"

int checklen(int val)
{
	int	i;

	if (val == 0)
		return (1);
	i = val < 0 ? 1 : 0;
	while (val)
	{	
		i++;
		val /= 10;
	}
	return (i);
}

int	precisionlong(t_cfc cfc, int val, int len)
{
	char	*buf;
	char	*temp;
	int		i;
	int		ret;

	i = 0;
	if(!(buf = (char *)malloc(sizeof(char) * (cfc.precision + 1))))
		return (-1);
	buf[cfc.precision] = 0;
	if(!(temp = ft_itoa(val)))
		return (-1);
	if (val < 0)
		buf[i++] = '-';
	while (cfc.precision-- - len)
		buf[i++] = '0';
	ft_strlcpy(buf + i, temp, len + 1);
	if (val < 0)
		buf[i] = '0';
	ret = write(1, buf, ft_strlen(buf));
	free(temp);
	free(buf);
	return (ret);
}

int	sort(t_cfc cfc, int val, int len)
{
	char	*buf;
	char	*temp;
	int		i;

	i = cfc.precision >= len ? cfc.precision - len : 0;
	i = (cfc.precision >= len && val < 0) ? i + 1 : i;
	if (!(buf = ft_calloc(cfc.width + 1, 1)) || !(temp = ft_itoa(val)))
		return (-1);
	if (cfc.precision >= len)
		ft_memset(buf, '0', cfc.width);
	ft_strlcpy(buf + i, temp, len + 1);
	buf[i] = ((val < 0) && (cfc.precision >= len)) ? '0' : buf[i];
	i = cfc.precision >= len ? cfc.precision : len;
	i = ((i == cfc.precision) && (val < 0)) ? i + 1 : i;
	ft_memset(buf + i, ' ', cfc.width - i);
	buf[0] = val < 0 ? '-' : buf[0];
	write(1, buf, ft_strlen(buf));
	free(buf);
	free(temp);	
	return (cfc.width);
}

int	basic(t_cfc cfc, int val, int len)
{
	char	*buf;
	char	*temp;
	int		i;

	i = cfc.precision > len ? cfc.precision : len;
	if (!(buf = ft_calloc(cfc.width + 1, 1)) || !(temp = ft_itoa(val)))
		return (-1);
	ft_memset(buf, ' ', cfc.width);
	if (cfc.precision >= len)
	{
		ft_memset(buf + cfc.width - cfc.precision, '0', cfc.precision);
		buf[cfc.width - i - 1] = val < 0 ? '-' : buf[cfc.width - i - 1];
	}	
	len = checklen(val);
	i = cfc.width - len;
	ft_strlcpy(buf + i, temp, len + 1);
	buf[i] = ((val < 0) && (cfc.precision >= len)) ? '0' : buf[i];
	write(1, buf, ft_strlen(buf));
	free(buf);
	free(temp);
	return (cfc.width);
}

int zero(t_cfc cfc, int val, int len)
{
	char	*buf;
	char	*temp;
	int		i;

	if(cfc.onlyfors && cfc.precision >= 0)
		return (basic(cfc, val, len));
	i = val < 0 ? cfc.width - len + 1 : cfc.width - len;
	if (!(buf = ft_calloc(cfc.width + 1, 1)) || !(temp = ft_itoa(val)))
		return (-1);
	ft_memset(buf, '0', cfc.width);
	buf[0] = val >= 0 ? buf[0] : '-';
	ft_strlcpy(buf + i, (val < 0 ? temp + 1 : temp), len + 1);
	write(1, buf, ft_strlen(buf));
	free(buf);
	free(temp);
	return (cfc.width);
}

int	onlyfornull(t_cfc cfc)
{
	char *buf;

	if (!(buf = ft_calloc(cfc.width + 1, 1)))
		return (0);
	ft_memset(buf, ' ', cfc.width);
	write(1, buf, cfc.width);
	free(buf);
	return (cfc.width);
}

int	godi(t_cfc cfc, va_list ap)
{
	int	val;
	int	len;

	val = va_arg(ap, int);
	len = checklen(val);
	if (!val && !cfc.precision)
		return (onlyfornull(cfc));
	else
		if (cfc.width < len)
			if (cfc.precision >= len)
				return (precisionlong(cfc, val, len));
			else
				return (write(1, ft_itoa(val), len));
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
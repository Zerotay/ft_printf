#include "ft_printf.h"

static int sort(t_cfc cfc, char *val, int len)
{
	char *buf;
	
	if (!(buf = ft_calloc(cfc.width + 1, 1)))
		return (-1);
	ft_memset(buf, ' ', cfc.width);
	ft_strlcpy(buf, val, len + 1);
	buf[len] = ' ';
	write(1, buf, ft_strlen(buf));
	free(buf);
	return (cfc.width);
}

static int	basic(t_cfc cfc, char *val, int len)
{
	char *buf;

	if (!(buf = ft_calloc(cfc.width + 1, 1)))
		return (-1);
	ft_memset(buf, ' ', cfc.width);
	ft_strlcpy(buf + (cfc.width - len), val, len + 1);
	write(1, buf, ft_strlen(buf));
	free(buf);
	return (cfc.width);
}

int gos(t_cfc cfc, va_list ap)
{
	char	*val;
	int		len;

	val = va_arg(ap, char *);
	if (!cfc.precision && !val)
		return (write(1, "(null)", 6));
	cfc.onlyfors = cfc.precision < 0 ? 0 : cfc.onlyfors;
	len = cfc.precision < (int)ft_strlen(val) ? cfc.precision : (int)ft_strlen(val);
	if (cfc.onlyfors)
		if (cfc.width <= len)
			return (write(1, val, len));
		else
			if (cfc.sort1zero2 == 1)
				return (sort(cfc, val, len));
			else
				return (basic(cfc, val, len));		
	else
		if (cfc.width <= (int)ft_strlen(val))
			return (write(1, val, ft_strlen(val)));
		else
			if (cfc.sort1zero2 == 1)
				return (sort(cfc, val, ft_strlen(val)));
			else
				return (basic(cfc, val, ft_strlen(val)));
	return (0);
}
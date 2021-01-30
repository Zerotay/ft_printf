#include "ft_printf.h"

static int sort(t_cfc cfc, char val)
{
	char	*buf;
	int		i;

	if (!(buf = ft_calloc(cfc.width + 1, 1)))
		return (-1);
	i = 1;
	while (i < cfc.width)
		buf[i++] = ' ';
	buf[0] = val;
	write(1, buf, ft_strlen(buf));
	free(buf);
	return (cfc.width);
}

static int basic(t_cfc cfc, char val)
{
	char	*buf;
	int		i;

	if (!(buf = ft_calloc(cfc.width + 1, 1)))
		return (-1);
	i = 0;
	while (i < cfc.width)
		buf[i++] = ' ';
	buf[i - 1] = val;
	write(1, buf, ft_strlen(buf));
	free(buf);
	return (cfc.width);
}

int goc(t_cfc cfc, va_list ap)
{
	char	val;

	val = va_arg(ap, int);
	if (cfc.width > 1)
		if (cfc.sort1zero2 == 1)
			return (sort(cfc, val));
		else
			return (basic(cfc, val));
	else
		return (write(1, &val, 1));
}
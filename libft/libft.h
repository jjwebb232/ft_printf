/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:28:01 by jwebb             #+#    #+#             */
/*   Updated: 2017/06/21 12:51:38 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# define ISNUM(x) x >= '0' && x <= '9'
# define ISLOWER(x) x >= 'a' && x <= 'z'
# define ISUPPER(x) x >= 'A' && x <= 'Z'
# define WHITESPACE(x) x == ' ' || x == '\n' || x == '\t'
# define SIZE_LD long double

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

# ifndef T_MLX
#  define T_MLX

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				size;
	int				end;
}					t_mlx;
# endif

typedef struct		s_pixel
{
	int				red;
	int				green;
	int				blue;
	int				x;
	int				y;
}					t_pixel;

typedef struct		s_coords
{
	int				x;
	int				y;
	int				z;
}					t_coords;

typedef struct		s_line
{
	t_pixel			point;
	int				x;
	int				y;
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				err;
	int				e2;
}					t_line;

int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isspace(int c);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putwchar(wchar_t wc);
void				ft_putwstr(const wchar_t *s);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
int					ft_nbrlen(long n);
int					ft_unbrlen(unsigned long n);
int					ft_sqrt(size_t nb);
int					ft_is_prime(int n);
void				ft_putnbr(int n);
void				ft_putunbr(unsigned int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putascii(int n);
void				ft_putshort(int n);
void				ft_putlong(long n);
void				ft_putlonglong(long long n);
void				ft_putulong(unsigned long n);
void				ft_putulonglong(unsigned long long n);
void				ft_putsize_t(size_t n);
void				ft_putintmax_t(intmax_t n);
void				ft_putuintmax_t(uintmax_t n);
void				ft_swap(int *a, int *b);
int					ft_atoi(const char *str);
char				*ft_ultoul_base(unsigned long n, int base);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memrcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strnew(size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strtrim(char const *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_strdel(char **as);
char				*ft_itoa(int n);
char				*ft_ltoa(long n);
char				*ft_itoh(long n);
char				*ft_uctoa_base(short n, int base);
char				*ft_ustoa_base(int n, int base);
char				*ft_uitoa_base(long n, int base);
char				*ft_ultoa_base(long long n, int base);
char				*ft_imtoa_base(intmax_t n, int base);
char				*ft_uimtoa_base(intmax_t n, int base);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_memdel(void **ap);
void				*ft_realloc(void *ptr, size_t size);
int					ft_wordlen(char const *s, char const d);
int					ft_wordcount(char const *str, char d);
char				**ft_strsplit(char const *s, char c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
SIZE_LD				ft_cvrtnbr(SIZE_LD src[2], SIZE_LD new[2], SIZE_LD n);
void				ft_putpixel(t_pixel *pixel, t_mlx *mlx, int w, int h);
void				ft_fillpixel(t_pixel *pixel, int x, int y, int c);
void				ft_matbzero(float mat[4][4]);
void				ft_matidentity(float mat[4][4]);
void				ft_matmultiply(float mat1[4][4], float mat2[4][4],
						float dst[4][4]);
void				ft_matrotate(float mat[4][4], float psi, float phi,
						float theta);
void				ft_matscale(float mat[4][4], float x, float y, float z);
void				ft_matxpoint(float mat[4][4], t_coords *coords);
void				ft_buildline(t_line *line, t_coords coords1,
						t_coords coords2, int c);
void				ft_printline(t_line line, t_mlx *mlx,
						int width, int height);
int					ft_wctomb(char *s, wchar_t wc);
void				ft_addchar(char **str, char c);
char				*ft_getwchar(wchar_t wc);
void				ft_addwstr(char **str, wchar_t *ws);
void				ft_addstr(char **str, char *s);

#endif

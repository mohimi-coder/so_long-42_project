/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:58:14 by mohimi            #+#    #+#             */
/*   Updated: 2024/03/06 22:37:33 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <limits.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_vars
{
	void	*win;
	void	*mlx;
	void	*w;
	void	*p_r;
	void	*p_l;
	void	*p_up;
	void	*p_d;
	void	*l;
	void	*e;
	void	*c;
	int		hie;
	int		wid;
	int		x;
	int		y;
	int		e_x;
	int		e_y;
	int		count_c;
	char	**map;
	int		count_move;
}			t_vars;

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_sersh_for_newline(const char *s, int c);
int		key_hook(int keycode, t_vars *vars);
char	*get_next_line(int fd);
char	**read_map(char	*str);
char	**ft_split(char const *s, char c);
void	draw_map(t_vars *arg);
void	set_hei_wid(t_vars *arg);
void	set_positions(t_vars *arg);
int		key_hook(int keycode, t_vars *vars);
void	you_win(t_vars *arg, int x, int y);
void	check_boundary(t_vars *arg);
void	ft_error_message(char *mess);
void	check_length_map(t_vars *arg);
void	check_lines_of_map(t_vars *arg);
void	check_map(t_vars *arg);
void	check_player_count(t_vars *arg);
void	check_exit_count(t_vars *arg);
void	ft_putnbr(int n);
void	check_file_isvalid(char *file);
int		ft_exit(t_vars *arg);
void	check_elements_presence(t_vars *arg);
int		count_element(t_vars *arg, char c, char **map);
void	flood(t_vars *arg, char *map);
void	ft_free_leak(char **str);
// # define malloc(x) malloc(-1)
#endif

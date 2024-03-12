/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:03:51 by mohimi            #+#    #+#             */
/*   Updated: 2024/03/08 18:30:57 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	void	*n_d;
	void	*n_u;
	void	*n_l;
	void	*n_r;
	int		hie;
	int		wid;
	int		x;
	int		y;
	int		e_x;
	int		e_y;
	int		x_n;
	int		y_n;
	void	*c_g;
	void	*c_b;
	void	*c_gr;
	void	*c_r;
	int		enemy_caller;
	int		enemy_switch_img;
	int		collec_switch_img;
	int		collec_caller;
	int		count_c;
	char	**map;
	int		count_move;
	int		divisor;
	char	arr[12];
	char	*strd;
}			t_vars;

int		ft_enemy(t_vars *args);
void	set_parameter(t_vars *arg);
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
void	set_positions(t_vars *arg, int i, int j);
int		key_hook(int keycode, t_vars *vars);
void	you_win(t_vars *arg, int x, int y);
void	check_boundary(t_vars *arg);
void	ft_error_message(char *mess);
void	check_length_map(t_vars *arg);
void	check_lines_of_map(t_vars *arg);
void	check_map(t_vars *arg);
void	check_player_count(t_vars *arg);
void	check_exit_count(t_vars *arg);
char	*ft_itoa(int n, t_vars *arg);
void	check_file_isvalid(char *file);
int		ft_exit(t_vars *arg);
void	check_elements_presence(t_vars *arg);
int		count_element(t_vars *arg, char c, char **map);
void	flood(t_vars *arg, char *map);
void	ft_free_leak(char **str);
int		ft_collect(t_vars *args);
#endif

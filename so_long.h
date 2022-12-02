/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatabay <yatabay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:48:18 by yatabay           #+#    #+#             */
/*   Updated: 2022/11/29 22:37:12 by yatabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 100

# include "./minilibx-linux/mlx.h"
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_wall {
	void			*img;
	char			*relative_path;
	int				imw;
	int				imh;
}				t_wall;

typedef struct	s_floor {
	void			*img;
	char			*relative_path;
	int				imw;
	int				imh;
}				t_floor;

typedef struct	s_exit {
	void			*img;
	char			*relative_path;
	int				imw;
	int				imh;
}				t_exit;

typedef struct	s_collectableim {
	void			*img;
	char			*relative_path;
	int				imw;
	int				imh;
}				t_collectableim;

typedef struct	s_player {
	void			*img;
	char			*relative_path;
	int				imw;
	int				imh;
}				t_player;

typedef struct	s_sprites {
	t_exit			exit;
	t_floor			floor;
	t_wall			wall;
	t_collectableim	collectableim;
	t_player		player;
}				t_sprites;

typedef struct s_collectable {
	int				amount;
	int				current;
}				t_collectable;

typedef struct	s_map {
	char			*sceleton;
	int				maxheight;
	int				mapheight;
	int				maxlen;
	int				maplen;
	int				totallen;
	int				totalhei;
	int				ppos;
	int				moves;
	t_collectable	coll;
}				t_map;

typedef struct	s_main {
	void				*mlx;
	void				*win;
	t_sprites			sp;
	t_map				map;
}				t_main;

void			first_render(t_main *main);
int				render_next_frame(t_main *main);
void			check_for_image(int counter, t_main *main, int j, int i);
void			render_image(t_main *main);

int				get_line_len(t_main *main);
int				get_map_hight(char *map);
int				get_player_pos(t_main *main);
int				get_collectable_count(t_main *main);

int				handle_keypress(int keysym, t_main *main);
int				close_program(t_main *main);
void			init_win(t_main *main, char *map);

size_t			len(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *s);
void			*cal_memset(void *s, int c, size_t n);
void			*fr_calloc(size_t nmemb, size_t size);

char			*free_dict(char *buffer, char *buf);
char			*loadmap(int fd);
int				get_newlines(char *map);
int				check_for_ascii(char *map, int symbol);
int				surround_by_walls(char *map, int lines, int passed, int valid);

void			d_move(t_main *main);
void			u_move(t_main *main);
void			r_move(t_main *main);
void			l_move(t_main *main);
void			make_move(t_main *main, int dir);

int				move_and_check(t_main *main);
int				spread(t_main *main, char *map, int ppos);
int				check_for_equal(t_main *main, int lines, int currentline, int linelentotal);
int				max_rounds(t_main *main, char *map);
int				check_for_error_exit(char *dup, t_main *main);
char			*first_replace(int ppos, char *dup, t_main *main);
char			*check_and_replace(char *dup, t_main *main);
void			init_error(t_main *main, int lines);

#endif

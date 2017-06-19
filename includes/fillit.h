/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:08:12 by biremong          #+#    #+#             */
/*   Updated: 2017/06/19 15:35:23 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "libft.h"

# define ANIM_MIN 50000000
# define ANIM_MAX 500000000
# define NOTHING 0

typedef struct	s_piece
{
	char	c;
	int		w;
	int		h;
	char	*s;
	int		id;
}				t_piece;

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_rgb
{
	int	r;
	int	g;
	int b;
}				t_rgb;

typedef struct	s_flags
{
	int		color;
	int		animate;
	int		block;
	int		equalize;
	int		zoom;
	int		shuffs;
	int		delay;
	int		strobe;
	char	**ansi_array;
	char	**strobe_array;
	int		data;
	int		seg;
}				t_flags;

typedef struct	s_game
{
	char	**board;
	int		size;
	t_piece	**pieces;
	int		piece_count;
	int		placed;
	int		steps;
}				t_game;

/*
** main.c
*/
void			ft_usage(void);
int				ft_is_flag(char *str, t_flags *flags);
int				ft_delay(int percent);
void			ft_handle_flags(char **av, int ac, t_flags *flags);

/*
** board.c
*/
int				ft_est_board(int piece_count);
char			**ft_new_board(int size);
void			ft_del_board(char **board);
void			ft_mod_board(char **board,
					t_piece piece, t_point coords, char c);

/*
** color1.c
*/
t_rgb			level_0(int mod);
t_rgb			level_1(int mod);
t_rgb			level_2(int mod);
t_rgb			level_3(int mod);
t_rgb			level_4(int mod);

/*
** color2.c
*/
char			**ft_get_ansi_array(int piece_count, t_flags *flags);
char			*ft_get_ansi(t_rgb rgb, int block_flag);
t_rgb			get_that_rgb(int i, int n);
t_rgb			level_5(int mod);
int				ft_scramble(int i, int n);

/*
** coords.c
*/
int				ft_tonext_space(char **board, t_piece piece, t_point *coords);
int				ft_isopen_space(char **board, t_piece piece, int x, int y);

/*
** getpieces.c
*/
t_piece			*ft_get_piece(int fd, char c);
void			ft_get_pieces(t_game *game, int fd);
void			ft_del_pieces(t_piece **pieces);

/*
** io.c
*/
void			ft_error(void);
void			ft_crash(void);
int				ft_open(char *f);
int				ft_read(int fd, char *buf, int len);
void			ft_close(int fd);

/*
** ispiece.c
*/
int				ft_octo_faces(char *piece, int i);
char			*ft_ispiece(char *piece);

/*
** puzzle.c
*/
void			ft_fillit(char *f, t_flags *flags);
int				ft_solve(t_game *game, t_flags *flags);
int				ft_recurse(t_game *game, t_flags *flags,
					t_point *start_coords, int n);

/*
** stdout.c
*/
void			ft_stdout(t_game *game, t_flags *flags);
void			ft_stdout_color(t_game *game, t_flags *flags);
void			ft_get_row_str(char *row, char *str, t_flags *flags);
void			ft_get_color_row_str(char *row, char *str, t_flags *flags);
int				ft_get_equalize_scalar(int zoom, int equalize);

/*
** animate.c
*/
void			ft_strobe(t_game *game, t_flags *flags);
void			ft_animate_step(t_game *game, t_flags *flags);
void			ft_80_newlines(void);
void			ft_print_data(int piece_count, int placed, int steps);
void			ft_update_data(int *steps, int *placed, int n);

/*
** topiece.c
*/
int				ft_octo_in_row(char *piece, int i);
int				ft_octo_in_col(char *piece, int i);
t_piece			*ft_new_piece(char c);
t_piece			*ft_topiece(char *s, char c);

/*
** pieceid.c
*/
int				ft_piece_id(int w, char *s);
int				ft_piece_id_w2(char *s);
int				ft_piece_id_w3(char *s);

#endif

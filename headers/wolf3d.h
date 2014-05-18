/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 17:01:38 by gleger            #+#    #+#             */
/*   Updated: 2014/05/18 13:19:11 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <unistd.h>
# include <stdlib.h>

# define WIDTH 1440
# define HEIGTH 900
# define MSPEED 0.1
# define RSPEED 0.1
# define WDISTX fabs((ptr->mapx - ptr->posx + (1 - x_angle) / 2) / ptr->raydirx)
# define WDISTY fabs((ptr->mapy - ptr->posy + (1 - y_angle) / 2) / ptr->raydiry)
# define BPP (ptr->i.bpp)
# define SIZEL (ptr->i.sizel)
# define ENDIAN (ptr->i.endian)

typedef struct			s_lst
{
	int					width;
	int					heigth;
	char				*content;
	struct s_lst		*next;
}						t_lst;

typedef struct			s_img
{
	char				*data;
	int					bpp;
	int					sizel;
	int					endian;
}						t_img;

typedef struct			s_mlx
{
	void				*win;
	void				*img;
	void				*mlx;
}						t_mlx;

typedef struct			s_wolf
{
	t_img				i;
	double				posx;
	double				posy;
	double				dirx;
	double				diry;
	double				raydirx;
	double				raydiry;
	double				d_distx;
	double				d_disty;
	double				side_dx;
	double				side_dy;
	double				planex;
	double				planey;
	double				walldist;
	int					mapx;
	int					mapy;
	int					drawstart;
	int					drawend;
	int					**maze;
	int					side;
	int					keys[4];
}						t_wolf;

int			get_next_line(int const fd, char **line);
int			ft_count_words(char *s, char c);
char		**ft_strsplit(char const *s, char c);
void		ft_strdel(char **as);
int			ft_atoi(const char *str);
char		*ft_strdup(const char *s1);
void		ft_memdel(void **ap);
char		*ft_strnew(size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_strcpy(char *s1, const char *s2);
char		*ft_strdup(const char *s1);
void		ft_strclr(char *s);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *s);
t_lst		*make_list(char **line);
t_lst		*add_to_list(t_lst **list, t_lst *new);
int			free_split(char ***tmp);
int			**treat_list(t_lst **list, int **tab);
int			**read_maze(char *file, int **tab, t_lst **list);
int			**make_tab(char **strings, int **tab, int j, int i);
void		free_list(t_lst *lst);
t_lst		*del_link(t_wolf **ptr, t_lst *lst);
void		set_mlx(t_wolf *ptr, t_mlx *e);
int			expose_hook(t_mlx *e);
void		create_image(t_wolf *ptr);
void		draw_sky(t_wolf *ptr);
void		draw_floor(t_wolf *ptr);
void		draw_bg(t_wolf *ptr);
int			set_cam(t_wolf *ptr, int max_w, int max_h);
void		draw_walls(t_wolf *ptr);
void		go_front(t_wolf *ptr);
void		go_back(t_wolf *ptr);
void		go_left(t_wolf *ptr);
void		go_right(t_wolf *ptr);
t_wolf		*init_ptr(void);
void		make_blank(t_wolf *ptr);
int			key_hook(int keycode, t_wolf *ptr);
void		set_rays(t_wolf *ptr, int x);
void		intersection_dist(t_wolf *ptr);
void		find_wall(t_wolf *ptr);
void		get_wall_height(t_wolf *ptr);
int			loop_arrows(t_wolf *ptr);
int			key_release(int keycode, t_wolf *ptr);

#endif

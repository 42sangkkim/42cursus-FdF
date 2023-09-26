# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 21:23:49 by sangkkim          #+#    #+#              #
#    Updated: 2022/06/24 11:20:44 by sangkkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:=libft.a

CC:=cc
CFLAGS:=-Wall -Wextra -Werror

AR:=ar
ARFLAGS:= rcus

RM:=rm
RMFLAGS:=-f

SRCS_1:=ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strlen.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c

SRCS_2:=ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCS_B:=ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS:=$(SRCS_1:.c=.o) $(SRCS_2:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.PHONY : all clean fclean re bonus

all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(SRCS_1:.c=.o) $(SRCS_2:.c=.o) $(SRCS_B:.c=.o)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

bonus :
	@make "OBJS:=$(OBJS) $(SRCS_B:.c=.o)"

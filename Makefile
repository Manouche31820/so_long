CC = gcc
CFLAGS = -Wall -Werror -Wextra
IFLAGS = -I /usr/local/include ./libft/libft.a \
			-L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
OBJ_DIR = obj/
SOLONG_DIR = so_long_src/

SOLONG_OBJ =  so_long.o \
			  so_long_utils.o \
			  so_long_utils2.o \
			  so_long_utils3.o \
			  so_long_utils4.o \

SOLONG_PREFIXE = $(addprefix  $(OBJ_DIR),$(SOLONG_OBJ))

NAME_SOLONG = so_long

all : mkdir_obj build_libft $(NAME_SOLONG)

bonus : all

$(NAME_SOLONG) : $(SOLONG_PREFIXE)
	$(CC) -o $@ $^ $(IFLAGS) $(CFLAGS) 

$(OBJ_DIR)%.o : $(SOLONG_DIR)%.c
	$(CC) -o $@ -c $< $(CFLAGS)

build_libft:
	make -C ./libft all

mkdir_obj :
	mkdir -p obj

.PHONY : clean

fclean : clean
	make -C ./libft fclean
	rm -f $(NAME_SRV)

clean:
	rm -f $(OBJ_DIR)*.o

re : fclean all
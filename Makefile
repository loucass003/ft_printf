# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 14:49:27 by llelievr          #+#    #+#              #
#    Updated: 2019/03/22 14:50:37 by llelievr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/objs
DEP_DIR = $(BUILD_DIR)/deps

CC = gcc
CFLAGS = -Wall -Wextra -Iincludes -flto -O3
PRECOMPILE = @mkdir -p $(dir $@)
POSTCOMPILE =

ifdef DEPS

DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.Td
CFLAGS += $(DEPFLAGS)

PRECOMPILE += ;mkdir -p $(dir $(DEP_DIR)/$*)
POSTCOMPILE += @mv -f $(DEP_DIR)/$*.Td $(DEP_DIR)/$*.d && touch $@

endif

-include src.mk

OBJS = $(patsubst srcs/%.c,$(OBJ_DIR)/%.o,$(SRCS))

all: $(NAME)


$(OBJ_DIR)/%.o: srcs/%.c Makefile
	$(PRECOMPILE)
	@mkdir -p $(dir $@)
	@$(call run_and_test, $(CC) $(CFLAGS) -c -o $@ $<)
	$(POSTCOMPILE)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

include $(wildcard $(DEP_DIR)/**/*.d)

get_files:
	$(shell find srcs -type f | sed 's/^/SRCS+=/' > src.mk)

.PHONY: all clean fclean re get_files

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[m
OK_COLOR    = \033[0;36m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

OK_STRING    = "OK"
ERROR_STRING = "ERROR"
WARN_STRING  = "WARNING"
COM_STRING   = "Compiling"
COMED_STRING = "Compiled"

define run_and_test
	printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
	$(1) 2> $@.log; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-80b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $<" "[ $(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR) ]\n"; \
	elif [ -s $@.log ]; then \
		printf "%-80b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $<" "[ $(WARN_COLOR)$(WARN_STRING)$(NO_COLOR) ]\n"; \
	else  \
		printf "%-80b%b" "$(COM_COLOR)$(COMED_STRING)$(OBJ_COLOR) $(<)" "[ $(OK_COLOR)$(OK_STRING)$(NO_COLOR) ]\n"; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef

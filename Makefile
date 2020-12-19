
ALLEGRO_DIR=/Users/markoates/Repos/allegro/build
ALLEGRO_LIBS=-lallegro_color -lallegro_font -lallegro_ttf -lallegro_dialog -lallegro_audio -lallegro_acodec -lallegro_primitives -lallegro_image -lallegro_main -lallegro


TERMINAL_COLOR_GREEN=\033[1;32m
TERMINAL_COLOR_RESET=\033[0m


SOURCES := $(shell find src -name '*.cpp')
OBJECTS := $(SOURCES:src/%.cpp=obj/%.o)


main: objects program
	@echo "=========== running executable ============="
	#./bin/DragonWrath.exe


objects: $(OBJECTS)


obj/%.o: src/%.cpp
	@mkdir -p $(@D)
	@printf "compiling object file \e[1m\e[34m$<\033[0m..."
	@g++ -c -ferror-limit=1 -std=c++17 $(UNUSED_ARGUMENTS_FLAG) -Wall -Wuninitialized -Weffc++ $< -o $@ -I./include -D_XOPEN_SOURCE_EXTENDED
	@printf "done\n"


program:
	@echo "=========== building debug target ============="
	@g++ -std=gnu++11 $(OBJECTS) ./programs/DragonWrath.cpp -o ./bin/DragonWrath.exe -I./include -I$(ALLEGRO_DIR)/include -L$(ALLEGRO_DIR)/lib $(ALLEGRO_LIBS)
	$(eval columns=$(shell tput cols))
	$(eval banner_width=103)
	$(eval hcolumns=$(shell expr $(columns) / 2 - $(banner_width) / 2))
	@printf ' %.0s' {1..$(hcolumns)}
	@echo "$(TERMINAL_COLOR_GREEN)🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫$(TERMINAL_COLOR_RESET)"
	@printf ' %.0s' {1..$(hcolumns)}
	@echo "$(TERMINAL_COLOR_GREEN)🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫   █▀▀▄  █▀▀█  █▀▀  █▀▀  🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫$(TERMINAL_COLOR_RESET)"
	@printf ' %.0s' {1..$(hcolumns)}
	@echo "$(TERMINAL_COLOR_GREEN)🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫   █▄▄▀  █▄▄█  ▀▀█  ▀▀█  🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫$(TERMINAL_COLOR_RESET)"
	@printf ' %.0s' {1..$(hcolumns)}
	@echo "$(TERMINAL_COLOR_GREEN)🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫   ▀     ▀  ▀  ▀▀▀  ▀▀▀  🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫$(TERMINAL_COLOR_RESET)"
	@printf ' %.0s' {1..$(hcolumns)}
	@echo "$(TERMINAL_COLOR_GREEN)🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫 🀫$(TERMINAL_COLOR_RESET)"



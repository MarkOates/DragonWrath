
ALLEGRO_DIR=/Users/markoates/Repos/allegro/build
ALLEGRO_LIBS=-lallegro_color -lallegro_font -lallegro_ttf -lallegro_dialog -lallegro_audio -lallegro_acodec -lallegro_primitives -lallegro_image -lallegro_main -lallegro


SOURCES := $(shell find src -name '*.cpp')
OBJECTS := $(SOURCES:src/%.cpp=obj/%.o)


main: objects program
	@echo "=========== running executable ============="
	./DragonWrath.exe


objects: $(OBJECTS)
	@echo "=========== $< ===========" 


obj/%.o: src/%.cpp
	@mkdir -p $(@D)
	@printf "compiling object file \e[1m\e[34m$<\033[0m..."
	@g++ -c -ferror-limit=1 -std=c++17 $(UNUSED_ARGUMENTS_FLAG) -Wall -Wuninitialized -Weffc++ $< -o $@ -I./include -D_XOPEN_SOURCE_EXTENDED


program:
	@echo "=========== building debug target ============="
	g++ -std=gnu++11 $(OBJECTS) ./programs/DragonWrath.cpp -o DragonWrath.exe -I./include -I$(ALLEGRO_DIR)/include -L$(ALLEGRO_DIR)/lib $(ALLEGRO_LIBS)



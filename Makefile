
ALLEGRO_DIR=/Users/markoates/Repos/allegro/build
ALLEGRO_LIBS=-lallegro_color -lallegro_font -lallegro_ttf -lallegro_dialog -lallegro_audio -lallegro_acodec -lallegro_primitives -lallegro_image -lallegro_main -lallegro


OBJECTS := $(SOURCES:src/%.cpp=obj/%.o)


build_and_run: main objects
	@echo "=========== running executable ============="
	./DragonWrath.exe


objects: $(OBJECTS)


obj/%.o: src/%.cpp


main:
	@echo "=========== building debug target ============="
	g++ -std=gnu++11 $(OBJECTS) ./programs/DragonWrath.cpp -o DragonWrath.exe -I./include -I$(ALLEGRO_DIR)/include -L$(ALLEGRO_DIR)/lib $(ALLEGRO_LIBS)



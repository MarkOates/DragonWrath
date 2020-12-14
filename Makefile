
ALLEGRO_DIR=/Users/markoates/Repos/allegro/build
ALLEGRO_LIBS=-lallegro_color -lallegro_font -lallegro_ttf -lallegro_dialog -lallegro_audio -lallegro_acodec -lallegro_primitives -lallegro_image -lallegro_main -lallegro


main: debug
	@echo "=========== running executable ============="
	./DragonWrath.exe

debug:
	@echo "=========== building debug target ============="
	g++ -std=gnu++11 ./programs/DragonWrath.cpp -o DragonWrath.exe -I./src -I$(ALLEGRO_DIR)/include -L$(ALLEGRO_DIR)/lib $(ALLEGRO_LIBS)

release:
	g++ -std=gnu++11 ./programs/DragonWrath.cpp -o DragonWrath.exe -I./src -I$(ALLEGRO_DIR) -L$(ALLEGRO_DIR) $(ALLEGRO_LIBS)



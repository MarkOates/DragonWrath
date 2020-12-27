require 'json'


class LevelBuilder
  private

  def screen_right
    1920 - 10
  end

  def screen_top
    20
  end

  def screen_bottom
    1080 - 20 
  end

  def screen_upper_middle
    1080 / 4
  end

  def screen_inner_upper_middle
    1080 / 8 * 3
  end

  def screen_middle
    1080 / 2
  end

  def screen_inner_lower_middle
    1080 / 8 * 5
  end

  def screen_lower_middle
    1080 / 4 * 3
  end

  def one_purple_dragon(start_time:, x:, y:)
    [ { "spawn_time": start_time, "type": "purple_dragon", "spawn_x": x, "spawn_y": y, "movement_strategy": "moving_left"} ]
  end

  def set_of_n_in_a_row(n: 5, start_time: 0, x:, y:, delay: 0.75, enemy_type: "yellow_dragon", movement_strategy: "move_left")
    result = []
    for i in 0...n
      result += [{ "spawn_time": start_time+delay*i, "type": enemy_type, "spawn_x": x, "spawn_y": y, "movement_strategy": movement_strategy }]
    end
    result
  end

  def set_of_5_in_a_row(start_time: 0, x:, y:, delay: 0.75, enemy_type: "yellow_dragon", movement_strategy: "move_left")
    [
      { "spawn_time": start_time+delay*0, "type": enemy_type, "spawn_x": x, "spawn_y": y, "movement_strategy": movement_strategy},
      { "spawn_time": start_time+delay*1, "type": enemy_type, "spawn_x": x, "spawn_y": y, "movement_strategy": movement_strategy},
      { "spawn_time": start_time+delay*2, "type": enemy_type, "spawn_x": x, "spawn_y": y, "movement_strategy": movement_strategy},
      { "spawn_time": start_time+delay*3, "type": enemy_type, "spawn_x": x, "spawn_y": y, "movement_strategy": movement_strategy},
      { "spawn_time": start_time+delay*4, "type": enemy_type, "spawn_x": x, "spawn_y": y, "movement_strategy": movement_strategy},
    ]
  end

  def sin_of_n_in_a_row(n: 5, start_time: 0, x:, y:, delay: 0.75, enemy_type: "yellow_dragon", movement_strategy: "move_left")
    result = []
    for i in 0...n
      result += [{ "spawn_time": start_time+delay*i, "type": enemy_type, "spawn_x": x, "spawn_y": y + Math.sin(i / n.to_f) * 0, "movement_strategy": movement_strategy }]
    end
    result
  end

  def enemies
    result = []
    start_time = 1; 

    result += set_of_n_in_a_row(n: 3, start_time: start_time, x: screen_right, y: screen_upper_middle); start_time += 3;
    result += set_of_n_in_a_row(n: 3, start_time: start_time, x: screen_right, y: screen_lower_middle); start_time += 3;
    result += set_of_n_in_a_row(n: 3, start_time: start_time, x: screen_right, y: screen_middle); start_time += 3;

    start_time = 12; # Start of A

    result += set_of_5_in_a_row(start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_upper_middle, delay: 0.4, movement_strategy: "sin_wave_move_left"); start_time += 4;
    result += set_of_5_in_a_row(start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_upper_middle, delay: 0.4, movement_strategy: "sin_wave_move_left"); start_time += 4;



    start_time = 25;

    result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_upper_middle)
    result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_lower_middle)

    result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_top);
    result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_bottom); start_time += 4;

    result += set_of_n_in_a_row(n: 2, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_inner_upper_middle)
    result += set_of_n_in_a_row(n: 2, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_inner_lower_middle)

    #result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_upper_middle);
    #result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_lower_middle);
    start_time += 4;

    result += set_of_n_in_a_row(n: 3, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_upper_middle)
    result += set_of_n_in_a_row(n: 3, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_lower_middle)

    result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_top);
    result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_bottom); start_time += 4;

    result += set_of_n_in_a_row(n: 4, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_inner_upper_middle)
    result += set_of_n_in_a_row(n: 4, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_inner_lower_middle)

    #result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_upper_middle);
    #result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_lower_middle);
    start_time += 4;


    # B-section of the music
    start_time = 50

    result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_middle, delay: 0.4, movement_strategy: "sin_wave_move_left"); start_time += 2.5;
    result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_upper_middle, delay: 0.4, movement_strategy: "sin_wave_move_left"); start_time += 2.5;
    result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_middle, delay: 0.4, movement_strategy: "sin_wave_move_left"); start_time += 2.5;

    #result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_middle, delay: 0.4, movement_strategy: "sin_wave_move_left"); start_time += 2.5;
    #result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_upper_middle, delay: 0.4, movement_strategy: "sin_wave_move_left"); start_time += 2.5;
    #result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_middle, delay: 0.4, movement_strategy: "sin_wave_move_left"); start_time += 2.5;


    # C-section of the music

    # waves of blue dragons
    start_time = 60.0

    result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_middle, delay: 0.4, movement_strategy: "sin_wave_move_left"); start_time += 2.5;
    result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_upper_middle, delay: 0.4, movement_strategy: "sin_wave_move_left"); start_time += 2.5;
    result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_middle, delay: 0.4, movement_strategy: "sin_wave_move_left"); start_time += 2.5;

    result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_middle, delay: 0.2, movement_strategy: "sin_wave_move_left"); start_time += 1.5;
    result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_upper_middle, delay: 0.2, movement_strategy: "sin_wave_move_left"); start_time += 1.5;
    result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_middle, delay: 0.2, movement_strategy: "sin_wave_move_left"); start_time += 1.5;

    result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_middle, delay: 0.2, movement_strategy: "sin_wave_move_left"); start_time += 1.5;
    result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_upper_middle, delay: 0.2, movement_strategy: "sin_wave_move_left"); start_time += 1.5;
    #result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_middle, delay: 0.2, movement_strategy: "sin_wave_move_left"); start_time += 1.5;


    start_time = 75.0

    result += set_of_n_in_a_row(n: 3, start_time: start_time, x: screen_right, y: screen_upper_middle); start_time += 3;
    result += set_of_n_in_a_row(n: 3, start_time: start_time, x: screen_right, y: screen_lower_middle); start_time += 3;
    result += set_of_n_in_a_row(n: 3, start_time: start_time, x: screen_right, y: screen_middle); start_time += 3;



    ## steady stream of red and purple dragons
    #start_time = 87.0

    result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_upper_middle, movement_strategy: "towards_player_dragon_but_maintain_trajectory")
    result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_lower_middle, movement_strategy: "towards_player_dragon_but_maintain_trajectory")

    result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_top);
    result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_bottom); start_time += 4;

    result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_inner_upper_middle, movement_strategy: "towards_player_dragon_but_maintain_trajectory")
    result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_inner_lower_middle, movement_strategy: "towards_player_dragon_but_maintain_trajectory")

    #result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_upper_middle);
    #result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_lower_middle);
    start_time += 4;

    result += set_of_n_in_a_row(n: 3, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_upper_middle)
    result += set_of_n_in_a_row(n: 3, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_lower_middle)

    result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_top);
    result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_bottom); start_time += 4;

    result += set_of_n_in_a_row(n: 3, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_inner_upper_middle)
    result += set_of_n_in_a_row(n: 3, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_inner_lower_middle)

    #result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_upper_middle);
    #result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_lower_middle);
    start_time += 4;



    # starter yellow dragons in simple rows
    start_time = 112

    result += set_of_n_in_a_row(n: 3, start_time: start_time, x: screen_right, y: screen_upper_middle); start_time += 3;
    result += set_of_n_in_a_row(n: 3, start_time: start_time, x: screen_right, y: screen_lower_middle); start_time += 3;
    result += set_of_n_in_a_row(n: 3, start_time: start_time, x: screen_right, y: screen_middle); start_time += 3;



    # two small waves of red dragons flying in at an angle
    start_time = 125

    result += set_of_n_in_a_row(n: 6, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_middle, movement_strategy: "move_up_left")
    result += set_of_n_in_a_row(n: 6, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_lower_middle, movement_strategy: "move_up_left")

    start_time += 6

    result += set_of_n_in_a_row(n: 6, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_upper_middle, movement_strategy: "move_down_left")
    result += set_of_n_in_a_row(n: 6, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_middle, movement_strategy: "move_down_left")


    # waves of blue dragons

    start_time = 137.0

    result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_middle, delay: 0.4, movement_strategy: "sin_wave_move_left"); start_time += 2.5;
    result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_upper_middle, delay: 0.4, movement_strategy: "sin_wave_move_left"); start_time += 2.5;
    result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_middle, delay: 0.4, movement_strategy: "sin_wave_move_left"); start_time += 2.5;

    result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_middle, delay: 0.2, movement_strategy: "sin_wave_move_left"); start_time += 1.5;
    result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_upper_middle, delay: 0.2, movement_strategy: "sin_wave_move_left"); start_time += 1.5;
    result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_middle, delay: 0.2, movement_strategy: "sin_wave_move_left"); start_time += 1.5;

    result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_middle, delay: 0.2, movement_strategy: "sin_wave_move_left"); start_time += 1.5;
    result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_upper_middle, delay: 0.2, movement_strategy: "sin_wave_move_left"); start_time += 1.5;
    #result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_middle, delay: 0.2, movement_strategy: "sin_wave_move_left"); start_time += 1.5;



    # last set of starter yellow dragons in simple rows
    start_time = 149

    result += set_of_n_in_a_row(n: 3, start_time: start_time, x: screen_right, y: screen_upper_middle); start_time += 3;
    result += set_of_n_in_a_row(n: 3, start_time: start_time, x: screen_right, y: screen_lower_middle); start_time += 3;
    result += set_of_n_in_a_row(n: 3, start_time: start_time, x: screen_right, y: screen_middle); start_time += 3;


    ## biggest wave
    wave_start_time = 162
    #wave_start_time = 0
    begin
      result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_inner_upper_middle)
      result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_inner_lower_middle)

      result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_top);
      result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_bottom); start_time += 3;

      result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_upper_middle)
      result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_lower_middle)

      result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_upper_middle);
      result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_lower_middle); start_time += 3;

      result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_inner_upper_middle)
      result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_inner_lower_middle)

      result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_top);
      result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_bottom); start_time += 3;

      result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_upper_middle)
      result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_lower_middle)

      result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_upper_middle);
      result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_lower_middle); start_time += 3;
    end
    begin
      start_time = wave_start_time + 12

      result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_middle, delay: 0.4, movement_strategy: "sin_wave_move_left"); start_time += 2.5;
      result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_upper_middle, delay: 0.4, movement_strategy: "sin_wave_move_left"); start_time += 2.5;
      result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_middle, delay: 0.4, movement_strategy: "sin_wave_move_left"); start_time += 2.5;

      #result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_inner_upper_middle)
      #result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_inner_lower_middle); start_time += 3

      result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_middle, delay: 0.2, movement_strategy: "sin_wave_move_left"); start_time += 1.5;
      result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_upper_middle, delay: 0.2, movement_strategy: "sin_wave_move_left"); start_time += 1.5;
      result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_middle, delay: 0.2, movement_strategy: "sin_wave_move_left"); start_time += 1.5;

      #result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_upper_middle)
      #result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_lower_middle); start_time += 3

      result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_middle, delay: 0.2, movement_strategy: "sin_wave_move_left"); start_time += 1.5;
      result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_upper_middle, delay: 0.2, movement_strategy: "sin_wave_move_left"); start_time += 1.5;
      result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_middle, delay: 0.2, movement_strategy: "sin_wave_move_left"); start_time += 1.5;

      #result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_inner_upper_middle)
      #result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_inner_lower_middle); start_time += 3
    end
    begin
      start_time = wave_start_time + 18

      result += set_of_n_in_a_row(n: 6, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_middle, movement_strategy: "move_up_left")
      result += set_of_n_in_a_row(n: 6, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_lower_middle, movement_strategy: "move_up_left")

      start_time += 6

      result += set_of_n_in_a_row(n: 6, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_upper_middle, movement_strategy: "move_down_left")
      result += set_of_n_in_a_row(n: 6, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_middle, movement_strategy: "move_down_left")

      start_time += 6

      result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_inner_upper_middle, movement_strategy: "towards_player_dragon_but_maintain_trajectory")
      result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_inner_lower_middle, movement_strategy: "towards_player_dragon_but_maintain_trajectory")
      start_time += 1

      result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_upper_middle, movement_strategy: "towards_player_dragon_but_maintain_trajectory")
      result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_lower_middle, movement_strategy: "towards_player_dragon_but_maintain_trajectory")
      start_time += 1

      result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_top, movement_strategy: "towards_player_dragon_but_maintain_trajectory")
      result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_bottom, movement_strategy: "towards_player_dragon_but_maintain_trajectory")
      start_time += 1
    end




    return result;
  end

  public

  def get_result_json
    result = {
      "type": "TimedScroll",
      "duration": 200,
      "enemies": enemies,
    }
    result
    JSON.pretty_generate(result)
  end
end


level_builder = LevelBuilder.new

IO.write('bin/data/levels/level_1.generated.json', level_builder.get_result_json)



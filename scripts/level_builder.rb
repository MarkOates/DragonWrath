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

  def screen_inner_lower_middle
    1080 / 8 * 5
  end

  def screen_middle
    1080 / 2
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
    start_time = 0;

    result += set_of_n_in_a_row(n: 3, start_time: start_time, x: screen_right, y: screen_upper_middle); start_time += 3;
    result += set_of_n_in_a_row(n: 3, start_time: start_time, x: screen_right, y: screen_lower_middle); start_time += 3;

    start_time += 5;

    result += set_of_5_in_a_row(start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_middle, delay: 0.4, movement_strategy: "sin_wave_move_left"); start_time += 4;
    result += set_of_5_in_a_row(start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_middle, delay: 0.4, movement_strategy: "sin_wave_move_left"); start_time += 4;

    start_time += 2;

    result += set_of_5_in_a_row(start_time: start_time, x: screen_right, y: screen_upper_middle)
    result += set_of_5_in_a_row(start_time: start_time, x: screen_right, y: screen_lower_middle)
    result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_top);
    result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_bottom); start_time += 4;

    start_time += 5;

    result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_upper_middle)
    result += set_of_n_in_a_row(n: 1, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_lower_middle)

    result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_top);
    result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_bottom); start_time += 4;

    result += set_of_n_in_a_row(n: 2, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_inner_upper_middle)
    result += set_of_n_in_a_row(n: 2, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_inner_lower_middle)

    result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_upper_middle);
    result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_lower_middle); start_time += 4;

    result += set_of_n_in_a_row(n: 3, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_upper_middle)
    result += set_of_n_in_a_row(n: 3, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_lower_middle)

    result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_top);
    result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_bottom); start_time += 4;

    result += set_of_n_in_a_row(n: 4, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_inner_upper_middle)
    result += set_of_n_in_a_row(n: 4, enemy_type: "red_dragon", start_time: start_time, x: screen_right, y: screen_inner_lower_middle)

    result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_upper_middle);
    result += one_purple_dragon(start_time: start_time + 2, x: screen_right, y: screen_lower_middle); start_time += 4;

    # B-section of the music

    start_time = 50

    result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_middle, delay: 0.4, movement_strategy: "sin_wave_move_left"); start_time += 4;
    result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_upper_middle, delay: 0.4, movement_strategy: "sin_wave_move_left"); start_time += 4;
    result += sin_of_n_in_a_row(n: 5, start_time: start_time, enemy_type: "blue_dragon", x: screen_right, y: screen_lower_middle, delay: 0.4, movement_strategy: "sin_wave_move_left"); start_time += 4;


    return result;
  end

  public

  def get_result_json
    result = {
      "type": "TimedScroll",
      "duration": 116,
      "enemies": enemies,
    }
    result
    JSON.pretty_generate(result)
  end
end


level_builder = LevelBuilder.new

IO.write('bin/data/levels/level_1.generated.json', level_builder.get_result_json)



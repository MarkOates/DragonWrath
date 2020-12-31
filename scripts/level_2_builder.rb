require 'json'


class Level2Builder
  def get_result_json
    result = {
      "type": "TimedScroll",
      "duration": 200,
      "enemies": enemies,
    }
    result
    JSON.pretty_generate(result)
  end

  private

  def enemies
    result = []
    start_time = 5; 

    return result;
  end
end



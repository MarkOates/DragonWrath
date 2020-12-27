require_relative 'level_1_builder'

level_1_builder = Level1Builder.new
IO.write('bin/data/levels/level_1.generated.json', level_1_builder.get_result_json)

level_2_builder = Level2Builder.new
IO.write('bin/data/levels/level_2.generated.json', level_1_builder.get_result_json)


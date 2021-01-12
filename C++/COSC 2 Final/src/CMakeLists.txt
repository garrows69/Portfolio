add_library(craps_library "roll.h" "roll.cpp"
								"die.cpp" "die.h"
								"shooter.cpp" "shooter.h"
                                "craps.cpp" "craps.h") 
								
add_executable(craps_exe "main.cpp" "roll.cpp" "die.cpp" 
                               "shooter.cpp" "craps.cpp")
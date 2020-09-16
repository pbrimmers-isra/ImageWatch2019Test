# ImageWatch2019Test
Minimal example to show ImageWatch2019 not working with objects of classes contained in DLLs in VS19. Always shows invalid, except when stepping into code inside DLL which contains image class. 

Tested with Microsoft Visual Studio Professional 2019 Version 16.7.2 and [Image Watch 2019](https://marketplace.visualstudio.com/items?itemName=VisualCPPTeam.ImageWatch2019) V1.0.2

Please note that this code was extracted from a larger legacy codebase. Just enough code do demonstrate the metioned problems with Image Watch 2019, which were observerd in other projects for similar classes.

# Repo steps
1. Build ImateWatch2019Test and place "Test.natvis" at appropriate location.
2. Run ImageWatch2019Test and step through "main()" in ImageWatch2019Test.cpp and into "step_into_this_function_to_see_image_watch_work" to see problems with ImageWatch showing test_img correctly.


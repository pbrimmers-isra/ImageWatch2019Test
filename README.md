# ImageWatch2019Test
Minimal example to show ImageWatch2019 not working with DLLs in VS19

Tested with Microsoft Visual Studio Professional 2019 Version 16.7.2 and [Image Watch 2019](https://marketplace.visualstudio.com/items?itemName=VisualCPPTeam.ImageWatch2019) V1.0.2

# Repo steps
1. Build ImateWatch2019Test and place "Test.natvis" at appropriate location.
2. Run ImageWatch2019Test and step through "main()" in ImageWatch2019Test.cpp and into "step_into_this_function_to_see_image_watch_work" to see problems with ImageWatch showing test_img correctly.

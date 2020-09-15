// ImageWatch2019Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "..\ImageWatch2019TestDLL\framework.h"

#pragma comment(lib, "ImageWatch2019TestDLL.lib")
int main()
{
    unsigned char data[] = { 1, 2, 3, 4, 5, 6 };
    test_img img;
    img.Attach(0, 0, 3, 2, 3, data);
    std::cout << "Set breakpoint here, ImageWatch will show INVALID data!\n";
    step_into_this_function_to_see_image_watch_work(img);
}

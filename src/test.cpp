#include <iostream>
#include "color.hpp"

int main(int argc, char *argv[]) {
  std::string rgb1 = "ff0000";
  std::string rgb2 = "0000ff";
  colorcpp::ColorRGBA color1(rgb1);
  colorcpp::ColorRGBA color2(rgb2);

  auto color3 = mix(color1, color2, 0.5);

  std::cerr << colorcpp::hex(color3) << std::endl;

  return 0;
}

#ifndef COLORSCPP_COLOR_HPP
#define COLORSCPP_COLOR_HPP
#include <string>
namespace colorcpp {
struct ColorRGB256;
struct ColorRGBA;
struct ColorRGBA256;
struct ColorHSL;
struct ColorRGB {
  double r, g, b;
  ColorRGB(double red = 0.0, double green = 0.0, double blue = 0.0)
      : r(red), g(green), b(blue) {}
  ColorRGB(ColorRGB &&color);
  ColorRGB(ColorRGB256 &color);
  ColorRGB(ColorRGBA &color);
  ColorRGB(ColorRGBA256 &color);
  ColorRGB(ColorHSL &color);
  ColorRGB(std::string &rgb);
  ColorHSL to_hsl();
};

struct ColorRGBA {
  double r, g, b, a;
  ColorRGBA(double red = 0.0, double green = 0.0, double blue = 0.0,
            double alpha = 0.0)
      : r(red), g(green), b(blue), a(alpha) {}
  ColorRGBA(ColorRGB &color);
  ColorRGBA(ColorRGB256 &color);
  ColorRGBA(ColorRGBA &color);
  ColorRGBA(ColorRGBA256 &color);
  ColorRGBA(ColorHSL &color);
  ColorRGBA(std::string &rgb);
};

struct ColorRGB256 {
  double r, g, b;
  ColorRGB256(double red = 0.0, double green = 0.0, double blue = 0.0)
      : r(red), g(green), b(blue) {}
  ColorRGB256(ColorRGB &color);
  ColorRGB256(ColorRGB256 &color);
  ColorRGB256(ColorRGBA &color);
  ColorRGB256(ColorRGBA256 &color);
  ColorRGB256(ColorHSL &color);
  ColorRGB256(std::string &rgb);
};

struct ColorRGBA256 {
  double r, g, b, a;
  ColorRGBA256(double red = 0.0, double green = 0.0, double blue = 0.0,
               double alpha = 0.0)
      : r(red), g(green), b(blue), a(alpha) {}
  ColorRGBA256(ColorRGB &color);
  ColorRGBA256(ColorRGB256 &color);
  ColorRGBA256(ColorRGBA &color);
  ColorRGBA256(ColorRGBA256 &color);
  ColorRGBA256(ColorHSL &color);
  ColorRGBA256(std::string &rgb);
};

struct ColorHSL {
  int h;
  double s, l;

  ColorHSL(int hue = 0, double saturation = 0.0, double luminance = 0.0)
      : h(hue), s(saturation), l(luminance) {}
  ColorHSL(ColorRGB &color);
  ColorHSL(ColorRGB256 &color);
  ColorHSL(ColorRGBA &color);
  ColorHSL(ColorRGBA256 &color);
  ColorHSL(ColorHSL &&color);
  ColorHSL(std::string &rgb);
  ColorRGB to_rgb();
};
}
#endif

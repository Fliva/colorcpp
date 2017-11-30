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
  ColorRGB(const ColorRGB &color);
  ColorRGB(const ColorRGB256 &color);
  ColorRGB(const ColorRGBA &color);
  ColorRGB(const ColorRGBA256 &color);
  ColorRGB(const ColorHSL &color);
  ColorRGB(std::string &rgb);
};

struct ColorRGBA {
  double r, g, b, a;
  ColorRGBA(double red = 0.0, double green = 0.0, double blue = 0.0,
            double alpha = 1.0)
      : r(red), g(green), b(blue), a(alpha) {}
  ColorRGBA(const ColorRGB &color);
  ColorRGBA(const ColorRGB256 &color);
  ColorRGBA(const ColorRGBA &color);
  ColorRGBA(const ColorRGBA256 &color);
  ColorRGBA(const ColorHSL &color);
  ColorRGBA(std::string &rgb);
};

struct ColorRGB256 {
  double r, g, b;
  ColorRGB256(double red = 0.0, double green = 0.0, double blue = 0.0)
      : r(red), g(green), b(blue) {}
  ColorRGB256(const ColorRGB &color);
  ColorRGB256(const ColorRGB256 &color);
  ColorRGB256(const ColorRGBA &color);
  ColorRGB256(const ColorRGBA256 &color);
  ColorRGB256(const ColorHSL &color);
  ColorRGB256(std::string &rgb);
};

struct ColorRGBA256 {
  double r, g, b, a;
  ColorRGBA256(double red = 0.0, double green = 0.0, double blue = 0.0,
               double alpha = 1.0)
      : r(red), g(green), b(blue), a(alpha) {}
  ColorRGBA256(const ColorRGB &color);
  ColorRGBA256(const ColorRGB256 &color);
  ColorRGBA256(const ColorRGBA &color);
  ColorRGBA256(const ColorRGBA256 &color);
  ColorRGBA256(const ColorHSL &color);
  ColorRGBA256(std::string &rgb);
};

struct ColorHSL {
  int h;
  double s, l;

  ColorHSL(int hue = 0, double saturation = 0.0, double luminance = 0.0)
      : h(hue), s(saturation), l(luminance) {}
  ColorHSL(const ColorRGB &color);
  ColorHSL(const ColorRGB256 &color);
  ColorHSL(const ColorRGBA &color);
  ColorHSL(const ColorRGBA256 &color);
  ColorHSL(const ColorHSL &color);
  ColorHSL(std::string &rgb);
};

ColorHSL to_hsl(ColorRGB color);
ColorRGB to_rgb(ColorHSL color);

ColorRGBA mix(const ColorRGBA color1, ColorRGBA color2, double amount);

ColorRGBA tint(const ColorRGBA color, double amount);

ColorRGBA shade(const ColorRGBA color, double amount);

ColorRGBA lighten(const ColorRGBA color, double amount);

ColorRGBA darken(const ColorRGBA color, double amount);

ColorRGBA greyscale(const ColorRGBA color);

float luminance(const ColorRGBA color);

std::string hex(const ColorRGB256 color);
}

#endif

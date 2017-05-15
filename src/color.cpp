#include "color.hpp"
#include <algorithm>
#include <ios>
#include <sstream>
namespace colorcpp {
ColorRGB::ColorRGB(const ColorRGB &color) {
  r = color.r;
  g = color.g;
  b = color.b;
}
ColorRGB::ColorRGB(const ColorRGB256 &color) {
  r = color.r / 255.0f;
  g = color.g / 255.0f;
  b = color.b / 255.0f;
}
ColorRGB::ColorRGB(const ColorRGBA &color) {
  r = color.r * color.a;
  g = color.g * color.a;
  b = color.b * color.a;
}
ColorRGB::ColorRGB(const ColorRGBA256 &color) {
  r = color.r / 255.0f * (color.a / 255.0f);
  g = color.g / 255.0f * (color.a / 255.0f);
  b = color.b / 255.0f * (color.a / 255.0f);
}
ColorRGB::ColorRGB(const ColorHSL &hsl) {
  ColorRGB color(to_rgb(hsl));
  r = color.r;
  g = color.g;
  b = color.b;
}
ColorRGB::ColorRGB(std::string &rgb) {
  ColorRGB256 color(rgb);
  r = color.r / 255.0f;
  g = color.g / 255.0f;
  b = color.b / 255.0f;
}
ColorRGBA::ColorRGBA(const ColorRGB &color) {
  r = color.r;
  g = color.g;
  b = color.b;
  a = 1.0f;
}

ColorRGBA::ColorRGBA(const ColorRGB256 &color) {
  r = color.r / 255.0f;
  g = color.g / 255.0f;
  b = color.b / 255.0f;
  a = 1.0f;
}

ColorRGBA::ColorRGBA(const ColorRGBA &color) {
  r = color.r;
  g = color.g;
  b = color.b;
  a = color.a;
}

ColorRGBA::ColorRGBA(const ColorRGBA256 &color) {
  r = color.r / 255.0f;
  g = color.g / 255.0f;
  b = color.b / 255.0f;
  a = color.a / 255.0f;
}

ColorRGBA::ColorRGBA(const ColorHSL &color) {
  ColorRGB rgb = to_rgb(color);
  r = rgb.r;
  g = rgb.g;
  b = rgb.b;
  a = 1.0f;
}

ColorRGBA::ColorRGBA(std::string &rgb) {
  ColorRGB256 color(rgb);
  r = color.r / 255.0f;
  g = color.g / 255.0f;
  b = color.b / 255.0f;
  a = 1.0f;
}

ColorRGB256::ColorRGB256(const ColorRGB &color) {
  r = color.r * 255;
  g = color.g * 255;
  b = color.b * 255;
}
ColorRGB256::ColorRGB256(const ColorRGB256 &color) {
  r = color.r;
  g = color.g;
  b = color.b;
}
ColorRGB256::ColorRGB256(const ColorRGBA &color) {
  r = color.r * 255 * color.a;
  g = color.g * 255 * color.a;
  b = color.b * 255 * color.a;
}
ColorRGB256::ColorRGB256(const ColorRGBA256 &color) {
  r = color.r * (color.a / 255.0f);
  g = color.g * (color.a / 255.0f);
  b = color.b * (color.a / 255.0f);
}
ColorRGB256::ColorRGB256(const ColorHSL &color) {
  auto rgb = to_rgb(color);
  r = rgb.r * 255.0f;
  g = rgb.g * 255.0f;
  b = rgb.b * 255.0f;
}
ColorRGB256::ColorRGB256(std::string &rgb) {
  int num = std::stoi(rgb, 0, 16);
  r = num / 0x10000;
  g = ((num / 0x100) % 0x100);
  b = (num % 0x100);
}

ColorRGBA256::ColorRGBA256(const ColorRGB &color) {
  r = color.r * 255.0f;
  g = color.g * 255.0f;
  b = color.b * 255.0f;
  a = 1.0f;
}
ColorRGBA256::ColorRGBA256(const ColorRGB256 &color) {
  r = color.r;
  g = color.g;
  b = color.b;
  a = 1.0f;
}
ColorRGBA256::ColorRGBA256(const ColorRGBA &color) {
  r = color.r * 255.0f;
  g = color.g * 255.0f;
  b = color.b * 255.0f;
  a = color.a * 255.0f;
}
ColorRGBA256::ColorRGBA256(const ColorRGBA256 &color) {
  r = color.r;
  g = color.g;
  b = color.b;
  a = color.a;
}
ColorRGBA256::ColorRGBA256(const ColorHSL &color) {
  auto rgb = to_rgb(color);
  r = rgb.r * 255.0f;
  g = rgb.g * 255.0f;
  b = rgb.b * 255.0f;
  a = 1.0f;
}
ColorRGBA256::ColorRGBA256(std::string &rgb) {
  ColorRGB256 color(rgb);
  r = color.r;
  g = color.g;
  b = color.b;
}

ColorHSL::ColorHSL(const ColorRGB &color) {
  auto hsl = to_hsl(color);
  h = hsl.h;
  s = hsl.s;
  l = hsl.l;
}

ColorHSL::ColorHSL(const ColorRGB256 &color) {
  auto hsl = to_hsl(color);
  h = hsl.h;
  s = hsl.s;
  l = hsl.l;
}
ColorHSL::ColorHSL(const ColorRGBA &color) {
  auto hsl = to_hsl(color);
  h = hsl.h;
  s = hsl.s;
  l = hsl.l;
}
ColorHSL::ColorHSL(const ColorRGBA256 &color) {
  auto hsl = to_hsl(color);
  h = hsl.h;
  s = hsl.s;
  l = hsl.l;
}
ColorHSL::ColorHSL(const ColorHSL &color)
    : h(color.h), s(color.s), l(color.l) {}
ColorHSL::ColorHSL(std::string &rgb) {
  ColorRGB newColor(rgb);
  auto hsl = to_hsl(newColor);
  h = hsl.h;
  s = hsl.s;
  l = hsl.l;
}
ColorHSL to_hsl(ColorRGB color) {
  double r = color.r;
  double g = color.g;
  double b = color.b;
  double themin, themax, delta;
  ColorHSL c2;

  themin = std::min(r, std::min(g, b));
  themax = std::max(r, std::max(g, b));
  delta = themax - themin;
  c2.l = (themin + themax) / 2;
  c2.s = 0;
  if (c2.l > 0 && c2.l < 1)
    c2.s = delta / (c2.l < 0.5 ? (2 * c2.l) : (2 - 2 * c2.l));
  c2.h = 0;
  if (delta > 0) {
    if (themax == r && themax != g) c2.h += (g - b) / delta;
    if (themax == g && themax != b) c2.h += (2 + (b - r) / delta);
    if (themax == b && themax != r) c2.h += (4 + (r - g) / delta);
    c2.h *= 60;
  }
  return (c2);
}

ColorRGB to_rgb(ColorHSL color) {
  ColorRGB c2, sat, ctmp;

  double h = color.h;
  double s = color.s;
  double l = color.l;

  while (h < 0) h += 360;
  while (h > 360) h -= 360;

  if (h < 120) {
    sat.r = (120 - h) / 60.0;
    sat.g = h / 60.0;
    sat.b = 0;
  } else if (h < 240) {
    sat.r = 0;
    sat.g = (240 - h) / 60.0;
    sat.b = (h - 120) / 60.0;
  } else {
    sat.r = (h - 240) / 60.0;
    sat.g = 0;
    sat.b = (360 - h) / 60.0;
  }
  sat.r = std::min(sat.r, 1.0);
  sat.g = std::min(sat.g, 1.0);
  sat.b = std::min(sat.b, 1.0);

  ctmp.r = 2 * s * sat.r + (1 - s);
  ctmp.g = 2 * s * sat.g + (1 - s);
  ctmp.b = 2 * s * sat.b + (1 - s);

  if (l < 0.5) {
    c2.r = l * ctmp.r;
    c2.g = l * ctmp.g;
    c2.b = l * ctmp.b;
  } else {
    c2.r = (1 - l) * ctmp.r + 2 * l - 1;
    c2.g = (1 - l) * ctmp.g + 2 * l - 1;
    c2.b = (1 - l) * ctmp.b + 2 * l - 1;
  }

  return (c2);
}

ColorRGBA mix(const ColorRGBA color1, ColorRGBA color2, double amount) {
  ColorRGBA result;

  double p = amount;
  double w = p * 2 - 1;
  double a = color1.a - color2.a;

  double w1 = ((w * color1.a == -1 ? w : (w + a) / (1 + w * a)) + 1) / 2.0;
  double w2 = 1.0 - w1;

  result.r = color1.r * w1 + color2.r * w2;
  result.g = color1.g * w1 + color2.g * w2;
  result.b = color1.b * w1 + color2.b * w2;

  return result;
}
ColorRGBA tint(const ColorRGBA color, double amount) {
  ColorRGBA white(1.0, 1.0, 1.0, 1.0);
  ColorRGBA result = mix(color, white, amount);
  return result;
}
ColorRGBA shade(const ColorRGBA color, double amount) {
  ColorRGBA black(0.0, 0.0, 0.0, 1.0);
  ColorRGBA result = mix(color, black, amount);
  return result;
}

ColorRGBA lighten(const ColorRGBA color, double amount) {
  ColorHSL tmp = to_hsl(color);
  tmp.l = tmp.l + tmp.l * amount;
  return to_rgb(tmp);
}

ColorRGBA darken(const ColorRGBA color, double amount) {
  ColorHSL tmp = to_hsl(color);
  tmp.l = tmp.l - tmp.l * amount;
  return to_rgb(tmp);
}

ColorRGBA greyscale(const ColorRGBA color) {
  ColorHSL tmp = to_hsl(color);
  tmp.s = 0;
  return to_rgb(tmp);
}

std::string hex(int element) {
  std::stringstream sstream;
  sstream << std::hex << element;

  auto val = sstream.str();
  if (val.size() == 0) {
    return "00";
  }
  if (val.size() == 1) {
    return "0" + val;
  }
  return val;
}

std::string hex(const ColorRGB256 color) {
  return hex(color.r) + hex(color.g) + hex(color.b);
}
}

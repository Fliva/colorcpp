#include "color.hpp"
#include <algorithm>
namespace colorcpp {
ColorRGB::ColorRGB(ColorRGB &&color) {
  r = color.r;
  g = color.g;
  b = color.b;
}
ColorRGB::ColorRGB(ColorRGB256 &color) {
  r = color.r / 255.0f;
  g = color.g / 255.0f;
  b = color.b / 255.0f;
}
ColorRGB::ColorRGB(ColorRGBA &color) {
  r = color.r * color.a;
  g = color.g * color.a;
  b = color.b * color.a;
}
ColorRGB::ColorRGB(ColorRGBA256 &color) {
  r = color.r / 255.0f * (color.a / 255.0f);
  g = color.g / 255.0f * (color.a / 255.0f);
  b = color.b / 255.0f * (color.a / 255.0f);
}
ColorRGB::ColorRGB(ColorHSL &hsl) {
  ColorRGB color(hsl.to_rgb());
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

ColorHSL ColorRGB::to_hsl() {
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

ColorRGBA::ColorRGBA(ColorRGB256 &color) {
  r = color.r / 255.0f;
  g = color.g / 255.0f;
  b = color.b / 255.0f;
  a = 1.0f;
}

ColorRGBA::ColorRGBA(ColorRGBA &color) {
  r = color.r;
  g = color.g;
  b = color.b;
  a = color.a;
}

ColorRGBA::ColorRGBA(ColorRGBA256 &color) {
  r = color.r / 255.0f;
  g = color.g / 255.0f;
  b = color.b / 255.0f;
  a = color.a / 255.0f;
}

ColorRGBA::ColorRGBA(ColorHSL &color) {
  auto rgb = color.to_rgb();
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

ColorRGB256::ColorRGB256(ColorRGB &color) {
  r = color.r * 255;
  g = color.g * 255;
  b = color.b * 255;
}
ColorRGB256::ColorRGB256(ColorRGB256 &color) {
  r = color.r;
  g = color.g;
  b = color.b;
}
ColorRGB256::ColorRGB256(ColorRGBA &color) {
  r = color.r * 255 * color.a;
  g = color.g * 255 * color.a;
  b = color.b * 255 * color.a;
}
ColorRGB256::ColorRGB256(ColorRGBA256 &color) {
  r = color.r * (color.a / 255.0f);
  g = color.g * (color.a / 255.0f);
  b = color.b * (color.a / 255.0f);
}
ColorRGB256::ColorRGB256(ColorHSL &color) {
  auto rgb = color.to_rgb();
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

ColorRGBA256::ColorRGBA256(ColorRGB &color) {
  r = color.r * 255.0f;
  g = color.g * 255.0f;
  b = color.b * 255.0f;
  a = 1.0f;
}
ColorRGBA256::ColorRGBA256(ColorRGB256 &color) {
  r = color.r;
  g = color.g;
  b = color.b;
  a = 1.0f;
}
ColorRGBA256::ColorRGBA256(ColorRGBA &color) {
  r = color.r * 255.0f;
  g = color.g * 255.0f;
  b = color.b * 255.0f;
  a = color.a * 255.0f;
}
ColorRGBA256::ColorRGBA256(ColorRGBA256 &color) {
  r = color.r;
  g = color.g;
  b = color.b;
  a = color.a;
}
ColorRGBA256::ColorRGBA256(ColorHSL &color) {
  auto rgb = color.to_rgb();
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

ColorHSL::ColorHSL(ColorRGB &color) {
  auto hsl = color.to_hsl();
  h = hsl.h;
  s = hsl.s;
  l = hsl.l;
}

ColorHSL::ColorHSL(ColorRGB256 &color) {
  ColorRGB newColor(color);
  auto hsl = newColor.to_hsl();
  h = hsl.h;
  s = hsl.s;
  l = hsl.l;
}
ColorHSL::ColorHSL(ColorRGBA &color) {
  ColorRGB newColor(color);
  auto hsl = newColor.to_hsl();
  h = hsl.h;
  s = hsl.s;
  l = hsl.l;
}
ColorHSL::ColorHSL(ColorRGBA256 &color) {
  ColorRGB newColor(color);
  auto hsl = newColor.to_hsl();
  h = hsl.h;
  s = hsl.s;
  l = hsl.l;
}
ColorHSL::ColorHSL(ColorHSL &&color) : h(color.h), s(color.s), l(color.l) {}
ColorHSL::ColorHSL(std::string &rgb) {
  ColorRGB newColor(rgb);
  auto hsl = newColor.to_hsl();
  h = hsl.h;
  s = hsl.s;
  l = hsl.l;
}
ColorRGB ColorHSL::to_rgb() {
  ColorRGB c2, sat, ctmp;

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
}

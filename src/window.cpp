#include "window.hpp"

Window::Window(int height, int width, int y, int x) :
  m_height(height), m_width(width), m_y(y), m_x(x)
{
  w = newwin(m_height, m_width, m_y, m_x);
}

Window::~Window() {
  wclear(this->w);
  delwin(w);
}

BorderedWindow::BorderedWindow(int height, int width, int y, int x) :
  Window(height, width, y, x)
{
  box(this->w, 0, 0);
}

BorderedWindow::~BorderedWindow() {
  wborder(this->w, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
  this->refresh();
}

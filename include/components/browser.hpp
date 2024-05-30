#pragma once

#include "common.hpp"
#include "components/pane.hpp"
#include "event_handler.hpp"
#include "fs.hpp"

namespace bff {

class Browser : protected Pane, public IEventListener {
public:
  Browser(const path &p, int width, int y, int x, BorderChars border);
  Browser(const path &p, int width, int y, int x);

  void accept(Event e) override;

  void populate();
  void redraw();
  void move_down();
  void move_up();

  void select(path path);
  directory_entry get_selected();

protected:
  static bool compare_entries(const directory_entry a,
                       const directory_entry b);

  const path &m_path;
  int m_sel;
  fs::dir_contents m_directory;
};

} // namespace bff

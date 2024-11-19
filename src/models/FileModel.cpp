#include "models/FileModel.hpp"
#include "gdkmm/pixbuf.h"
#include "utils/utils.hpp"
#include <iostream>
FileModel::FileModel(Glib::RefPtr<Gio::File> file) {
  auto fileInfo = file->query_info();
  name = fileInfo->get_name();
  filePath = file->get_path();
  fileSize = fileInfo->get_size();

  Glib::RefPtr<Gdk::Pixbuf> pixbuf = Gdk::Pixbuf::create_from_file(filePath);

  // Get the width and height of the image
  width = pixbuf->get_width();
  height = pixbuf->get_height();
}

std::string FileModel::resize(int height, int width) {
  std::string destinationPath = "hello";
  std::cout << "🟢 [FileModel.cpp:11]: " << "RESIZING..." << std::endl;
  return destinationPath;
}
std::string FileModel::blackAndWhite() {
  std::string destinationPath = "";
  Utils::blackAndWhite(destinationPath);
  return destinationPath;
}
std::string FileModel::invert() {
  std::string destinationPath = "";
  return destinationPath;
}
FileModel::~FileModel() {}
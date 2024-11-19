#include "models/FileModel.hpp"
FileModel::FileModel(Glib::RefPtr<Gio::File> file) {
  auto fileInfo = file->query_info();
  name = fileInfo->get_name();
  filePath = file->get_path();
  fileSize = fileInfo->get_size();
}

std::string FileModel::resize(int height, int width) {
  std::string destinationPath = "";
  return destinationPath;
}
std::string FileModel::compress(int percentage) {
  std::string destinationPath = "";
  return destinationPath;
}
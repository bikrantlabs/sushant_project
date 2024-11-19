
#pragma once
#include "giomm/file.h"
#include "glibmm/refptr.h"
#include <string>

class FileModel {
public:
  // Constructor
  FileModel(Glib::RefPtr<Gio::File> file);
  ~FileModel();

  std::string filePath;
  long long fileSize;

  std::string name;

  std::string destinationPath;

  std::string resize(int height, int width);

  std::string compress(int percentage);
};
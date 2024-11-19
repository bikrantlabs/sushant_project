#include "EditorView.hpp"
#include "FileModel.hpp"
#include "gtkmm/box.h"
#include "gtkmm/grid.h"
#include "gtkmm/label.h"

#include <cstdio>
#include <iostream>
#include <string>

EditorView::EditorView(FileModel &fileModel)
    : fileModel(fileModel), resizeHeightInput(), resizeWidthInput(),
      resizeButton("Resize"), blackAndWhiteButton("Black & White"),
      invertButton("Invert") {
  set_name("editorView");

  Gtk::Label editorLabel("Editor");
  editorLabel.set_name("editorLabel");
  controlsGrid.attach(editorLabel, 0, 0, 1, 1);

  attach(controlsGrid, 0, 1, 1, 1);

  Gtk::Grid resizeGrid;

  Gtk::Label resizeLabel("Resize");
  Gtk::Label heightLabel("Height");
  Gtk::Label widthLabel("Width");
  Gtk::Grid heightGrid;
  Gtk::Grid widthGrid;

  resizeLabel.set_halign(Gtk::Align::START);
  resizeLabel.set_name("resizeLabel");

  heightGrid.attach(heightLabel, 0, 0, 1, 1);
  heightGrid.attach(resizeHeightInput, 0, 1, 1, 1);
  heightGrid.set_row_homogeneous(false);
  heightLabel.set_halign(Gtk::Align::START);
  resizeHeightInput.set_halign(Gtk::Align::START);
  resizeHeightInput.setText(std::to_string(fileModel.height / 2));

  heightGrid.set_row_spacing(12);

  widthGrid.attach(widthLabel, 0, 0, 1, 1);
  widthGrid.attach(resizeWidthInput, 0, 1, 1, 1);
  widthGrid.set_row_spacing(12);
  widthGrid.set_row_homogeneous(false);
  widthLabel.set_halign(Gtk::Align::START);
  resizeWidthInput.set_halign(Gtk::Align::START);
  resizeWidthInput.setText(std::to_string(fileModel.width / 2));

  resizeGrid.set_row_spacing(16);

  resizeGrid.attach(resizeLabel, 0, 0, 1, 1);
  resizeGrid.attach(heightGrid, 0, 1, 1, 1);
  resizeGrid.attach(widthGrid, 0, 2, 1, 1);
  resizeGrid.attach(resizeButton, 0, 3, 1, 1);

  auto stringHeight = resizeHeightInput.getText();
  auto stringWidth = resizeWidthInput.getText();

  int height;
  int width;

  if (!stringWidth.empty() && !stringHeight.empty()) {
    height = std::stoi(stringHeight);
    width = std::stoi(stringWidth);
    resizeButton.signal_clicked().connect([this, &fileModel, height, width]() {
      // Call the resize function when button is clicked
      std::string result =
          fileModel.resize(height, width); // Example dimensions
      std::cout << "Resized image saved at: " << result << std::endl;
    });
  }

  Gtk::Grid actionBtnGrid;

  actionBtnGrid.attach(blackAndWhiteButton, 0, 0, 1, 1);
  actionBtnGrid.attach(invertButton, 1, 0, 1, 1);
  actionBtnGrid.set_column_spacing(20);

  // Connect the "Black & White" button to the blackAndWhite function
  blackAndWhiteButton.signal_clicked().connect([this, &fileModel]() {
    std::string result = fileModel.blackAndWhite();
    std::cout << "Black & White transformation saved at: " << result
              << std::endl;
  });
  invertButton.signal_clicked().connect([this, &fileModel]() {
    std::string result = fileModel.invert();
    std::cout << "Inverted image saved at: " << result << std::endl;
  });

  Gtk::Box separator;
  separator.set_name("separator");
  separator.set_size_request(-1, 3);
  attach(resizeGrid, 0, 2, 1, 1);
  attach(separator, 0, 3, 1, 1);
  attach(actionBtnGrid, 0, 4, 1, 1);
  set_row_spacing(10);
}
EditorView::~EditorView(){};